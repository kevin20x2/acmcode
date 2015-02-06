/*
 *File:  2011chengdue.cpp
 *Date : 2014-11-08 16:38:51
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
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
#define maxn 20010
struct LogVar{
    int index;
    bool pre;
    LogVar(int _index = 0,bool _pre =false ) : index(_index),pre(_pre){}
};
struct BinExp{
    LogVar p,q;
    BinExp(LogVar _p = LogVar(),LogVar _q = LogVar()): p(_p),q(_q){}
};
struct seg{
    int next,to;
}h[maxn<<2];
int head[maxn];
int T;
int n,m;
int tot;
BinExp a[maxn];
int edge_tot,id_cnt,cnt,top;
int low[maxn],dfn[maxn],belong[maxn],s[maxn],vis[maxn];
int g[maxn],g1[maxn];
void add_edge(int u,int v)
{
    h[++edge_tot].to= v; 
    h[edge_tot].next = head[u];
    head[u] = edge_tot;
}
void dfs(int x)
{
    low[x] =dfn[x] =++id_cnt;
    s[++top] =x;
    vis[x] =true;
    for(int i = head[x],k;~i;i = h[i].next)
        if(!vis[k = h[i].to]){
            dfs(k);
            low[x] = min(low[x],low[k]);
        }
    else low[x] =min(low[x],dfn[k]);
    if(dfn[x] ==low[x])
    {
        s[top+1] = -1;
        for(++cnt;s[top+1]!=x;--top)
        {
            //c[cnt].push_back(s[top]);
            belong[s[top]] = cnt;
        }
    }
}
inline bool two_sat()
{
    edge_tot = 0, id_cnt = 0,cnt =0,top = 0;
    clr(belong);
    clr(s);
    clr(low);
    clr(dfn);
    clr(vis);
    memset(head,-1,sizeof(head));
    for(int i =0;i<tot;++i)
    {
        add_edge(a[i].p.index+a[i].p.pre*n,a[i].q.index+!a[i].q.pre*n);
        add_edge(a[i].q.index+a[i].q.pre*n,a[i].p.index+!a[i].p.pre*n);
    }
    for(int i= 0;i<2*n;++i)
        if(!vis[i])
            dfs(i);
    for(int i =0;i<n;++i)
        if(belong[i] == belong[i+n])
        {
            return false ;
        }
    return true;
}


int main()
{
    scanf("%d",&T);
    for(int cas =1;cas<=T;cas++)
    {
        printf("Case #%d: ",cas);
        scanf("%d%d",&n,&m);
        for(int i =0;i<n;i++)
        {
            scanf("%d",&g[i]);
            if(g[i]==1) g1[i] =2;
            else if(g[i]==2) g1[i]=3;
            else g1[i] = 1;
            if(g[i]>g1[i]) swap(g[i],g1[i]);
        }
        int x,y,z;
        tot =0;
        clr(a);
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;y --;
            if((z==0&&g[x]!=g[y])||(z==1&&g[x]==g[y]))
                a[tot++] = BinExp(LogVar(x,true),LogVar(y,true));
            if((z==0&&g[x]!=g1[y])||(z==1&&g[x]==g1[y]))
                a[tot++] =BinExp(LogVar(x,true),LogVar(y,false));
            if((z==0&&g1[x]!=g[y])||(z==1&&g1[x]==g[y]))
                a[tot++] = BinExp(LogVar(x,false),LogVar(y,true ));
            if((z==0&&g1[x]!=g1[y])||(z==1&&g1[x]==g1[y]))
                a[tot++] =BinExp(LogVar(x,false),LogVar(y,false ));
        }
        if(two_sat())
            puts("yes");
        else puts("no");
        
    }
    return 0;
}

