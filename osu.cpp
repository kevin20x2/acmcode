/*
 *File:  osu.cpp
 *Date : 2014-10-22 12:30:48
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
#define maxn 1000010

int T;
int n;
int t[maxn];
int x[maxn];
int y[maxn];
double dist(int a,int b)
{
    return sqrt(pow((double)(x[a]-x[b]),2)+pow((double)(y[a]-y[b]),2))/(double)(t[b]-t[a]);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
        {
            scanf("%d%d%d",&t[i],&x[i],&y[i]);
        }
        double ans = 0;
        for(int i =1;i<n;i++)
            ans = max(ans,dist(i,i+1));
        printf("%.10f\n",ans);
    }
    return 0;
}

