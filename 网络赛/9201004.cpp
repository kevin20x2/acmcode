/*
 *File:  9201004.cpp
 *Date : 2014-09-20 15:19:00
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
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
struct seg{
    int x,y;
    int v;
    int s;
};

using namespace std;
char g[102][102];
bool vis[102][102][1<<10][1<<5];
int id[102][102];
int n,m;
int snum;
queue <seg> q;
int can_get(int v,int x)
{
   loop(i,1,x-1) 
   {
       if((v&(1<<(i-1)))==0)
           return 0;
   }
   return 1;
}
int over(int v)
{
    if(m==0)
        return 1;
    else {
        loop(i,1,m)
            if((v&(1<<(i-1)))==0)
                return 0;
    }
    return 1;
}
int beaten(int s,int no)
{
    if((s&(1<<(no-1)))!=0)
        return 1;
    return 0;
    
}
int bfs(seg x)
{
    while(!q.empty())
        q.pop();
    q.push(x);
    vis[x.x][x.y][x.v][x.s]=true;
    int ans =0;
    int size = 1;
    int tsize =1;
    while(!q.empty())
    {
        size = tsize;
        tsize =0;
        //printf("\n");
        loop(i,1,size)
        {
           seg t = q.front();
         //  printf("%d %d %x\n",t.x,t.y,t.v);
           q.pop();
           if(g[t.x][t.y]=='S'&&beaten(t.s,id[t.x][t.y])==0)
           {
               t.s|= (1<<(id[t.x][t.y]-1));
               q.push(t);
               tsize ++;
               continue;
           } else if(g[t.x][t.y]>='1'&&g[t.x][t.y]<='9')
           {
               int temp = (int)(g[t.x][t.y]-'0');
               if(can_get(t.v,temp))
                   t.v |= 1<<(temp-1);
           }
           else if(g[t.x][t.y]=='T')
           {
            if(over(t.v))
                return ans;
           }

           loop(j,0,3) 
           {
               int ansx = t.x+dx[j];
               int ansy = t.y+dy[j];
               seg in ;
               in.x = ansx;
               in.y = ansy;
               in.v =t.v;
               in.s =t.s;
               if(ansx<=n&&ansx>=1&&ansy<=n&&ansy>=1&&g[ansx][ansy]!='#'&&vis[ansx][ansy][t.v][t.s]==false)
               {
                   vis[ansx][ansy][t.v][t.s]=true;
                   q.push(in);
                   tsize++;
               }
           }
        }
        ans++;
    }
    return -1;
    
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n)
    {
        seg t;
        snum=0;
        clr(vis);
        clr(id);
        loop(i,1,n)
        {
            scanf("%s",&g[i][1]);
            loop(j,1,n)
            {
                if(g[i][j]=='K')
                {
                    t.x=i,t.y=j,t.v=0;
                    t.s=0;
                }
                else if(g[i][j]=='S')
                {
                    snum++;
                    id[i][j] = snum;
                }
            }
        }
        int ans = bfs(t);
        if(ans==-1)
            puts("impossible");
        else printf("%d\n",ans);
    }
    return 0;
}

