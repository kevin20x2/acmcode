/*
 *File:  cf479c.cpp
 *Date : 2014-10-19 17:54:16
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
#define maxn 50010
struct seg
{
    int x,y;
} a[maxn];

int n;
int cmp(seg a,seg b)
{
    return a.x<b.x;
}
int main()
{
    scanf("%d",&n);
    for(int i =1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a+1,a+n+1,cmp);
    int now = 0;
    for(int i =1;i<=n;i++)
    {
        if(a[i].y>=now) 
        {
            now = a[i].y;
        }else now = a[i].x;
    }
    printf("%d\n",now);
    return 0;
}

