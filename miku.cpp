/*
 *File:  miku.cpp
 *Date : 2014-10-22 12:49:32
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
int T;
int n,m;
int g[55][55];
int dp[110][110];
int a[110];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        clr(dp);
        clr(g);
        scanf("%d%d",&n,&m);
        for(int i =1;i<=m;i++)
            for(int j = 1;j<=m;j++)
                scanf("%d",&g[i][j]);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=2;i<=n;i++)
        {
            if(a[i]>=0)
            {  
                if(a[i-1]>=0)
                {
                    dp[i][a[i]] = dp[i-1][a[i-1]] +g[a[i-1]][a[i]];
                }
                else 
                for(int t = 1;t<=m;t++)
                    dp[i][a[i]] = max(dp[i][a[i]],dp[i-1][t] +g[t][a[i]]);
            }
            else 
            for(int j =1;j<=m;j++)
            {
                if(a[i-1]>=0)
                {
                    dp[i][j] = dp[i-1][a[i-1]] + g[a[i-1]][j];
                }
                else 
                for(int t = 1;t<=m;t++)
                    dp[i][j]  = max(dp[i][j],dp[i-1][t]+g[t][j]);
            }
        }
        int ans = 0;
        for(int i= 1;i<=m;i++)
            ans = max(ans,dp[n][i]);
        printf("%d\n",ans);

    }
    return 0;
}

