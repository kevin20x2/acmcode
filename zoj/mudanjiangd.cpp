/*
 *File:  mudanjiangd.cpp
 *Date : 2014-10-15 13:47:53
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
double dp[2502][52][52];
int n,m;

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        clr(dp);
        scanf("%d%d",&n,&m);
        dp[0][0][0]=1;
        for(int a = 1;a<=n*m;a++)
        {
            for(int i =1;i<=n;i++)
                for(int j = 1;j<=m;j++)
                {
                    dp[a][i][j] = dp[a-1][i-1][j]*(n-i+1)*j/(n*m-a+1)+dp[a-1][i][j-1]*(m-j+1)*i/(n*m-a+1)+dp[a-1][i-1][j-1]*(n-i+1)*(m-j+1)/(n*m-a+1)+dp[a-1][i][j]*(i*j-a+1)/(n*m-a+1);
                    //printf("%lf ",dp[a][i][j]);
                }
        }
        double ans = 0;
        for(int i=1;i<=n*m;i++)
            ans += i*(dp[i][n][m]-dp[i-1][n][m]);
        printf("%.12f\n",ans);

       
    }
    return 0;
}

