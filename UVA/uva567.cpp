/*
 *File:  uva567.cpp
 *Date : 2014-11-11 14:18:44
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
#define maxn 25
int g[maxn][maxn];

using namespace std;

int main()
{
    int cas;
    int n;
    int tt=0;
    int x,y;
    while(~scanf("%d",&n))
    {
        memset(g,0x3f,sizeof(g));
        printf("Test Set #%d\n",++tt);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            g[1][x] = 1;
            g[x][1] = 1;
        }
        for(int i= 2;i<=19;i++)
        {
            scanf("%d",&n);
            for(int j= 1;j<=n;j++) 
            {
                scanf("%d",&x);
                g[i][x] = 1;
                g[x][i] = 1;
            }
        }
        for(int k=1;k<=20;k++)
            for(int i =1;i<=20;i++)
                for(int j =1;j<=20;j++)
                    g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            printf("%2d to %2d: %d\n",x,y,g[x][y]);
            

        }
        printf("\n");
    }
    return 0;
}

