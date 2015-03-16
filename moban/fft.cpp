/*
 *File:  fft.cpp
 *Date : 2015-03-15 09:55:56
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<bitset>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;
const double pi= acos(-1.0);
const int maxn = 200010;
struct Complex{
    double x,y;
    Complex() {}
    Complex(double x, double y): x(x),y(y){}
};
Complex operator + (const Complex &a,const Complex &b){
    Complex c;
    c.x = a.x +b.x;
    c.y = a.y +b.y;
    return c;
}
Complex operator - (const Complex &a , const Complex &b)
{
    Complex c;
    c.x =  a.x - b.x;
    c.y = a.y - b.y;
    return c;
}
Complex operator * (const Complex &a,const Complex &b)
{
    Complex c;
    c.x  = a.x * b.x - a.y*b.y;
    c.y = a.x*b.y +a.y*b.x;
   return c;
}
inline void fft (vector <Complex> &a, bool inverse){
    int n = a.size();
    for(int i = 0,j=0;i<n;i++)
    {
        if(j>i)
            swap(a[i],a[j]);
        int k = n;
        while(j & (k>>=1)) j &=~k;
        j|=k;
    }
    double PI = inverse ?-pi:pi;
    for(int step = 2;step <=n ; step <<=1)
    {
        double alpha = 2*PI/step;
        Complex wn(cos(alpha),sin(alpha));
        for(int k = 0;k<n;k+=step)
        {
            Complex w(1,0);
            for(int Ek = k;Ek <k+step/2;Ek++)
            {
                int Ok = Ek + step/2;
                Complex u = a[Ek];
                Complex t = a[Ok]*w;
                a[Ok] = u-t;
                a[Ek] = u+t;
                w = w*wn;
            }
        }
    }
    if(inverse)
        for(int i = 0;i<n;i++)
            a[i].x = (a[i].x/n);
}
//¾í»ý
vector <int > operator * (const bitset <maxn> &v1,const bitset<maxn> &v2)
{
    int S1 = v1.size() , S2 = v2.size();
    int S =2;
    while(S<S1+S2) S<<=1;
    vector <Complex > a(S),b(S);
    for(int i = 0;i<S;i++)
        a[i].x = a[i].y = b[i].x = b[i].y =0.0;
    for(int i = 0;i<S1;i++)
        a[i].x = v1[i];
    for(int i=0;i<S2;i++)
        b[i].x = v2[i];
    fft(a,false);
    fft(b,false);
    for(int i = 0;i<S;i++)
        a[i] = a[i] * b[i];
    fft(a,true);
    vector <int > res(S);
    for(int i= 0;i< (int) a.size();i++)
    {
        res[i] = round(a[i].x);
    }
    return res;
}

int main()
{
    return 0;
}

