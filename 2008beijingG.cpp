/*
 *File:  2008beijingG.cpp
 *Date : 2014-11-01 15:31:49
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
#define maxn 100010
struct seg{
    int s;
    int t;
}a[maxn];
int n;
int length[maxn];
int cmp(seg a,seg b)
{
    if(a.s<b.s) return 1;
    else if(a.s==b.s&&a.t<b.t) return 1;
    return 0;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        for(int i =1;i<=n;i++)
        {
            scanf("%d%d",&a[i].s,&a[i].t) ;
        }
        sort(a+1,a+n+1,cmp);
        for(int i =1;i<=n;i++)
        {
            length[i]  = ceil((a[i].s+a[i].t)/2);
        }
        int last = a[1].s;
        int i;
        for(i =1;i<=n;i++)
        {
            if(a[i].s>=last)
            {
                last = a[i].s+length[i];
            }else if(a[i].t-length[i]>=last)
            {
                last = last + length[i];
            }
            else if(last>a[i].t-length[i])
            {
                puts("NO");
                break;
            }
            else puts("error");
        }
        if(i==n+1)
        puts("YES");
    }
    return 0;
}

