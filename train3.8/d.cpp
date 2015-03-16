/*
 *File:  d.cpp
 *Date : 2015-03-08 15:58:50
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
const int maxn =10010;
vector <int> v[maxn];
int n,m;
int vis[maxn];
int id;
bool ans;
void find_loop(int x,int id)
{
    vis[x] = id;
    for(int i = 0;i<v[x].size();i++)
    {
        if(ans ) return ;
        if(vis[v[x][i]]==0)
            find_loop(v[x][i],id);
        else if(vis[v[x][i]]==id){
            bool flag = 0;
            for(int i =0;i<n;i++) if(vis[i]==0)
            {
                flag = 1;
                find_loop(i,id+1);
            }
            if(!flag) { 
                ans = 1;
                return ;
            }
        }
    }
    vis[x] = 0;
    
}
int main()
{
    int x,y;
    while(~scanf("%d%d",&n,&m))
    {
        ans = 0;
        memset(vis,0,sizeof vis);
        for(int i =0;i<n;i++)
            v[i].clear();
        for(int i = 1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
        }
        find_loop(0,1);
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}

