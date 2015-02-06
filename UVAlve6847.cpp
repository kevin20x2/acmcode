/*
 *File:  UVAlve6847.cpp
 *Date : 2014-12-21 11:12:59
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
LL a,b;

int main()
{
    while(~scanf("%lld%lld",&a,&b)&&a&&b)
    {
        LL sum = b/5 - a/5+1;
        printf("%lld\n",sum);


    }
    return 0;
}

