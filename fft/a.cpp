/*
 *File:  a.cpp
 *Date : 2015-03-15 10:54:32
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
const double pi= acos(-1.0);
const int maxn = 400040;
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

int a[maxn/4];

int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        vector <LL> num(maxn);
        vector <LL> sum(maxn);
        for(int i =0;i<n;i++)
        {
            scanf("%d",&a[i]);
            num[a[i]]++;
        }
        sort(a,a+n);
        int len1 = a[n-1]+1;
        int len =1;
        while(len<2*len1) len<<=1;
        vector <Complex> x(len);
        for(int i = 0;i<len1;i++)
            x[i] =Complex(num[i],0);
        for(int i = len1;i<len ;i++)
            x[i] = Complex(0,0);
        fft(x,0);
        for(int i = 0;i<len;i++)
            x[i] = x[i]*x[i];
        fft(x,1);
        for(int i = 0;i<len;i++)
            num[i] = (LL) (x[i].x+0.5);
        len = 2*a[n-1];
        for(int i = 0;i<n;i++)
            num[a[i]+a[i]]--;
        for(int i= 1;i<=len;i++)
        {
            num[i]/=2;
        }
        sum[0] = 0;
        for(int i = 1;i<=len;i++)
            sum[i] = sum[i-1]+num[i];
        LL cnt = 0;
        for(int i =0;i<n;i++)
        {
            cnt += sum[len] -sum[a[i]];
            cnt -= (long long )(n-1-i)*i;
            cnt -= (n-1);
            cnt -= (long long )(n-1-i)*(n-i-2)/2;
        }
        long long tot = (LL ) n*(n-1)*(n-2)/6;
        //printf("%d %d",cnt,tot);
        printf("%.7lf\n",(double)cnt/tot);
    }
    return 0;
}

