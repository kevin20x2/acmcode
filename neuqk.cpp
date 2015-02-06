/*
 *File:  neuqk.cpp
 *Date : 2014-11-29 10:23:30
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
bool g[55][55];
vector <int > v[55];
bool vis[55];
int n,m,k;
int ans;
int now;
void dfs(int x, int dep)
{
    vis[x] = true;
    if(dep == k)
    {
        if(g[x][now] == true) ans = 1;
        return;
        
    }
    for(int i = 0;i<v[x].size();i++) if(!vis[v[x][i]])
    {
        dfs(v[x][i],dep+1);
    }
    vis[x] = false;


    
}

int main()
{
    int cas;
    scanf("%d",&cas);
    int x,y;
    while(cas--)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(n<k ) {
            puts("NO");
            continue;
        }
        for(int i =0;i<n;i++)
            v[i].clear();
        ans = 0;
        memset(g,0,sizeof(g));
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
            g[x][y] = true;
            g[y][x] = true;
        }
        for(int i = 0;i<n;i++)
        {
            now = i;
            memset(vis,0,sizeof(vis));
            dfs(now,1);
            if(ans == 1) 
            {
                puts("YES");
                break;
            }
        }
        if(ans == 0)
            puts("NO");
        
    }

    return 0;
}

