/*
 *File:  a.cpp
 *Date : 2014-09-07 12:25:42
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
struct reg{
    int w,t,c;
    void input(int i)
    {
        scanf("%d%d",&w,&t);
        c=i;
    }
};
reg a[402];
reg b[402];
stack <reg> res[402];
int n;
int T;
int q;
char vis[402];
stack <reg> re[402][200002];
stack  <reg> s;
stack  <reg> ans;
int cmp(seg a, seg b)
{
    if(a.w<b.w) return 1;
    else if(a.w==b.w&&a.t<b.t) return 1;
    else return 0;
}
void dfs(int x,int sumt,int sumw,int t,int w)
{
    if(!ans.empty())
        return ;
    vis[x]=1;
    s.push(a[i]);
    sumt+=a[x].t;
    sumw+=a[x].w;
    re[sumw][sumt]=s;
    if(sumt>=t||sumw>=t)
    {
        if(sumt==t&&sumw==w)
        {
            ans=s;
        }
        return ;
    }
    for(int i=x+1;i<=n;i++) if(!vis[i])
    {
        dfs(i,t,w);
        sumt-=a[x].t;
        sumw-=a[x].w;
        s.pop();
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
            a[i].input(i);
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=q;i++)
            b[i].input(i);
        sort(b+1,b+q+1,cmp);
        for(int i=q;i>=1;i--)
        {
            while(!ans.empty()) ans.pop();
            if(!re[i][j].empty())
            
        }
        
    }

    return 0;
}

