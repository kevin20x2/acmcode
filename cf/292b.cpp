/*
 *File:  292b.cpp
 *Date : 2015-02-18 00:46:46
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
int n,m;
int b,g;
bool visb[110];
bool visg[110];
vector <int > v1[110];
vector <int > v2[110];
bool ans;
void dfs2(int y);
void dfs1(int x)
{
    for(int i=0;i<v1[x].size();i++)
    {
        if(!visg[v1[x][i]])
        {
            visg[v1[x][i]]=1;
            dfs2(v1[x][i]);
        }
    }
}
void dfs2(int y)
{
    for(int i =0;i<v2[y].size();i++)
    {
        if(!visb[v2[y][i]])
        {
            visb[v2[y][i]] =1;
            dfs1(v2[y][i]);
        }
    }
    
}
int main()
{
    int t;
    ans = 0;
    memset(visb,0,sizeof visb);
    memset(visg,0,sizeof visg);
    scanf("%d%d",&n,&m);
    scanf("%d",&b);
    for(int i = 0;i<b;i++)
    {
        scanf("%d",&t);
        visb[t] = true;
    }
    scanf("%d",&g);
    for(int i =0;i<g;i++)
    {
        scanf("%d",&t);
        visg[t] = true;
    }
    for(int i = 0;i<n*m;i++)
    {
        v1[i%n].push_back(i%m);
        v2[i%m].push_back(i%n);
        if(visb[i%n]||visg[i%m])
        {
            visb[i%n]=visg[i%m]=true;
        }
    }
    for(int i =0;i<n;i++) if(visb[i])
        dfs1(i);
    for(int i =0;i<m;i++) if(visg[i])
        dfs2(i);
    for(int i =0;i<n;i++)
        if(!visb[i])
        {
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}

