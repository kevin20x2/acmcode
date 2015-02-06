/*
 *File:  UVAlive6843.cpp
 *Date : 2014-12-21 11:25:30
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
int prime[100000];
int b[100000];
bool v[100000];
int tot;
int m;
int ans;
void get(int n)
{
    tot =0 ;
    memset(v,true,sizeof(v));
    for(int i =2;i<=n;i++)
    {
        if(v[i])
        {
            tot ++;
            prime[tot] = i;
        }
        for(int j = 1;((j<=tot)&& (i*prime[j]<=n));j++)
        {
            v[i*prime[j]] = false ;
            if( i%prime[j]==0) break;
        }
    }
}
void dfs(int dep,int now)
{
    if(prime[dep] >m ) 
    {
        if(now<=m*m)
        {
            ans++;
            printf("%d ",now);
        }
        return ;
    }
    int tmp =1;
    for(int i =0;;i++)
    {
        if(now*tmp<=m*m)
            dfs(dep+1,now*tmp);
        else break;
        tmp*=prime[dep];
    }
}

int main()
{
    get(30000);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(b,0,sizeof b);
        ans =0;
        scanf("%d",&m);
        for(int i =1;i<=n;i++)
        dfs(1,1);
        printf("%d\n",ans);
        
    }
    return 0;
}

