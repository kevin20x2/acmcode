/*
 *File:  hdu5133.cpp
 *Date : 2014-12-05 23:01:16
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
#define eps 1e-9
char str[12];
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int cas =0;
    while(~scanf("%s",str))
    {
        double a;
        int k = strlen(str) - 2;
        sscanf(str,"%lf",&a);
        LL y = (LL )pow(10.0,k+1);
        LL x = (LL)(a*y);
        printf("%lld %lld",x,y);
        int ans = inf;
        int ans2 = 0;
        for(int i = -5;i<=4;i++)
        {
            LL t = gcd(x+i,y);
            double l = sqrt((x+i)/t);
            double r = sqrt(y/t);
            //printf("%f %f\n",l,r);
            if(l -(int)l<eps&&r -(int)r<eps&&(int )l<ans)
            {
                ans = (int)l;
                ans2 = (int)r;
            }
        }
        printf("Case #%d: %d/%d\n",++cas,ans,ans2);

    }
    return 0;
}

