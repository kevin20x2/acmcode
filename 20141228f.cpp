/*
 *File:  20141228f.cpp
 *Date : 2014-12-28 14:44:22
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

char str[3][1000010];
int dp[1000010][2][2];
int main()
{
    int  T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i =0;i<3;i++)
            scanf("%s",&str[i][1]);
        int maxlen = max(strlen(&str[0][1],&str[1][1]));
        dp[0][0][0] =1;dp[0][1][1]=1;
        dp[0][1][0] =1;dp[0][0][1] =1;
        for(int i = 1;i<=maxlen;i++)
        {
            if(str[0][i]=='?'&&str[1][i]!='?')
            {
                if(str[2][i]=='?')
                {
                    dp[i][1][1] = dp[i-1][1][1];
                    dp[i][1][0] = dp[i-1][1][0]*26+dp[i-1][1][1]*('z'-str[1][i]);
                    dp[i][0][1] = dp[i-1][1][1]*(str[1][i]-'a')+dp[i-1][0][1]*26;
                    dp[i][0][0] = dp[i-1][1][1]*(str[1][i]-'a')*('z'-str[1][i]);
                    dp[i][0][0] += dp[i-1][1][0]*(str[1][i]-'a')*26+dp[i-1][0][1]*('z'-str[1][i])*26;
                    dp[i][0][0] +=dp[i-1][0][0]*26*26;
                }
                else {
                    dp[i][1][1] =dp[i-1][1][1];
                    dp[i][1][0] =(str[1][i]==str[2][i]?dp[i-1][1][1]:0)+ dp[i-1][1][0]
                    
                }
            }
            else if(str[0][i]=='?'&&str[1][i]=='?')
            {
                dp[i][1] =dp[i-1][1]*26;
                dp[i][0] = dp[i-1][1]*26*25/2+dp[i-1][0]*26*26;
            }
            else if(str[0][i]!='?'&&str[1][i]=='?')
            {
                dp[i][1] = dp[i-1][1];
                dp[i][0] = dp[i-1][1]*('z'-str[0][i])+dp[i-1][0]*26;
            }
            else if(str[0][i]!='?'&&str[1][i]!='?')
            {
                if(str[0][i]!=str[1][i])
                {
                    dp[i][1] = 0;
                    dp[i][0] = dp[i-1][1]+dp[i-1][0];
                }
                else 
                { 
                    dp[i][1] = dp[i-1][1];
                    dp[i][0] = dp[i-1][0];
                }
            }
            
        }
    }
    return 0;
}

