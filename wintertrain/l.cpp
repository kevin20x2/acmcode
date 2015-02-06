/*
 *File:  l.cpp
 *Date : 2015-02-06 20:19:36
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

using namespace std;
const int MAXN = 100005;
const int MAXE = 200005;
struct edge{
    int v;
    int next;
}edge[MAXE];
int head[MAXE],tot;
struct point{
    LL x,y;
    int idx;
    point (){}
    point (LL x,LL y):x(x),y(y){}
    point operator- (const point &p) const
    {
        return point(x-p.x,y-p.y);
    }
}p[MAXN],s[MAXN];
int top[MAXN];
int siz[MAXN];
int son[MAXN];
int fa[MAXN];
int dep[MAXN];
void addedge(int u,int v)
{
    edge[tot].v = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int u)
{
    siz[u] = 1;
    son[u] =0;
    for(int i = head[u];~i;i=edge[i].next)
    {
        int v = edge[i].v;
        if( v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u]+1;
        dfs(v);
        if(siz[v]>siz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int p)
{
    top[u] = p;
    if(son[u]) dfs2(son[u],p);
    for(int i = head[u];~i;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v!=son[u]&&v!=fa[u]) dfs2(v,v);
    }
}

int query(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]> dep[top[y]]) x = fa[top[x]];
        else y = fa[top[y]];
    }
    if(dep[x]<dep[y]) return x;
    else return y;
}


int cross(const point &a,const point& b)
{
    return a.x*b.y - a.y*b.x>0;
}
int main()
{
    int n;
    int q;
    int x,y;
    memset(head,-1,sizeof head);
    scanf("%d",&n);
    for(int i =1;i<=n;i++)
    {
        scanf("%I64d%I64d",&p[i].x,&p[i].y);
        p[i].idx = i;
    }
    int pi = 0;
    for(int i = n;i>=1;i--)
    {
        while(pi>1&&cross(s[pi-1]-p[i],s[pi-2]-p[i]))--pi;
        s[pi++] = p[i];
        if(pi>1)
        {
            addedge(s[pi-2].idx,s[pi-1].idx);
        }
    }
    dfs(n);
    dfs2(n,n);
    scanf("%d",&q);
    int first = 1;
    while(q--)
    {
        scanf("%d%d",&x,&y);
        if(first)
        {
            printf("%d",query(x,y));
            first = 0;
        }else printf(" %d",query(x,y));
    }
    printf("\n");

    return 0;
}

