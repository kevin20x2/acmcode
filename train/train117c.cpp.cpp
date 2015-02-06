/*
 *File:  train117c.cpp.cpp
 *Date : 2014-11-07 15:26:36
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
#define maxn 50010
struct seg{
    int v,w,next;
}edge[maxn<<2];
int tot;
int head[maxn];

int length[maxn];
int lmax[maxn],rmax[maxn];
int lmaxid[maxn],rmaxid[maxn];
int ans[maxn];
int n,m;
int st[maxn][32];
int stmax[maxn][32];
int plog[maxn];
void addedge(int u,int v,int w)
{
    edge[++tot].v =  v; 
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u]= tot;
}
void dfs(int u,int fa)
{
    lmax[u] =rmax[u] =lmaxid[u] = rmaxid[u] = 0;
    for(int i = head[u];~i;i=edge[i].next) 
    {
        int v = edge[i].v;
        int w = edge[i].w;
        if(fa == v) continue;
        dfs(v,u);
        if(lmax[v] + w >rmax[u])
        {
            rmaxid[u] =v;
            rmax[u] = lmax[v] +w;
            if(lmax[u]<rmax[u])
            {
                swap(lmax[u],rmax[u]);
                swap(lmaxid[u],rmaxid[u]);
            }
        }
    }
}
void dfs2(int u,int fa)
{
    for(int i =head[u];~i;i = edge[i].next)
    {
        int v = edge[i].v;
        if(fa == v) continue;
        if(lmaxid[u] == v)
        {
            if(rmax[u] + edge[i].w >rmax[v])
            {
                rmax[v] = rmax[u] +edge[i].w;
                rmaxid[v] = u;
                if(lmax[v]<rmax[v])
                {
                    swap(lmax[v],rmax[v]);
                    swap(lmaxid[v],rmaxid[v]);
                }
            }
        }
        else {
            if(lmax[u]+edge[i].w >rmax[v])
            {
                rmax[v] = lmax[u] +edge[i].w;
                rmaxid[v] =u;
                if(lmax[v]<rmax[v])
                {
                    swap(lmax[v],rmax[v]);
                    swap(lmaxid[v],rmaxid[v]);
                }
            }
        }
        dfs2(v,u);
    }
}
void st_init(int n)
{
    plog[0] = -1;
    for(int i=1;i<=n;i++)
    {
        plog[i] = plog[i-1];
        if((1<<plog[i] +1)==i)
            plog[i] ++;
        st[i][0] = length[i];
        stmax[i][0] = length[i];
    }
    for(int j = 1;j<=plog[n];j++)
    {
        for(int i =1 ;(i+(1<<j)-1)<=n;i++)
        {
            st[i][j] = min (st[i][j-1],st[i+(1<<j-1)][j-1]);
            stmax[i][j] = max(stmax[i][j-1],stmax[i+(1<<j-1)][j-1]);
        }
    }
}
int query(int l,int r)
{
    int len = r-l+1,k = plog[len];
    return max(stmax[l][k],stmax[r-(1<<k)+1][k])-min(st[l][k],st[r-(1<<k)+1][k]);
}
int check(int m)
{
    int & res = ans[m];
    if(res != -1) return res;
    for(int i =1;i +m -1<=n;i++)
    {
        if(res == -1) res = query(i,i+m-1);
        else res = min(res,query(i,i+m-1));
    }
    return res;
}
int main()
{
    int x,y,z;
    while(~scanf("%d%d",&n,&m)&&n*m)
    {
        tot = 0;
        memset(head,-1,sizeof(head));
        for(int i =1;i<=n-1;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
        }
        dfs(1,1);
        dfs2(1,1);
        for(int i =1;i<=n;i++)
            length[i] = lmax[i];
        st_init(n);
        memset(ans,-1,sizeof(ans));
        ans[1] = 0;
        int q;
        while(m--)
        {
            scanf("%d",&q);
            int l =1,r = n+1;
            while(l <r )
            {
                int mid = (l+r)/2;
                if(check(mid)<=q)
                {
                    l =mid +1;
                }else r = mid;
            }
            printf("%d\n",l-1);
        }
    }
    return 0;
}

