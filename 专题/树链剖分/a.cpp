/*
 *File:  a.cpp
 *Date : 2014-09-30 21:28:51
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
#define maxn 50050
using namespace std;
int fa[maxn],dep[maxn],top[maxn],w[maxn],siz[maxn],son[maxn];
vector <int> g[maxn];
int a[maxn];
int tree[maxn<<2];
int cnt;
int n,m,p;
int root;


void dfs(int x)
{
    siz[x] = 1; son[x] = 0;
    for(int i = 0;i<g[x].size();i ++)
        if( g[x][i]!= fa[x])
        {
            fa[g[x][i]] = x;
            dep[g[x][i]] = dep[x] + 1;
            dfs(g[x][i]);
            if(siz[g[x][i]] > siz[son[v]]) son[v] = g[x][i];
            siz[x] += siz[g[x][i]];
        }
    
}
void build_tree(int x, int tp)
{
    w[x] = ++cnt; top[x] = tp;
    if(son[x]!=0) build_tree(son[x],top[x]);
    for(int i = 0 ; i<g[x].size(); i++)
        if(g[x][i]!=son[v] && g[x][i]!= fa[x])
            build_tree(g[x][i],g[x][i]);
}
void update(int x, int data)
{
   for(;x;x-=x&(-x)) tree[x] +=data;
}
int sum(int x)
{
    int ans = 0;
    for(;x<=n;x+=x&(-x)) ans +=tree[x];
    return ans;
}
inline int find(int va,int vb)
{
    int f1 = top[va],f2 = top[vb],tmp = 0;
    while(f1!=f2)
    {
        if(dep[f1]< dep[f2])
        {swap(f1,f2);swap(va,vb);}
        tmp = max(tmp,)
    }
}

int main()
{
    cnt = 0;
    root =1;
    fa[root] = dp[root] = 0;
    clr(siz);clr(tree);
    scanf("%d%d%d",&n,&m,&p);
    loop(i,1,n)
    {
        scanf("%d",&a[i]);
    }
    int x,y;
    loop(i,1,m)
    {
       scanf("%d%d",&x,&y); 
       g[x].push_back(y);
       g[y].push_back(x);
    }
    dfs(root);
    build_tree(root,root);
    loop(i,1,n)
    {
       update(w[i],a[i]);
       if(w[i]>1)
       update(w[i]-1,-a[i]);
    }
    char str[2];
    loop(i,1,p)
    {
        scanf("%s",str);
        if(str[0]=='I')
        {
            
        }
        
    }
    return 0;
}

