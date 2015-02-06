/*
 *File:  112hdu1005.cpp.cpp
 *Date : 2014-11-02 14:45:47
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
    int type;
    seg(int a=0,int b=0,int c=0):x(a),y(b),type(c){}
};
int dx[4] = {0,1,0,-1};
int dy[4] ={1,0,-1,0};
int vis[55][55][1<<11];
int w[255][255];
int g[55][55];
int n,m,p;
int k,s;
seg q[55*55*(1<<11)];
int l,r;
void bfs(seg x)
{
    l= r = 0;
    memset(vis,0x3f,sizeof(vis));
    if(g[x.x][x.y]!=0)
        x.type = x.type|g[x.x][x.y];
    q[r++] = x;
    vis[x.x][x.y][x.type] =0;
    while(l!=r)
    {
        seg t = q[l++];
       // printf("%d %d %d %d\n",t.x,t.y,t.type,vis[t.x][t.y][t.type]);
        for(int i =0;i<4;i++)
        {
            int ansx = t.x+dx[i];
            int ansy = t.y +dy[i];
            if(ansx>=1&&ansx<=n&&ansy<=m&&ansy>=1)
            {
                int door = w[(t.x-1)*n+t.y][(ansx-1)*n+ansy];
                if(door!=0)
                if(door==-1||(t.type&(1<<(door-1)))!=0)
                {
                    if(vis[ansx][ansy][t.type]>vis[t.x][t.y][t.type]+1)
                    {
                        vis[ansx][ansy][t.type]= vis[t.x][t.y][t.type]+1;
                        if(g[ansx][ansy]!=0)
                        {
                            vis[ansx][ansy][t.type|g[ansx][ansy]] = vis[ansx][ansy][t.type];
                            t.type = t.type|g[ansx][ansy];
                        }
                        q[r++] = seg(ansx,ansy,t.type);
                    }
                }
            }
        }
        
    }
    
}

int main()
{
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        memset(w,-1,sizeof(w));
        clr(g);
        scanf("%d",&k);
        int x,y,a,b,t;
        for(int i =1;i<=k;i++)
        {
            scanf("%d%d%d%d%d",&x,&y,&a,&b,&t);
            if(t!=0)
            {
                w[(x-1)*n+y][(a-1)*n+b] = t;
                w[(a-1)*n+b][(x-1)*n+y] =t;
            }
        }
        scanf("%d",&s);
        for(int i =1;i<=s;i++)
        {
            scanf("%d%d%d",&x,&y,&t);
            g[x][y] =g[x][y]|(1<<(t-1));
        }
        bfs(seg(1,1,0));
        int ans = inf;
        for(int i =0;i<(1<<p);i++)
            ans= min(ans,vis[n][m][i]);
        if(ans ==inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}

