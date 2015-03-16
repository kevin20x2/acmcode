/*
 *File:  f.cpp
 *Date : 2015-03-15 10:36:22
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
int a,b;

int main()
{
    while(~scanf("%d%d",&a,&b))
        printf("%d\n",a*b);
    return 0;
}

