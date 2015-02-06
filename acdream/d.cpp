/*
 *File:  d.cpp
 *Date : 2014-10-01 12:34:49
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
#define maxn 10005

using namespace std;

int g[maxn][maxn];
int co[maxn][maxn];
int n,m;
int x,y;

int main()
{
    clr(g);
    scanf("%d%d",&n,&m);
    loop(i,1,m)
    {
        scanf("%d%d",&x,&y);
        g[x][y]=1;
        g[y][x]=1;
    }
    int ans = 0;
    loop(i,1,n)
    {
        loop(j,1,n)
        {
            
        }
       
    }
    return 0;
}

