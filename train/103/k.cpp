/*
 *File:  k.cpp
 *Date : 2014-10-03 13:30:48
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
#define maxn 1000000000000
#define N 100000

using namespace std;
LL n;
LL r,k;
void update(LL x, LL y)
{
    if(x*y< r*k) r= x,k=y;
    else if(x*y==r*k&&x<r) r=x,k=y;
}
LL find(LL x,LL t,bool &flag)
{
   LL ans = 1; 
   while(t>0)
   {
        t-=x;
        if(t==0)
            flag = 1;
        x= x*i;
        ans++;
   }
   return ans;
}

int main()
{
    while(~scanf("%I64d",&n))
    {
        r = 1, k =n-1;
        LL left = 1,right = n-1;
        bool flag = 0;
        while(left < right)
        {
            LL mid = (left+right)/2; 
            LL midmid = (left +mid)/2;
            if()
            
        }
        printf("%I64d %I64d\n",r,k);

    }
    return 0;
}

