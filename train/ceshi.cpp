
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
const int maxN = 2e4;  
int M, R, N;  
int a[maxN];  
double p[1000][1000];  
double dp[maxN][125];  
int C(int x) {  
    return x * (x - 1) * (x - 2) / 6;  
}  
int main() {  
  
    while(~scanf("%d", &M)) {  
        R = C(M);  
        for(int i = 1; i <= R; ++i)  
            for(int j = 1; j <= R; ++j) scanf("%lf", &p[i][j]);  
        scanf("%d", &N);  
        for(int i = 1; i <= N; ++i)  
         scanf("%d", &a[i]), ++a[i];  
         memset(dp,0,sizeof(dp));  
         for(int i=1;i<=R;i++)  
         dp[0][i]=1;  
         for(int i=1;i<=N;i++)  
         {  
             for(int j=1;j<=R;j++)  
             {  
                 dp[i][j]=max(dp[i][j],dp[i-1][j]*p[j][a[i]]);  
                 dp[i][a[i]]=max(dp[i][a[i]],dp[i-1][j]*p[j][a[i]]);  
             }  
         }  
         double ans=0;  
         for(int i=1;i<=R;i++)  
         {  
             if(dp[N][i]>ans)  
             ans=dp[N][i];  
         }  
        printf("%.6f\n", ans);  
    }  
    return 0;  
} 

