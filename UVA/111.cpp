/*
 *File:  111.cpp
 *Date : 2014-09-19 15:34:18
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
typedef long long LL;
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
int a[22];
int myhash[22];
int dp[22];
int maxn[22];
int x;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        myhash[x]=i;
    }
    while(~scanf("%d",&a[1]))
    {
        memset(maxn,0x3f,sizeof(maxn));
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=n;i++)
            scanf("%d",&a[i]);
        dp[1]=1;maxn[1]=myhash[a[1]];
        for(int i=2;i<=n;i++)
        {
            int ans=-inf;
            int flag = 0;
            for(int j=1;j<i;j++)
            {
                if(myhash[a[i]]>maxn[j])
                {
                    ans = max(ans,dp[j]+1);
                    if(dp[j]==dp[i-1]-1)
                        flag = 1;
                }
                else{
                    ans = max(ans,dp[j]);
                }
            }
            if(ans == dp[i-1]&&flag == 0)
                maxn[i]=maxn[i-1];
            else maxn[i]=myhash[a[i]];
            dp[i]=ans;
        }
        printf("%d\n",dp[n]);
    }


    return 0;
}

