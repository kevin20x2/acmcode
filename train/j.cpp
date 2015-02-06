/*
 *File:  j.cpp
 *Date : 2014-09-19 20:04:04
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
#define eps 1e-9

using namespace std;
int n,m;
double g[122][122];
double dp[10002][122];
int a[10002];
int bigger(double a, double b)
{
    return a-b>eps;
}

int main()
{
    while(~scanf("%d",&n))
    {
        int num = n*(n-1)*(n-2)/6;
        loop(i,1,num)
        {
            loop(j,1,num)
            {
                scanf("%lf",&g[i][j]);
            }
        }
        scanf("%d",&m);
        loop(i,1,m)
        {
            scanf("%d",&a[i]);
            if(a[i]>num) a[i] =0;
            a[i]++;
        }
        double ans = 0;
        clr(dp);
        loop(i,1,num)
        {
            dp[0][i] = 1;
        }
        loop(i,1,m)
        {
            loop(j,1,num)
            {
                if(bigger(g[j][a[i]]*dp[i-1][j],dp[i][j]))
                    dp[i][j]=g[j][a[i]]*dp[i-1][j];
                if(bigger(dp[i-1][j]*g[j][a[i]],dp[i][a[i]]))
                    dp[i][a[i]]= dp[i-1][j]*g[j][a[i]];
            }
        }
            printf("%.6f\n",dp[m][a[m]]);
        
    }
    return 0;
}

