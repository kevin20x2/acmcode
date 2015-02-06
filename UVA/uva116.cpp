/*
 *File:  uva116.cpp
 *Date : 2014-10-27 15:28:22
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf  0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
int a[15][110];
LL dp[15][110];
int  fa[15][110];
int n,m;
int getmin(int a,int b ,int dep)
{
    stack <int > s1;
    stack <int > s2;
    int res = dep;
    int x =a;
    int y =b;
    if(a==b) return a;
    while(dep>=0)
    {
        s1.push(x);
        s2.push(y);
        x = fa[x][dep];
        y =fa[y][dep];
        dep--;
        
    }
    while(!s1.empty()&&!s2.empty())
    {
        if(s1.top()>s2.top()) return b;
        else if(s1.top()<s2.top()) return a;
        s1.pop();s2.pop();
    }
    
}


int main()
{
    while(~scanf("%d%d",&m,&n))
    {
        for(int i = 0;i<m;i++)
        {
            for(int j =0;j<n;j++)
                scanf("%d",&a[i][j]);
        }
        for(int i =0;i<m;i++)
            for(int j = 0;j<n;j++)
            {
                fa[i][j] = inf;
            }
        memset(dp,0x3f,sizeof(dp));
        LL ans = dp[0][0];
        for(int i =0;i<m;i++)
            dp[i][0] = 1LL*a[i][0];
        for(int i=1;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                for(int t = -1;t<=1;t++)
                {
                    if(dp[j][i]>dp[(j+m+t)%m][i-1]+1LL*a[j][i])
                        fa[j][i] = (j+m+t)%m;
                    else if(dp[j][i]==dp[(j+m+t)%m][i-1]+1LL*a[j][i])
                        fa[j][i] = getmin(fa[j][i],(j+m+t)%m,i-1);
                    dp[j][i] = min(dp[j][i],dp[(j+m+t)%m][i-1]+1LL*a[j][i]);
                   
                    
                }
                //printf("%d ",dp[j][i]);
            }
            //printf("\n");
        }
        int f = 0;
        for(int i = m-1;i>=0;i--)
        {
            if(ans>dp[i][n-1])
                f = i;
            else if(ans == dp[i][n-1])
                f = getmin(f,i,n-1);
            ans = min(ans,dp[i][n-1]);
        }
        stack <int> s;
        int col = n-1;
        while(f!=inf)
        {
            s.push(f+1);
            f=fa[f][col--];
        }
        int first=1;
        while(!s.empty())
        {
            if(first)
            {
                printf("%d",s.top());
                first = 0;
            }
            else printf(" %d",s.top());
            s.pop();
        }
        printf("\n");
        printf("%lld\n",ans);
        
    }
    return 0;
}

