/*
 *File:  neuqd.cpp
 *Date : 2014-11-29 12:19:40
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
int dp[10010];
int n;
int a[10010];
int be[10010];

int main()
{
    scanf("%d",&n);
    for(int i =1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(be,-1,sizeof(be));
    for(int i =1;i<=n;i++)
    dp[i] = 1;
    for(int i =2;i<=n;i++)
    {
        for(int j =1;j<i;j++)
        {
            if(a[i]>a[j] )
            {
                int t = dp[i];
                dp[i]= max(dp[j]+1,dp[i]); 
                if(dp[i] == dp[j] +1)
                {
                    if(dp[i] >t) be[i] = j;
                    if(be[i]==-1)
                       be[i] = j;
                    else if(be[i]==i-1||a[be[i]]==a[i]-1)
                        be[i] = j;
                }
            }
           /* else 
            {
                int t = dp[i];
                dp[i]= max(dp[j],dp[i]); 
                if(dp[i] == dp[j])
                {
                    if(dp[i] >t ) be[i] = j;
                    if(be[i]==-1)
                       be[i] = j;
                    else if(be[i]==i-1||a[be[i]]==a[i]-1)
                        be[i] = j;
                }
            }
            */
        }
    }
    int flag = 0;
    int MAX = 0;
    for(int i = 1;i<= n;i++)
    {
       // printf("%d ",dp[i]);
        MAX = max(MAX,dp[i]);
    }
    for(int i  =n ;i>=1 ;i--) if(dp[i] == MAX)
    {
        int t = i;
        while(t!=-1)
        {
           // printf("%d %d\n",t,a[t]);
            if(a[t]-a[be[t]]>1&&t-be[t]>1)
            {
                flag=1;
                break;
            }
            t= be[t];
        }
        if(flag ==0)
        {
            if(t>1&&a[t]>1)
                flag = 1;
            if(i <n &&a[i]<10000)
                flag  =1;
        }
        if(flag ) break;
    }
    printf("%d\n",MAX+flag);

    return 0;
}

