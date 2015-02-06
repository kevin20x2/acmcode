/*
 *File:  UVAlive6851.cpp
 *Date : 2014-12-21 12:49:21
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
vector <int>g[507];
int p,s,c,m;

int match[2007];
int tot;
bool vis[2007];
bool dfs(int x)
{
    for(int i = 0;i<g[x].size();i++)
    {
        int u =g[x][i];
        if(!vis[u])
        {
            vis[u] = true;
            if(match[u] == -1||dfs(match[u]))
            {
                match[u] = x;
                return true;
            }
            
        }
    }
    return false ;
}

int main()
{
    int T;
    int x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&p,&s,&c,&m);
        for(int i =1;i<=p;i++)
            g[i].clear();
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            for(int j = 1;j<=c;j++)
                g[x].push_back((y-1)*c+j);
        }
        tot = 0;
        memset(match,-1,sizeof(match));
        for(int i =1;i<=p;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))
                ++tot;
        }
        printf("%d\n",tot);
        
    }
    return 0;
}

