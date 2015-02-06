/*
 *File:  uva10154.cpp
 *Date : 2014-10-28 16:10:09
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
#define maxn 6000
struct seg{
    int x,y;
}a[maxn];
int dp[maxn];
int cmp(seg a,seg b)
{
    return a.y<b.y;
}

int main()
{
    int n =1;
    memset(dp,0x3f,sizeof(dp));
    while(~scanf("%d%d",&a[n].x,&a[n].y)) n++;
    sort(a+1,a+n,cmp);
    int imax = 0;
    dp[0] = 0;
    for(int i =1;i<n;i++)
        for(int j =imax;j>=0;j--) 
        {
            if(a[i].y>=dp[j]+a[i].x&&dp[j+1]>dp[j]+a[i].x)
            {
                dp[j+1] =dp[j] +a[i].x;
                imax = max(imax,j+1);
            }
        }
    printf("%d\n",imax);
    return 0;
}

