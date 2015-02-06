/*
 *File:  zoj2563.cpp
 *Date : 2014-12-08 15:06:22
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
int n,m;
LL dp[32][200000];
int pp[10];
int num[10];
int row,znt;
int imax;

void dfs(int pos,int stat)
{
    if(pos==n)
    {
        dp[row+1][stat] += dp[row][znt];
        return ;
    }
    if(num[pos]== 0)
    {
        if(pos+2<n&&num[pos+1]==0&&num[pos+2]==0) dfs(pos+3,stat);
        dfs(pos+1,stat+2*pp[pos]);
    }
    else if(num[pos] == 1)
    {
        dfs(pos+1,stat);
    }
    else {
        dfs(pos+1,stat+pp[pos]);
    }
}
void change()
{
    int tmp = znt;
    for(int i =0;i<n;i++)
    {
        num[i] = tmp%3;
        tmp = tmp/3;
    }

}

int main()
{
    pp[0] = 1;
    for(int i =1;i<=9;i++) pp[i] =pp[i-1]*3;
    imax = pp[9];
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]= 1;
        for(row = 0;row<=m-1;row++)
        {
            for(znt=0;znt<imax;znt++)
            {
                change();
                dfs(0,0);
                
            }
        }
        printf("%lld\n",dp[m][0]);
        
    }
    return 0;
}

