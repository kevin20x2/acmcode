/*
 *File:  2006shanghaic.cpp
 *Date : 2014-12-27 16:03:46
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define maxn 100010
using namespace std;
int next[maxn<<1];
int var[maxn<<1];
int w[maxn];
int head[maxn];
LL sum[maxn];
int fa[maxn];
bool vis[maxn];
int tot;
int n;
int m;
void addedge(int u,int v)
{
    var[++tot] = v;
    next[tot] = head[u];
    head[u] = tot;
}
LL dfs(int x)
{
    vis[x] = 1;
    if(sum[x]!=0 ) return sum[x];
    for(int i = head[x];~i;i=next[i])
    {
        int v = var[i];
        if(!vis[v])
        {
            fa[v]= x;
            sum[x]+=dfs(v);
        }
    }
    sum[x]+=1LL*w[x];
    return sum[x];
    
}

int main()
{
    int x,y;
    int cas=0;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(head,-1,sizeof head);
        memset(fa,0,sizeof fa);
        memset(sum,0,sizeof sum);
        memset(w,0,sizeof w);
        memset(vis,0,sizeof vis);
        tot = 0;
        LL total = 0;
        for(int i =1;i<=n;i++)
        {
            scanf("%d",&w[i]);
            total+=1LL*w[i];
        }
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        fa[1] = -1;
        dfs(1);
        LL ans = 1e18;
        for(int i =1;i<=n;i++)
        {
            for(int j =head[i];~j;j=next[j])
            {
                int v = var[j];
                if(fa[i] == v)
                {
                    ans = min(ans,abs(total-sum[i]-sum[i]));
                }else if(fa[v]==i) {
                    ans = min(ans,abs(total-sum[v]-sum[v]));
                }else printf("error");
                    
            }
        }
        printf("Case %d: ",++cas);
        cout<<ans<<endl;
        
    }
    return 0;
}

