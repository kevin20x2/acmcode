/*
 *File:  cf100187.cpp
 *Date : 2014-10-02 00:08:02
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)
using namespace std;
struct seg{
    int x,y;
};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char g1[505][505];
char g2[505][505];
int vis[505][505];
seg q[505*505];
int l,r;
int n,m;

int bfs(seg x)
{
    clr(q);
    l=r=0;
    q[r++] = x;
    vis[x.x][x.y] = 1;
    int size = 1;
    int tsize =1;
    int ans  =0 ;
    while(l!=r)
    {
        size = tsize ;
        tsize = 0;
        loop(i,1,size)
        {
           seg t = q[l++]; 
          // printf("%d %d\n",t.x,t.y);
           if(t.x==n&&t.y==m)
               return ans ;
           loop(i,0,3) 
           {
               int ansx = t.x+dx[i];
               int ansy = t.y+dy[i];
               if(ansx>=1&&ansx<=n&&ansy>=1&&ansy<=m&&vis[ansx][ansy]==0&&g1[ansx][ansy]!='#'&&g2[ansx][ansy]!='#')
               {
                   vis[ansx][ansy] =1;
                   seg temp;
                   temp.x = ansx;temp.y =ansy;
                    q[r++]=(temp);
                    tsize++;
               }
           }
        }
        ans ++;
        //printf("\n");
        
    }
    return -1;
}
int bfs_2(seg x,char g[][505])
{
    clr(q);
    l=r=0;
    q[r++] =x;
    vis[x.x][x.y] = 1;
    int size = 1;
    int tsize =1;
    int ans  =0 ;
    while(l!=r)
    {
        size = tsize ;
        tsize = 0;
        loop(i,1,size)
        {
           seg t = q[l++]; 
         //  printf("%d %d\n",t.x,t.y);
           if(t.x==n&&t.y==m)
               return ans ;
           loop(i,0,3) 
           {
               int ansx = t.x+dx[i];
               int ansy = t.y+dy[i];
               if(ansx>=1&&ansx<=n&&ansy>=1&&ansy<=m&&vis[ansx][ansy]==0&&g[ansx][ansy]!='#')
               {
                   vis[ansx][ansy] =1;
                   seg temp;
                   temp.x = ansx;temp.y =ansy;
                    q[r++]=(temp);
                    tsize++;
               }
           }
        }
        ans ++;
        //printf("\n");
        
    }
    return -1;
}


int main()
{
    scanf("%d%d",&n,&m);
    loop(i,1,n)
    {
        scanf("%s",&g1[i][1]);
    }
    loop(i,1,n)
    {
        scanf("%s",&g2[i][1]);
    }
    seg root;
    root.x = 1,root.y=1;
    clr(vis);
    int a = bfs(root);
    //printf("%d ",a);
    if(a==-1)
        puts("NO");
    else {
        clr(vis);
        int b = bfs_2(root,g1);
        //printf("%d ",b);
        clr(vis);
        int c = bfs_2(root,g2);
       // printf("%d ",c);
        if(a==b&&b==c)
            puts("YES");
        else puts("NO");
    }

    return 0;
}

