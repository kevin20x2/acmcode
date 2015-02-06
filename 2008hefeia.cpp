/*
 *File:  2008hefeia.cpp
 *Date : 2014-11-09 13:01:20
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
#define maxn 30010
int n,t;
int a[maxn],la,ra;
int b[maxn],lb,rb;
int gcd (int a,int b)
{ 
    return b==0?a:gcd(b,a%b);
}
int cmp(int a,int b)
{
    return (int)(fabs(a))<(int )fabs(b);
}

int main()
{
    int tt=0;
    while(~scanf("%d%d",&n,&t)&&!(n==0&&t==0))
    {
        int x;
        la=ra=lb=rb=0;
        for(int i =1;i<=n;i++)
        {
            scanf("%d",&x);
            if(x>=0)
                a[ra++] =x;
            else b[rb++] =-x;
        }
        int sum =0;
        sort(a,a+ra,cmp);
        sort(b,b+rb,cmp);
        if(t>=0)
        {
            for(int i =0;i<ra;i++)
            {
                if(a[i]==0) continue;
                sum += (a+ra-upper_bound(a,a+ra,t/a[i]));
            }
            for(int i =0;i<rb;i++)
            {
                sum += (b+rb-upper_bound(b,b+rb,t/b[i]));
            }
        }
        else {
            sum+= ra*ra+rb*rb;
            for(int i=0;i<rb;i++)
            {
                if((-t)%b[i]==0)
                sum += 2*(lower_bound(a,a+ra,(-t)/b[i])-a);
                else sum+= 2*(upper_bound(a,a+ra,(-t)/b[i])-a);
            }
        }
        if(sum==0)
            printf("Case %d: 0/1\n",++tt);
        else
        printf("Case %d: %d/%d\n",++tt,sum/gcd(sum,n*n),n*n/(gcd(sum,n*n)));

    }
    return 0;
}

