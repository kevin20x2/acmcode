/*
 *File:  2014.12.7g.cpp
 *Date : 2014-12-07 13:04:19
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<stack>
#include<algorithm>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
int n,m;
int dp[110][27];
int a[110];
int g[27][27];
int head[110][27];

int main()
{
    int x;
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,0x3f,sizeof(dp));
        memset(head,-1,sizeof(head));
        for(int i =1;i<n;i++)
            scanf("%d",&a[i]);
        for(int i =1;i<=m;i++)
            for(int j =1;j<=m;j++)
            {
                scanf("%d",&x);
                g[i][j] = x;
            }
        for(int i =1;i<=m;i++)
            dp[1][i] = 0;
        for(int i = 2;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                for(int k = m;k>=1;k--)
                {
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+abs(a[i-1]-g[k][j]));
                    if(dp[i][j]==(dp[i-1][k]+abs(a[i-1]-g[k][j])))
                    {
                        head[i][j] = k;
                    }
                }
            }
        }
        //printf("%d %d",dp[n][1],dp[n][3]);

        int ans = inf;
        int res = -1;
        for(int i = 1;i<=m;i++)
        {
            if(dp[n][i]<ans)
            {
                ans = dp[n][i];
                res = i;
            }
        }
        stack <int> s;
        int x= n;
        while(x!=0)
        {
            s.push(res);
            res = head[x][res];
            x--;
        }
        while(!s.empty())
        {
            int t = s.top();
            putchar('a'+t-1);
            s.pop();
        }
        putchar('\n');
        
    }
    return 0;
}

