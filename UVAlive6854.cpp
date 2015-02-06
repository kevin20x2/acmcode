/*
 *File:  UVAlive6854.cpp
 *Date : 2014-12-21 14:34:08
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
int g[505][505];
int n,m;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        int sum =0;
        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&g[i][j]);
                if(g[i][j]==-1) g[i][j]=0;
                if((i+j)&1) g[i][j]=-g[i][j];
                sum += g[i][j];
            }
        }
        if(sum>0)
        printf("%d\n",sum);
        else printf("%d\n",-sum);
        
    }
    return 0;
}

