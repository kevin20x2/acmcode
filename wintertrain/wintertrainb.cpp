/*
 *File:  wintertrainb.cpp
 *Date : 2015-01-09 14:22:32
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
#define eps 1e-9
const double pi = 3.141592653;
double R,r;

struct Circle{
    double x,y;
    double r;
    Circle(double x,double y,double r):x(x),y(y),r(r){}
};

double calArea(Circle c1, Circle c2)
{
    double d;
    double s,s1,s2,s3,angle1,angle2,temp;

    d=sqrt((c1.x-c2.x)*(c1.x-c2.x)+(c1.y-c2.y)*(c1.y-c2.y));
    if(d>=(c1.r+c2.r))//两圆相离
        return 0;
    if((c1.r-c2.r)>=d)//两圆内含,c1大
        return acos(-1.0)*c2.r*c2.r;
    if((c2.r-c1.r)>=d)//两圆内含,c2大
        return acos(-1.0)*c1.r*c1.r;

    angle1=acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
    angle2=acos((c2.r*c2.r+d*d-c1.r*c1.r)/(2*c2.r*d));

    s1=angle1*c1.r*c1.r;s2=angle2*c2.r*c2.r;
    s3=c1.r*d*sin(angle1);
    s=s1+s2-s3;

    return s;
}
int main()
{
    int T;
    int cas = 0;
    scanf("%d",&T);
    double a,b,c,d;
    while(T--)
    {
        scanf("%lf%lf",&r,&R);
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        double ans = calArea(Circle(a,b,R),Circle(c,d,R))-2*calArea(Circle(a,b,R),Circle(c,d,r))+calArea(Circle(a,b,r),Circle(c,d,r));
        printf("Case #%d: ",++cas);
        printf("%.6lf\n",ans);
        
    }
    return 0;
}

