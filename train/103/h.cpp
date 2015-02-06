/*
 *File:  h.cpp
 *Date : 2014-10-03 15:06:18
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
#define N 1002
#define K 102

using namespace std;
int dp[N][K][N];

int gcd(int a, int b)
{
    if(a<b) swap(a,b);
    if(b==0) return a;
    else return gcd(b,a%b);
}
int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}
int n,m,k;
int main()
{
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i = 1;i<=k;i++)
        {
           for(int j = 1;j<=n;j ++) 
           {
            for(int t = 1;t<=m;t++)
                dp[j][i][t] = 
            for(int v = 0;v<j;v++)
           }
        }
        
    }
    return 0;
}

