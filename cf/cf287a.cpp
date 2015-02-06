/*
 *File:  cf287a.cpp
 *Date : 2015-01-24 00:04:31
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

using namespace std;
struct seg{
    int v,c;
};
seg a[110];
int n,m;
int cmp(seg a,seg b)
{
    return a.v<b.v;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;i++)
    {
        scanf("%d",&a[i].v);
        a[i].c = i;
    }
    sort(a+1,a+n+1,cmp);
    int l = 1;
    while(m>=a[l].v&&l<=n)
    {
        m-=a[l++].v;
    }
    printf("%d\n",l-1);
    int first = 1;
    for(int i = 1;i<l;i++)
    {
        if(first)
        {
            printf("%d",a[i].c);
            first = 0;
        }
        else printf(" %d",a[i].c);
    }
    return 0;
}

