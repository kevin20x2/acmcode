/*
 *File:  uva10405.cpp
 *Date : 2014-10-23 13:14:56
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
char str1[1010];
char str2[1010];
int dp[1010][1010];

int main()
{
    while(gets(&str1[1]))
    {
        gets(&str2[1]);
        clr(dp);
        for(int i =1;i<=strlen(&str1[1]);i++)
        {
            for(int j =1;j<=strlen(&str2[1]);j++)
            {
                if(str1[i]==str2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("%d\n",dp[strlen(&str1[1])][strlen(&str2[1])]);
        
    }

    return 0;
}

