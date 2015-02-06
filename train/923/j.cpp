/*
 *File:  j.cpp
 *Date : 2014-09-24 17:01:01
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

#define mod 1000000007
using namespace std;
LL an[4000050];
int T;
int n;
int str[2];
int l,r,a,b,c,d;
const LL N = 1000001;
LL lowbit(LL x)
{
    return x&(x^(x-1));
}
void add(LL x,LL  d)
{
    while(x<=N)
    {
        an[x]=an[x]+d;
        x+=lowbit(x);
    }
}
LL sum(LL x)
{
    LL ans = 0;
    for(;x;x-=lowbit(x))
    {
        ans=(ans+an[x]);
    }
    return (ans+mod)%mod;
}

LL f(int x,int a,int b,int c,int d)
{
    return (((1LL*a*x%mod)*((1LL*x*x)%mod))%mod+((1LL*b*x)%mod*x)%mod+1LL*c*x+d+mod)%mod;
}
LL minn(LL a , LL b)
{
    return b>a?a:b;
}
LL maxn(LL a,LL b)
{
    return a>b?a:b;
}


int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        printf("Case #%d:\n",cas);
        clr(an);
        scanf("%d",&n);
        while(n--)
        {
           scanf("%s",str); 
           if(str[0]=='p')
           {
               scanf("%d%d%d%d%d%d",&l,&r,&a,&b,&c,&d);
               for(LL i=l;i<=r;i++)
               {
                   LL t = f(i,a,b,c,d);
                   add(i+1,t);
               }
           }
           else {
               scanf("%d%d%d%d%d%d",&l,&r,&a,&b,&c,&d);
               LL e = (sum(r+1)-sum(l)+mod)%mod;
               printf("%I64d\n",e);
               LL  r1=(1LL*((l)%1000000)*(e%1000000))%1000000;
               LL  r2=(1LL*((r)%1000000)*(e%1000000))%1000000;
               for(LL i=minn(r1,r2);i<=maxn(r1,r2);i++)
               {
                   //printf("ceshi\n");
                   LL t = f(i,a,b,c,d);
                   add(i+1,t);
               }
            
           }
        }
        
    }
    return 0;
}

