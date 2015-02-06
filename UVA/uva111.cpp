/*
 *File:  uva111.cpp
 *Date : 2014-10-21 14:00:04
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
int n;
int rank[22];
int a[22];
int dp[22][22];

int main()
{
    scanf("%d",&n);
    int x;
    for(int i =1;i<=n;i++)
    {
        scanf("%d",&x);
        rank[x] = i;
    }
  
    while(~scanf("%d",&x))
    {
        memset(dp,0,sizeof(dp));
        a[x] = 1;
        for(int i =2;i<=n;i++)
        {
            scanf("%d",&x);
            a[x] =i;
        }
        for(int i =0;i<=n;i++)
        {
            dp[i][0] = 0;
            dp[0][i] = 0;
        }
        for(int i =1;i<=n;i++)
            for(int j =1;j<=n;j++)
            {
                if(rank[i]==a[j])
                    dp[i][j] = dp[i-1][j-1] +1;
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        printf("%d\n",dp[n][n]);
    }
    return 0;
}

