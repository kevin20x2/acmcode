/*
 *File:  913clone.cpp
 *Date : 2014-09-13 14:46:46
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define MOD 1000000007
using namespace std;

int T;
int n;
int minn;
int x;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        minn = inf;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            minn=min(minn,x);
        }
        if(n==1)
        {
            printf("1\n");
        }
        else {
           long long ans = (((long long)(2+minn*(n-2)))*(minn+1)/2+MOD)%MOD; 
           printf("%I64d\n",ans);
        }
    }

    return 0;
}

