/*
 *File:  wintertrainC.cpp
 *Date : 2015-01-04 20:26:25
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;
vector<int> v[41];
bool inque[1000005];
int dp[45][2000005];
int a[45];
int n,m;

int main()
{
    int T;
    scanf("%d",&T);
    int cas = 0;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i =1;i<=n;i++)
            v[i].clear();
        memset(dp,0,sizeof dp);
        memset(inque,0,sizeof inque);
        for(int i =1;i<=n;i++)
            scanf("%d",&a[i]);
        v[1].push_back(0);v[1].push_back(a[1]);
        inque[0] = 1;inque[a[1]]  =1;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 0;j<v[i-1].size();j++) 
            {
                v[i].push_back(v[i-1][j]);
                if(!inque[v[i-1][j]^a[i]])
                {
                    v[i].push_back(v[i-1][j]^a[i]);
                    inque[v[i-1][j]^a[i]] = 1;
                }
            }
        }
        dp[1][0] = 1; dp[1][a[1]] = 1;
        for(int i =2;i<=n;i++)
        {
            for(int j =0;j<v[i].size();j++)
            {
                dp[i][v[i][j]] = dp[i-1][v[i][j]^a[i]]+dp[i-1][v[i][j]];
            }
        }
        LL ans = 0;
        for(int i = 0;i<v[n].size();i++) if(v[n][i]>=m)
            ans+= 1LL*dp[n][v[n][i]];
        printf("Case #%d: ",++cas);
        cout<<ans<<endl;

    }
    return 0;
}

