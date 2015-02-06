/*
 *File:  20141228h.cpp
 *Date : 2014-12-28 14:02:44
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
bool vis[1000];
int g[4][3]={
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {-1,0,-1}
};
void dfs(int dep,int x,int y,int v)
{
    vis[v]=1;
    if(dep==3)
    {
        return ;
    }
    dfs(dep+1,x,y,v*10+g[x][y]);
    if(x+1<4&&g[x+1][y]!=-1)
    {
        dfs(dep,x+1,y,v);
        dfs(dep+1,x+1,y,v*10+g[x+1][y]);
    }
    if(y+1<3&&g[x][y+1]!=-1)
    {
        dfs(dep,x,y+1,v);
        dfs(dep+1,x,y+1,v*10+g[x][y+1]);
    }
}

int main()
{
    memset(vis,0,sizeof vis);
    dfs(0,0,0,0);
    int T;
    int x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&x);
        int minn = inf;
        int res;
        for(int i=0;i<300;i++) if(vis[i])
        {
            //printf("%d\n",i);
            minn = min(minn,abs(i-x));
            if(minn == abs(i-x))
                res = i;
        }
        printf("%d\n",res);
    }
    return 0;
}

