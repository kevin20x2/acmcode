/*
 *File:  2014.12.7a.cpp
 *Date : 2014-12-07 12:35:00
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
double x[4];
double y[4];

int main()
{
    while(~scanf("%lf%lf",&x[1],&y[1]))
    {
        for(int i =2;i<=3;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        double a = sqrt((x[2]-x[1])*(x[2]-x[1])+(y[2]-y[1])*(y[2]-y[1]));
        double b = sqrt((x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]));
        double c = sqrt((x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]));
        printf("%f\n",(a+b-c)/2);
        printf("%f\n",(a+c-b)/2);
        printf("%f\n",(b+c-a)/2);
    }
    return 0;
}

