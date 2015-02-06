/*
 *File:  c.cpp
 *Date : 2014-09-07 13:39:51
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define N 100002
using namespace std;
vector <int > g[N];
set <int > G[N];
int a[N];
char sen[N];
char vis[N];
int id[N];
int T;
int n,m,k;
int l;
int x,y;
void dfs(int x,int fa)
{
    vis[x]=1;
    id[x]=fa;
    for(int i=0;i<g[x].size();i++) if(!vis[g[x][i]]&&!sen[g[x][i]])
    {
        dfs(g[x][i],fa);
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            G[i].clear();
            id[i]=i;
        }
        clr(vis);
        clr(sen);
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&x);
            sen[x]=1;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1;i<=n;i++) if(!vis[i]&&!sen[i])
        {
            dfs(i,i);
        }
        for(int i=1;i<=n;i++)
        {
                for(int j=0;j<g[i].size();j++)
                {
                    G[id[i]].insert(id[g[i][j]]);
                }
        }
        for(int i=1;i<=n;i++) if(!sen[i]&&!G[i].empty())
        {
            for(set <int> ::iterator it = G[i].begin();it!=G[i].end();it++)
                for( set <int> ::iterator ity=it;ity!=G[i].end();ity++)
                {
                    G[*it].insert(*ity);
                }
        }
        scanf("%d",&l);
        for(int i=1;i<=l;i++)
        {
            scanf("%d",&a[i]);
        }
        int flag =0 ;
        for(int i=1;i<l;i++)
        {
            if(find(G[a[i]].begin(),G[a[i]].end(),a[i+1])==G[a[i]].end())
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            puts("Yes");
        else puts("No");
    }
    return 0;
}

