/*
 *File:  wintertraind.cpp
 *Date : 2015-01-09 15:12:28
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
int dp[250][250];
int a[250];
int b[250];
int n;


int main()
{
    int T;
    scanf("%d",&T);
    int cas = 0;
    while(T--)
    {
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i =1;i<=n;i++)
            scanf("%d",&b[i]);
        memset(dp,0x3f,sizeof dp);
        for(int i =0;i<=n+1;i++)
            for(int j = 0;j<=n+1;j++) if(i==j||j==i+1)
                dp[i][j] = 0;
            for(int i = 0;i<=n+1;i++)
            {
                for(int j = 0;j<=n+1;j++)
                {
                    int l = j;
                    int r = i+j;
                    if(r >n+1)
                        continue;
                    for(int k = l+1;k<=n+1;k++)
                    {
                        dp[l][r] =min(dp[l][r],dp[l][k]+dp[k][r]+a[k]+b[l]+b[r]);
                    }
                }
            }

        printf("Case #%d: %d\n",++cas,dp[0][n+1]);
        
    }
    return 0;
}

