/*
 *File:  112hdu1003.cpp
 *Date : 2014-11-02 13:56:34
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
int dx[3] = {-1,0,1};
int dp[110][110];
int fa[110][110];
int  a[110][110];
int n,m;
int T;

int main()
{
    scanf("%d",&T);
    for(int cas =1;cas<=T;cas++)
    {
        printf("Case %d\n",cas);
        scanf("%d%d",&n,&m);
        for(int i =1;i<=n;i++)
            for(int j =1;j<=m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0x3f,sizeof(dp));
        memset(fa,-1,sizeof(fa));
        for(int i =1;i<=m;i++)
            dp[1][i] = a[1][i];
        for(int i=2;i<=n;i++)
        {
            for(int j =1;j<=m;j++)
            {
                for(int t = 0;t<3;t++) if(j+dx[t]<=m&&j+dx[t]>=1)
                {
                    dp[i][j] = min(dp[i][j],dp[i-1][j+dx[t]] +a[i][j]);
                    if(dp[i][j] == dp[i-1][j+dx[t]]+a[i][j])
                        fa[i][j] = j+dx[t];
                }
                
            }
        }
        int minn = inf;
        int ans = 0;
        for(int i=1;i<=m;i++)
        {
            minn  = min(minn,dp[n][i]);
            if(minn ==dp[n][i])
                ans = i;
        }
        vector <int > v ;
        int t = n;
        while(ans!=-1)
        {
            v.push_back(ans);
            ans = fa[t][ans];
            t--;
        }
        int first =1;
        for(int i =v.size()-1;i>=0;i--)
        {
            if(first)
            {
                first = 0;
                printf("%d",v[i]);
            }
            else printf(" %d",v[i]);
            
        }
        printf("\n");
    }
    return 0;
}

