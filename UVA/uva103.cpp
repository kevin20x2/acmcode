/*
 *File:  uva103.cpp
 *Date : 2014-10-21 15:48:11
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
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
struct seg{
    int a[32];
    int c;
}v[32];
int dp[32];
int fa[32];
stack <int> s;
int n,k;

int cmp(seg a ,seg b)
{
    return a.a[1]<b.a[1];
}

int in(seg a,seg b)
{
    for(int i =1;i<=k;i++)
        if(a.a[i]>=b.a[i]) return 0;
    return 1;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        clr(dp);
        memset(fa,-1,sizeof(fa));
        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
                scanf("%d",&v[i].a[j]);
            sort(v[i].a+1,v[i].a+k+1);
            v[i].c = i;
        }
        sort(v+1,v+n+1,cmp);
        for(int i =1;i<=n;i++)
            dp[i] = 1;
        for(int i =2;i<=n;i++)
            for(int j =1;j<i;j++)
            {
                if(in(v[j],v[i])==1)
                {
                    dp[i] = max(dp[i],dp[j]+1);
                    if(dp[i] == dp[j]+1)
                        fa[i] = j;
                }
            }
        int ans = 0;
        int maxn = -1;
        for(int i =1;i<=n;i++)
        {
            ans = max(ans,dp[i]);
            if(ans == dp[i])
                maxn = i;
        }
        int t = maxn;
        while(t!=-1)
        {
            s.push(v[t].c);
            t = fa[t];
        }
        int first = 1;
        printf("%d\n",ans);
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
    }
    return 0;
}

