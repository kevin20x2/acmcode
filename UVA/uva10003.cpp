/*
 *File:  uva10003.cpp
 *Date : 2014-10-23 16:02:51
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
int dp[55][55];
int a[55];
int l;
int n;
int get(int l, int r)
{
    if(dp[l][r]!=0) return dp[l][r];
    if(l+1==r) return 0;
    int ans  = inf;
    for(int i =l+1;i<r;i++)
    {
        ans = min(ans,get(l,i)+get(i,r)+a[r]-a[l]);
    }
    return dp[l][r]=ans;
}

int main()
{
    while(~scanf("%d",&l)&&l)
    {
        clr(dp);
        scanf("%d",&n);
        a[0] = 0;
        for(int i =1;i<=n;i++)
            scanf("%d",&a[i]);
        a[n+1] = l;
        printf("The minimum cutting is %d.\n",get(0,n+1));
    }
    return 0;
}

