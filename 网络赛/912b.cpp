/*
 *File:  912b.cpp
 *Date : 2014-09-13 00:08:12
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define clr(x) memset((x),0,sizeof(x))
#define inf 6000000001
using namespace std;
long long n,a,b;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    long long  ans = inf;
    long long  ansa=0,ansb=0;
    if(6*n/a<=b)
        printf("%I64d\n%I64d %I64d\n",a*b,a,b);
    else {
        if(a<b)
        {
            for(int i=a;i<=6*n/b+1;i++)
            {
                if((6*n)%i==0)
                {
                    printf("%I64d\n%I64d %I64d\n",6*n,(long long)i,(6*n)/i);
                    return 0;
                }
                else {
                    ans = min(ans,(6*n/i+1)*i);
                    if(ans == (6*n/i+1)*i)
                    {
                        ansa = i;
                        ansb = (6*n/i+1);
                        
                    }
                }
            }
            printf("%d\n%d %d\n",ansa*ansb,ansa,ansb);
          }
        else 
        {
            for(int i=b;i<=6*n/a+1;i++)
            {
                if(6*n%i==0)
                {
                    printf("%I64d\n%I64d %I64d\n",6*n,6*n/i,(long long)i);
                    return 0;
                }
                else {
                    ans = min(ans,(6*n/i+1)*i);
                    if(ans == (6*n/i+1)*i)
                    {
                        ansa = (6*n/i+1);
                        ansb = i;
                    }
                }
            }
            printf("%I64d\n%I64d %I64d\n",ansa*ansb,ansa,ansb);

        }


    }
    return 0;
}

