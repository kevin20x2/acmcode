/*
 *File:  10141228c.cpp
 *Date : 2014-12-28 13:28:34
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

int main()
{
    int T;
    int x;
    scanf("%d",&T);
    while(T--)
    {
        int flag =1;
        scanf("%d",&x);
        for(int i =2;i*(i-1)/2<x;i++)
        {
            int t = i*(i-1)/2;
            if((x-t)%i==0)
            {
                int res = (x-t)/i;
                printf("%d =",x);
                int first = 1;
                for(int j=0;j<i;j++)
                {
                    if(first)
                    {
                        printf(" %d",res+j);
                        first = 0;
                    }
                    else printf(" + %d",res+j);
                }
                printf("\n");
                flag =0;
                break;
            }
            
        }
        if(flag) puts("IMPOSSIBLE");
    }
    return 0;
}

