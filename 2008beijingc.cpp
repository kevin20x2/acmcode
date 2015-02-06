/*
 *File:  2008beijingc.cpp
 *Date : 2014-11-01 14:35:53
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
char g[110][110];
int x[27];
int y[27];
int rx[27];
int ry[27];
bool rect(int u)
{
    char c =(char)(u+'A');
    int down = x[u];
    int right = y[u];
    while(g[down][right]==c) 
    {
        down++;
    }
    down--;
    if(g[down][right+1]!=c) return false ;
    while(g[down][right]==c)
    {
        right ++;
    }
    right--;
    rx[u] = down;
    ry[u] = right;
    if(g[down-1][right]!=c) return false ;
    while(g[down][right]==c)
    {
        down --;
    }
    down ++;
    if(g[down][right-1]!=c) return false ;
    while(g[down][right]==c)
    {
        right --;
    }
    right ++;
    if(down == x[u]&&right ==y[u])
        return true;
    return false;
}
bool empty(int u)
{
    for(int i =x[u]+1;i<=rx[u]-1;i++)
        for(int j =y[u]+1;j<=ry[u]-1;j++)
            if(g[i][j]!='.') return false ;
    return true;
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n*m)
    {
        clr(x);
        clr(rx);
        clr(ry);
        clr(y);
        for(int i =1;i<=n;i++)
        {
            scanf("%s",&g[i][1]);
            for(int j =1;j<=m;j++)
            {
                if(g[i][j]!='.'&&x[(int )(g[i][j]-'A')]==0)
                {
                    x[(int )(g[i][j]-'A')]= i;
                    y[(int )(g[i][j]-'A')] = j;
                }
            }
        }
        for(int i =0;i<26;i++)
        {
            if(x[i]!=0)
            {
               // printf("%c %d %d\n",(char)(i+'A'),x[i],y[i]);
                if(rect(i)&&empty(i))
                    putchar((char)(i+'A'));
            }
            
        }
        putchar('\n');
    }
    return 0;
}

