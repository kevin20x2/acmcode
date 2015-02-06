/*
 *File:  uva674.cpp
 *Date : 2014-10-23 14:31:04
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
#define maxn 7500

using namespace std;
int dp[maxn+10][6];
int a[6] = {0,1,5,10,25,50};

int main()
{
    clr(dp);
    dp[0][0] =1;
    for(int i =1;i<=5;i++)
    {
        for(int t = 0;t<=maxn;t++)
        for(int j =0;a[i]*j+t<=maxn;j++)
        {
            dp[t+a[i]*j][i]+=dp[t][i-1];
        }
        
    }
    int x;
    while(~scanf("%d",&x))
    printf("%d\n",dp[x][5]);
    return 0;
}

