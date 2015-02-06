/*
 *File:  cf1025f.cpp
 *Date : 2014-10-25 15:39:28
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
#define maxn 200010
int n,k;
int sum[maxn];
int a[maxn];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans = 0;
    int pos = 0;
    if(2*k>=n) {
        for(int i =1;i<=n;i++)
            ans += a[i];
        printf("%d\n",ans);
        return 0;
    }
    for(int i =1;i<=n-2*k+1;i++)
    {
        sum[i] = 0;
        for(int j = 0;j<2*k;j++)
            sum[i] +=a[i+j];
        ans = max(ans,sum[i]);
    }
    for(int i =1;i<=n-k+1;i++)
    {
        sum[i] =0;
        for(int j = 0;j<k;j++)
            sum[i] += a[i+j];
    }
    sort(sum+1,sum+1+n-k+1);
    ans = max(ans,sum[n-k+1]+sum[n-k]);
    printf("%d\n",ans);
        return 0;
}

