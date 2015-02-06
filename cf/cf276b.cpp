/*
 *File:  cf276b.cpp
 *Date : 2014-11-06 14:43:15
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
#define maxn 1010

int n;
int main()
{
    int maxx=-inf,maxy=-inf;
    int minx=inf,miny=inf;
    scanf("%d",&n);
    int x,y;
    for(int i =1;i<=n;i++)
    {
        scanf("%d%d",&x,&y);
        maxx =max(maxx,x);
        maxy =max(maxy,y);
        minx = min(minx,x);
        miny = min(miny,y);
    }
    int ans  = max(maxx-minx,maxy-miny);
    printf("%lld\n",1LL*ans*ans);
    return 0;
}

