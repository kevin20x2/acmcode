/*
 *File:  train114i.cpp
 *Date : 2014-11-14 10:40:24
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
double dp1[15][5][1010];
double dp2[15][5][1010];
int T;
int n,a;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<5;j++)
            {
                dp[i][j][]=
                
            }
        }
        
    }
    return 0;
}

