/*
 *File:  2012hangzhouh.cpp
 *Date : 2014-10-26 14:34:52
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
#define maxn 1010
struct seg{
    int v,next;
    seg (int v =-1,int next =-1):v(v),next(next){}
}edge[20010];
int n ,m;
int head[maxn];
int tot;
int q[maxn<<2],l,r;
int g[maxn][maxn];
int inque[maxn];
map <string,int >m2;
void addedge(int u ,int v)
{
    edge[++tot].v = v;
    edge[tot].next = head[u];
    head[u] = tot;
}
void bfs(int x)
{
    l =r =0;
    for(int i =1;i<=n;i++)
        g[x][i] = inf;
    memset(inque,0,sizeof(inque));
    g[x][x] = 0;
    inque[x] =1;
    q[r++]  =x;
    while(l!=r)
    {
        
        int t  = q[l++];
        inque[t] = 0;
        for(int j=head[t];j!=-1;j=edge[j].next) 
        {
            int v = edge[j].v;
            if(g[x][v]>g[x][t]+1)
            {
                g[x][v] = g[x][t]+1;
                if(!inque[v])
                {
                    inque[v] =1;
                    q[r++] =v;
                }
            }
        }
    }
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    m2.clear();
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        string t;
        string t2;
        init();
        for(int i =1;i<=n;i++)
        {
            cin>>t;
            m2[t] = i;
        }
        scanf("%d",&m);
        for(int i =1;i<=m;i++)
        {
            cin >> t >>t2;
            addedge(m2[t],m2[t2]);addedge(m2[t2],m2[t]);
        }
        int ans  = -1;
        for(int i =1;i<=n;i++) bfs(i);
        for(int i =1;i<=n;i++)
        {
            for(int j =i+1;j<=n;j++)
                ans = max(ans,g[i][j]);
        }
        if(ans == inf) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}

