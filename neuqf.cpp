/*
 *File:  neuqf.cpp
 *Date : 2014-11-29 10:54:07
 */

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
typedef  long long LL;
using namespace std;
int s[10005];
int lis(int a[],int n)
{
    int h[10005];
        h[0] = -1;
        h[1] = a[0];
        int len = 1;

        for(int i = 1; i < n; i++)
        {
            int index = lower_bound(h,h+len+1,a[i])-h;
            h[index] = a[i];
            if(index > len)
                len = index;
        }
        return len;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);

    }
   // printf("%d\n",lis(s,n));
    int maxn=0,ans=0,ans1,ans2,ans3;
    for(int i=0;i<n;i++)
    {
        ans1=lis(s,n);
   // printf("ans1=%d\n",ans1);
        int pp;
        if(i!=0&&s[i]<=s[i-1])
        {
            pp=s[i];
            s[i]=s[i-1]+1;
            ans2=lis(s,n);

   // printf("ans2=%d\n",ans2);
            s[i]=pp;
            if(ans2>ans1&&ans2>ans)
                {
ans=ans2;maxn=i;
                }
        }
        if(s[i]>=s[i+1])
        {
            pp=s[i];
            s[i]=s[i+1]-1;
            ans3=lis(s,n);

   // printf("ans3=%d\n",ans3);
            s[i]=pp;
            if(ans3>ans&&ans3>ans1)
            {
                ans=ans3,maxn=i;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

