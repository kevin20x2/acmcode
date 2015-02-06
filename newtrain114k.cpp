/*
 *File:  newtrain114k.cpp
 *Date : 2014-11-14 10:07:18
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
const int maxn = 100010;
int a[maxn];
int b[maxn];
int c[maxn];
int n,m;
void add_b(int x,int d)
{
    for(int i =x;i>0;i-=i&(-i)) b[i] += d;
}
void add_c(int x,int d)
{
    for(int i =x;i<=n;i+=i&(-i)) c[i] += x*d;
}
LL sum_b(int x)
{
   LL s =0;
    for(int i = x;i<=n;i+=i&(-i)) s+= 1LL*c[i];
    return s;
}
LL sum_c(int x)
{
    LL s = 0;
    for(int i = x;i>0;i-=i&(-i)) s+=1LL*c[i];
    return s;
}
LL sum(int x)
{
    if(x) return sum_b(x) *x+ sum_c(x-1);
    return 0;
}

int main()
{
    while(~scanf("%d",&n)&&n)
    {
        clr(a);clr(b);clr(c);
       scanf("%d",&m); 
       int l,r,d;
       for(int i =1;i<=m;i++)
       {
           scanf("%d%d%d",&l,&r,&d);
           add_b(r,d);add_c(r,d);
           if(l>1) {add_b(l-1,-d);add_c(l-1,-d);}
       }
       scanf("%d",&m);
       LL x;
       LL tmp = sum(n);
       int ans = 0;
       for(int i=1;i<=m;i++)
       {
           scanf("%I64d%d",&x,&r);
           LL t = tmp - sum(r-1);
           if(x>t) 
               ans ++;
       }
       printf("%d\n",ans);
    }
    return 0;
}

