/*
 *File:  2012tianjingb.cpp
 *Date : 2014-10-19 10:06:35
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
#define maxn 1000000
char str[20]={"0123456789ABCDEF"};
int n,m;
int a[maxn];
int b[maxn];
int num[17];
int tot;
int s[maxn],l,r;
void factor()
{
   int temp ,i ,now;
   temp =(int) ((double )sqrt(n)+1);
   tot = 0;
   now =n;
   for(i =2;i<=temp;i++) if(now%i==0)
   {
        a[++tot]  = i;
        b[tot] = 0;
        while(now%i==0){
            ++b[tot];
            now/=i;
        }
   }
   if(now!=1){
        a[++tot] = now;
        b[tot] =1;
   }
}
void transform(int x)
{
    l=r=0;
    while(x)
    {
       s[r++]=x%m ;
       num[x%m]++;
       x/=m;
    }
}
void get(int ans,int dep)
{
    if(dep==tot+1)
    {
        transform(ans);
        return ;
    }
    for(int i =0;i<=b[dep];i++)
    {
        get(ans*(int)pow((double)a[dep],i),dep+1);
    }
    
}
void init()
{
    tot = 0;
    clr(a);
    clr(b);
    clr(num);
}



int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        factor();
        get(1,1);
        LL ans =0;
        for(int i=1;i<=m;i++)
        {
            ans += 1LL*num[i]*i*i;
        }
        l=r = 0;
        while(ans)
        {
            s[r++] = ans%m;
            ans/=m;
        }
        while(r!=l)
        {
            putchar(str[s[--r]]);
        }
        putchar('\n');

        
    }
    return 0;
}

