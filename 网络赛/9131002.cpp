/*
 *File:  9131002.cpp
 *Date : 2014-09-13 16:38:07
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
double xa,xb,xc;
double ya,yb,yc;
int T;
int n;
double x,y,p;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        xa=1;xb=xc=0;
        yb=1;ya=yc=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&x,&y,&p);
            xa=xa*cos(p);
            xb=xb*cos(p)-sin(p);
            xc=xc*cos(p)+(1-cos(p))*x+sin(p)*y;
            ya=ya*cos(p)+sin(p);
            yb=yb*cos(p);
            yc=yc*cos(p)+y*(1-cos(p))-sin(p)*x;
        }
        printf("%lf %lf %lf %lf %lf %lf",xa,xb,xc,ya,yb,yc);

    }
    return 0;
}

