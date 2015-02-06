/*
 *File:  2008hefeic.cpp
 *Date : 2014-11-09 15:58:58
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
#define maxn 100010
struct seg{
    int v,next;
}edge[maxn<<2];
int tot;
int head[maxn];
int visedge[maxn<<2];
int visedge2[maxn<<2];
int vis[maxn];
int n,m;
int s,t;
bool ans;
void addedge(int u,int v)
{
    edge[++tot].v = v;
    edge[tot].next = head[u];
    head[u] = tot;
}
void dfs(int x)
{
    vis[x] = 1;
    if(x==t)
    {
        for(int i =1;i<=tot;i++)
                visedge2[i] = visedge[i];
        return ;
    }
    for(int i =head[x];~i;i=edge[i].next) 
    {
        int v= edge[i].v;
        if(!vis[v])
        {
            visedge[i] =1;
            dfs(v);
            visedge[i] = 0;
        }

    }
    
}
void dfs2(int x)
{
    vis[x] =1;
    if(x==t)
    {
        ans =1;
        return ;
    }
    for(int i =head[x];~i;i=edge[i].next) if(!visedge2[i])
    {
        int v=edge[i].v;
        if(!vis[v])
        {
            dfs2(v);
        }
    }
}


int main()
{
    int tt =0;
    while(~scanf("%d%d",&n,&m)&&n*m)
    {
        printf("Case %d: ",++tt);
        tot =0;
        ans =0;
        memset(head,-1,sizeof(head));
        int x,y;
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);addedge(y,x);
        }
        scanf("%d%d",&s,&t);
        clr(vis);
        clr(visedge);
        clr(visedge2);
        dfs(s);
        clr(vis);
        dfs2(s);
        if(ans)
            puts("YES");
        else puts("NO");
            

    }
    return 0;
}

