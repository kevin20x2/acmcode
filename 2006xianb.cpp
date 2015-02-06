/*
 *File:  2006xianb.cpp
 *Date : 2014-12-06 21:17:51
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
int a[10] ={6,2,5,5,4,5,6,3,7,6}; 
int dp[55][10][3010];
int n,m;
int mypow[55];
int head[55][10][3010];
int tail[55][10][3010];
void init()
{
    mypow[0] =1;
    for(int i =1;i<=50;i++)
    {
        mypow[i]= (mypow[i-1]*10)%m;
    }
}

int main()
{
    int cas = 0;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        init();
        memset(head,-1,sizeof(head));
        memset(tail,-1,sizeof(tail));
        memset(dp,0x3f,sizeof(dp));
        for(int i =0;i<=9;i++)
            dp[1][i][i%m] = a[i];
        for(int i =2;i<=50;i++)
        {
            for(int j=0;j<=9;j++)
                for(int v =0;v<m;v++)
                {
                    int t = ((j*mypow[i-1])%m+v%m)%m;
                    for(int k=0;k<=9;k++)
                    {
                        dp[i][j][t] = min(dp[i][j][t],a[j]+dp[i-1][k][v]);
                        if(dp[i][j][t] == a[j]+dp[i-1][k][v])
                        {
                            int x = head[i][j][t];
                            int y =tail[i][j][t];
                            if(x!=-1&&y!=-1)
                            {
                                if(dp[i][j][t] == a[j] + dp[i-1][x][y])
                                {
                                    if(k>x)
                                    {
                                        head[i][j][t] = k;
                                        tail[i][j][t] = v;
                                    }
                                    else {
                                        head[i][j][t] =x;
                                        tail[i][j][t] =y;
                                    }
                                }
                                else {
                                    head[i][j][t] = k;
                                    tail[i][j][t] = v;
                                }
                            }
                            else {
                                head[i][j][t] = k;
                                tail[i][j][t] = v;
                            }
                        }
                        
                    }
                }
        }

        int flag =0;
        for(int i =50;i>=1;i--)
        {
            for(int j =9;j>=0;j--) if(dp[i][j][0]<=n)
            {
                printf("Case %d: ",++cas);
                int x =i,y = j,z=0;
                while(y!=-1)
                {
                    printf("%d",y);
                    y = head[x][y][z];
                    z = tail[x][y][z];
                    x--;
                }
                printf("\n");
                flag =1;
                break;
            }
            if(flag ) break;
        }
        if(flag ==0) printf("Case %d: -1\n",++cas);
    }
    return 0;
}

