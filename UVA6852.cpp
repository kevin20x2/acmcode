/*
 *File:  UVA6852.cpp
 *Date : 2014-12-21 13:43:20
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
int a[1000050];
int num[100050];
int g[17][17];
int n,m;

int main()
{
    int T;
    scanf("%d",&T);
    int x,y;
    while(T--)
    {
        memset(num,0,sizeof num);
        memset(a,0,sizeof a);
        memset(g,0,sizeof g);
        scanf("%d%d",&n,&m);
        for(int i =1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            g[x][y] ++;
        }
        for(int i =1;i<=16;i++)
            for(int j =1;j<=16;j++) if(g[i][j]>0)
            {
                for(int k= 0;;k++)
                {
                    if(k*j>=m) break; 
                    a[k*j] += g[i][j];
                    if(k*j+i>=m) break;
                    a[k*j+i] -= g[i][j]; 
                }
            }
        for(int i =1;i<m;i++)
            a[i] += a[i-1];
        for(int i =0;i<m;i++)
            num[a[i]]++;
        for(int i =0;i<=n;i++)
            printf("%d\n",num[i]);
        
    }
    return 0;
}

