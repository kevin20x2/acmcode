/*
 *File:  my.cpp
 *Date : 2014-09-30 16:15:43
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
#define maxn 100000000

using namespace std;

vector <int > g[maxn];
int siz[maxn];
int dep[maxn];
int top[maxn];
int fa[maxn];
int son[maxn];
int w[maxn];  

int dfs_1(int x)
{
    siz[x] = 1; son[v] = 0 ;
    if(g[x].size() == 0)
        return siz[x] = 0;
    int  tson = -1;
    for(int i = 0;i<g[x].size();i++)
    {
        fa[g[x][i]] = x;
        dep[g[x][i]] = dep[x]+1;
        int t = dfs_1(g[x][i]);
        siz[x] += t+1;
        tson = max(tson,t);
        if(son == t)
            son[x] = g[x][i];
        
    }
    
    return siz[x] ;
}


int main()
{
    return 0;
}

