/*
 *File:  913j.cpp
 *Date : 2014-09-13 12:17:51
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
int T;
int n;
int a[502];
int cmp(int a, int b)
{
    return a>b;
}
int main()
{
    double ans = 0;
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            ans+=pow(0.95,i-1)*a[i];
        }
        printf("%.10f\n",ans);
        
    }


    return 0;
}

