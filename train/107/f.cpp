#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include<stdio.h>
#include<string.h>
using namespace std;
const double EPS        = 1e-6;
struct Point {              // 二维点或矢量
    double x, y;
    double angle, dis;
    Point() {}
    Point(double x0, double y0): x(x0), y(y0) {}
}pp[25];

        int n;
struct Line {               // 二维的直线或线段
    Point p1, p2;
    Line() {}
    Line(Point p10, Point p20): p1(p10), p2(p20) {}
};
 double max(double x,double y)
{
    return x > y ? x : y;
}
 double min(double x, double y)
{
    return x > y ? y : x;
}

 bool ZERO(Point p)               // p == 0
{
    return (fabs(p.x)<EPS && fabs(p.y)<EPS);
}
 bool EQ(double x, double y)      // eqaul, x == y
{
    return (fabs(x - y) < EPS);
}
 bool NEQ(double x, double y)     // not equal, x != y
{
    return (fabs(x - y) >= EPS);
}
 bool LT(double x, double y)     // less than, x < y
{
    return ( NEQ(x, y) && (x < y) );
}
 bool GT(double x, double y)     // greater than, x > y
{
    return ( NEQ(x, y) && (x > y) );
}
 bool LEQ(double x, double y)     // less equal, x <= y
{
    return ( EQ(x, y) || (x < y) );
}
 bool GEQ(double x, double y)     // greater equal, x >= y
{
    return ( EQ(x, y) || (x > y) );
}
const double eps=1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}

bool operator==(Point p1, Point p2)
{
    return ( EQ(p1.x, p2.x) &&  EQ(p1.y, p2.y) );
}
bool operator!=(Point p1, Point p2)
{
    return ( NEQ(p1.x, p2.x) ||  NEQ(p1.y, p2.y) );
}
bool operator<(Point p1, Point p2)
{
    if (NEQ(p1.x, p2.x)) {
        return (p1.x < p2.x);
    } else {
        return (p1.y < p2.y);
    }
}
Point operator+(Point p1, Point p2)
{
    return Point(p1.x + p2.x, p1.y + p2.y);
}
Point operator-(Point p1, Point p2)
{
    return Point(p1.x - p2.x, p1.y - p2.y);
}
double operator*(Point p1, Point p2) // 计算叉乘 p1 × p2
{
    return (p1.x * p2.y - p2.x * p1.y);
}
double operator&(Point p1, Point p2) { // 计算点积 p1·p2
    return (p1.x * p2.x + p1.y * p2.y);
}
bool OnLineSeg(Point p, Line L) // 判断二维平面上点p是否在线段l上
{
    return ( fabs((L.p1 - p) * (L.p2 - p))<EPS  &&
        LEQ((p.x - L.p1.x)*(p.x - L.p2.x), 0) &&
        LEQ((p.y - L.p1.y)*(p.y - L.p2.y), 0) );
}
bool SameSide(Point p1, Point p2, Line L) // 判断点p1, p2是否在直线L的同侧
{
    double m1 = (p1 - L.p1) * (L.p2 - L.p1);
    double m2 = (p2 - L.p1) * (L.p2 - L.p1);
    return GT(m1 * m2, 0);
}
int InsideConvex(Point p, Point pp[]) // 判断点p是否在凸多边形poly内
{
    Point q(0, 0);
    Line side;
    int i ;

    for (i = 0; i < n; i++) {
        q.x += pp[i].x;
        q.y += pp[i].y;
    }
    q.x /= n;
    q.y /= n;
    for (i = 0; i < n; i++) {
        side.p1 = pp[i];
        side.p2 = pp[(i+1)%n];
        if (OnLineSeg(p, side)) {
            return 0;
        } else if (!SameSide(p, q, side)) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int v,b,g;
    while(scanf("%d%d%d",&v,&b,&g)!=EOF)
    {
        if(!v&&!b&&!g)
            break;
        scanf("%d",&n);
        int maxy=0;
        double x,y;
        int T;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&pp[i].x,&pp[i].y);
            if(pp[i].y>maxy)maxy=pp[i].y;
        }

        if (g) {
            T = 2.0*b/g;
        } else {
            T = maxy / b;
        }
        v=-v;
        double t;
        int mark=0;
        for(t=0;t<=T;t+=0.0001)
        {
            Point bullet;
            bullet.x=v*t;
            bullet.y=b*t-0.5*g*t*t;
            mark=InsideConvex(bullet,pp);
            if(mark==1)break;
            if(bullet.y<0||bullet.y>maxy)break;
        }
        if(mark)printf("%.2lf\n",t);
        else printf("Miss!\n");
    }
    return 0;
}

