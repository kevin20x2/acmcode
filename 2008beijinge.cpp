/*
 *File:  2008beijinge.cpp
 *Date : 2014-11-01 16:42:41
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)
#define eps 1e-8

using namespace std;
int g[20][20];
int a[20];
int dp[16][1<<16];
int inque[1<<16];
int n,m;
queue <int> q;
int edge(int x,int u)
{
    int ans = inf;
   for(int i =1;i<=n;i++) 
   {
        if(x&(1<<(i-1)))
            ans = min(ans,g[i][u]);
   }
   return ans;
}
int weight(int x)
{
    int ans = 0;
    for(int i =1;i<=n;i++)
    {
        if(x&(1<<(i-1)))
            ans += a[i];
    }
    return ans;
}
int cmp(int a,int b)
{
    for(int i=1;i<=n;i++)
    {
        if((a&(1<<(i-1)))&&(b&(1<<(i-1)))) continue;
        else if((a&(1<<i-1))) return a;
        else if((b&(1<<i-1))) return b;
        else continue;
    }
    return a;
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n*m)
    {
        for(int i =1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i = 1;i<=n;i++)
            for(int j =1;j<=n;j++)
                scanf("%d",&g[i][j]);
        memset(dp,0x3f,sizeof(dp));
        while(!q.empty()) q.pop();
        clr(inque);
        for(int i =1;i<=n;i++)
        {
            dp[1][1<<(i-1)] = 0;
            q.push(1<<(i-1));
            //inque[1<<(i-1)] =1;
        }
        for(int i =2;i<=m;i++)
        {
            int size = q.size();
            while(size --)
            {
                int t = q.front();
                //printf("%x ",t);
                for(int j =1;j<=n;j++) 
                {
                    //printf("*%d %x %x %d\n",j,t&(1<<(j-1)),t|(1<<(j-1)),inque[t|(1<<(j-1))]);
                    if((t&(1<<(j-1)))==0)
                    {
                        dp[i][t|(1<<(j-1))] = min(dp[i][t|(1<<(j-1))],dp[i-1][t]+edge(t,j));
                        q.push(t|(1<<(j-1)));
                        //inque[t|(1<<(j-1))] =1;
                    }
                }
                q.pop();
             //   inque[t] =0;
            }
            
        }
        double ans =inf;
        int res = 0;
        while(!q.empty())
        {
            int t = q.front();
            //printf("%x %d %d\n ",t,dp[m][t],weight(t));
            if(ans >1.0*dp[m][t]/weight(t))
            {
                ans =1.0*dp[m][t]/weight(t);
                res  = t;
            }else if(abs(ans - 1.0*dp[m][t]/weight(t))<eps)
            {
                res = cmp(res,t);
            }
            q.pop();
        }
        int first = 1;
        for(int i =1;i<=n;i++)
        {
            if(res&(1<<(i-1)))
            {
                if(first )
                {
                    first = 0;
                printf("%d",i);
                }
                else printf(" %d",i);
                
            }
        }
        printf("\n");

    }

    return 0;
}

