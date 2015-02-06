/*
 *File:  cf1123d.cpp
 *Date : 2014-11-23 18:17:19
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
LL a[4];
int num2[4];
int num3[4];
int re[4];
int main()
{
    clr(num2);clr(num3);
    for(int i=0;i<4;i++)
    {
        scanf("%I64d",&a[i]);
        LL t = a[i];
        while(t%2== 0)
        {
            t= t/2;
            num2[i] ++;
        }
        while(t%3==0)
        {
            t/=3;
            num3[i] ++;
        }
        re[i] = t;
    }
    int ans = 0;
    if(re[0]*re[1]==re[2]*re[3])
    {
        int sum1 = num3[0] + num3[1];
        int sum2 = num3[2]+ num3[3];
        int t1,t2;
        ans += max(sum1,sum2)-min(sum1,sum2);
        if(sum1 > sum2)
        {
            int tmp = ans;
            while(tmp--)
            {
                if(a[0]%3==0) a[0]=a[0]*2/3;
                else if(a[1]%3==0) a[1]=a[1]*2/3;
            }
            t1 = num2[0] + num2[1] +ans;
            t2 = num2[2] +num2[3] ;
            ans += max(t1,t2)-min(t1,t2);
        }
        else {
            int tmp = ans ;
            while(tmp--)
            {
                if(a[2]%3==0) a[2]=a[2]*2/3;
                else if(a[3]%3==0) a[3]=a[3]*2/3;
            }
            t1 = num2[0] + num2[1];
            t2 = num2[2] +num2[3]+ans;
            ans +=max(t1,t2)-min(t1,t2); 
        }
        if(t1>t2) 
        {
            int  t = t1-t2;
            while(t--)
            {
                if(a[0]%2==0) a[0]/=2;
                else if(a[1]%2==0) a[1]/=2;
            }
        }
        else{
            int t = t2-t1;
            while(t--)
            {
                if(a[2]%2==0) a[2]/=2;
                else if(a[3]%2==0) a[3]/=2;
            }
        } 
        printf("%d\n",ans);
        printf("%I64d %I64d\n",a[0],a[1]);
        printf("%I64d %I64d\n",a[2],a[3]);
        
    }
    else puts("-1");


    return 0;
}

