/*
 *File:  1009.cpp
 *Date : 2014-09-27 12:49:53
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
int T;
int a,b;

int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        printf("Case #%d: ",cas);
        scanf("%d%d",&a,&b);
        a--;
        LL sum =(1LL*(1+b)*(1+b)*b*b-1LL*(1+a)*(1+a)*a*a)/4;
        printf("%I64d\n",sum);
    }
    return 0;
}

