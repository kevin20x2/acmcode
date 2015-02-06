/*
 *File:  912a.cpp
 *Date : 2014-09-12 23:38:16
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
int n,m,a,b;
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    double ans= 1.0*b/m;
    int sum=0;
    if(ans<(double)a)
    {
        sum+=n/m*b;
        if(n%m!=0&&n%m*a<b)
            sum+=n%m*a;
        else if(n%m!=0)sum+=b;
    }
    else sum = n*a;
    printf("%d\n",sum);
    return 0;
}

