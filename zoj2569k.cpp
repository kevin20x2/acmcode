/*
 *File:  zoj2569k.cpp
 *Date : 2014-12-11 14:38:20
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
struct seg{
    int e,t;
    int c;
    seg()
    {
        e = -1;t = -1;
        c=0;
    }
}g[20][20];
int I[20],A[20],L[20],O[20];
int T[20],Z[20],V[20],C[20];
int m,n,t,l;
int p[20];
int vis[20];
int num[20];
int pe[20];
int ans[20];
int res;
int cmp(seg a,seg b)
{
    if(a.e<b.e) return 1;
    else if(a.e==b.e&&a.t<b.t) return 1;
    else return 0;
}
void count()
{
    memset(num,0,sizeof(num));
    memset(pe,0,sizeof(pe));
    for(int i = 1;i<=t;i++)
    {
        int remain = l;
        for(int j= 1;j<=m;j++) if(vis[j])
        {
            if(remain>=g[i][j].t) {
                num[i] ++;
                pe[i] += g[i][j].t;
                remain-= g[i][j].t;
            }
        }
    }
    int rank = 0;
    for(int i = 2;i<=t;i++) 
    {
        if(num[i]>num[1])
            rank ++;
        else if(num[i]==num[1]&&pe[i]<pe[1])
        {
            rank ++;
        }
    }
    if(rank <=res)
    {
        res = rank;
        for(int i =1;i<=n;i++)
            ans[i] = p[i];
    }
}
void dfs(int no,int dep)
{
    p[dep] = no;
    vis[no] = 1;
    if(dep == n)
    {
        count();
        return ;
    }
    for(int i = no+1;i<=m-n+dep+1;i++)
    {

        dfs(i,dep+1);
    }
    vis[no] = 0;
    p[dep] = 0;
}

int main()
{
    res = inf;
    scanf("%d%d%d%d",&m,&n,&t,&l);
    for(int i =1;i<=m;i++)
    {
        scanf("%d%d%d%d",&I[i],&A[i],&L[i],&O[i]);
    }
    for(int i =1;i<=t;i++)
    {
        scanf("%d%d%d%d",&T[i],&Z[i],&V[i],&C[i]);
    }
    for(int j =1;j<=t;j++) 
    {
        for(int i =1;i<=m;i++) if(T[j]+C[j]>I[i]-O[i])
        {
            g[j][i].e = ceil(1.0*I[i]/O[i])+max((int)ceil(1.0*A[i]/C[i]),5);
            g[j][i].t =  max(I[i]-T[j],0)+(int)ceil(1.0*A[i]/(Z[j]+C[j]))+(int)ceil(1.0*L[i]/V[j]);
            g[j][i].c = i;
        }
        sort(g[j]+1,g[j]+m+1,cmp);
    }
    memset(vis,0,sizeof(vis));
    memset(p,0,sizeof(p));
    dfs(0,0);
    int first = 1;
    for(int i =1;i<=n;i++)
    {
        if(first)
        {
            printf("%d",ans[i]);
            first = 0;
        }
        else printf(" %d",ans[i]);
        
    }
    return 0;
}

