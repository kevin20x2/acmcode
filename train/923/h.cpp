/*
 *File:  h.cpp
 *Date : 2014-09-24 15:12:58
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
int c[1300];
int w[1300];
double dp[1300][1300];
int n,m;
int T;

int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        scanf("%d%d",&n,&m);
        loop(i,1,n)
            scanf("%d",&c[i]);
        loop(i,1,n)
            scanf("%d",&w[i]);
        loop(i,1,n)
            loop(j,0,m)
                dp[i][j]=16000;
        dp[1][0] = 15000*1.0*(100-2*w[1])/100;
        dp[1][1] = 15000*1.0*(2*c[1]-100)/100;
        loop(i,2,n){
            loop(j,0,i) 
            {
                if(j!=0&&j<=m)
                    dp[i][j]=min(dp[i-1][j]*1.0*(100-2*w[i])/100,dp[i-1][j-1]*1.0*(2*c[i]-100)/100);
                else if(j<=m) dp[i][j]=dp[i-1][j]*1.0*(100-2*w[i])/100;
            }
        }
        double ans = 16000;
        loop(i,1,n){
            loop(j,0,i) if(j<=m)
                printf("%f ",dp[i][j]);
            printf("\n");
        }
        loop(i,0,m)
            ans= min(ans,dp[n][i]);
        printf("Case #%d: %.3f\n",cas,ans);
        
    }
    return 0;
}

