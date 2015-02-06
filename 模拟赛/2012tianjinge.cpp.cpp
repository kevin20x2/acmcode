/*
 *File:  2012tianjinge.cpp.cpp
 *Date : 2014-10-19 13:50:23
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
int n,d;
double x[130];
double y[130];
int num[130];
vector <int> v[130];
vector <int > gh[130];
int g[130][130];
int ans[130];
int fa[130];
int vis[130];
int dist(int a,int b)
{
    return ceil(sqrt(1.0*(x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b])));
}
void dfs(int x)
{
    for(int i=0;i<gh[x].size();i++) if(ans[gh[x][i]]&&!vis[gh[x][i]])
    {
        vis[gh[x][i]]=1;
        fa[gh[x][i]]=1;
        dfs(gh[x][i]);
        
    }

}
bool judge()
{
    for(int i =1;i<=n;i++)
        if(num[i]==0) return false ;
    clr(fa);
    fa[1]=1;
    clr(vis);
    dfs(1);
    for(int i =1;i<=n;i++) if(ans[i])
    {
        if(fa[i]==0) return false;
    }
    return true;
}

int main()
{
    while(~scanf("%d%d",&n,&d))
    {
        clr(num);
        clr(ans);
        for(int i =1;i<=n;i++)
            v[i].clear();
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&x[i],&y[i]);
        for(int i=1;i<=n;i++)
        {
            v[i].push_back(i);
            for(int j =1;j<=n;j++) if(j!=i&&dist(i,j)<=d)
            {
                v[i].push_back(j);
            }
        }
        for(int i =1;i<=n;i++)
        {
           for(int j=1;j<=n;j++) 
           {
                for(int t=0;t<v[i].size();t++)
                    if(find(v[j].begin(),v[j].end(),v[i][t])!=v[j].end())
                    {
                        g[i][j]=1;
                        gh[i].push_back(j);
                        break;
                    }
           }
        }
        int t =1;
        while(t<=n)
        {
            for(int i=0;i<v[t].size();i++)
                num[v[t][i]]++;
            ans[t] =1;
            if(judge()) break;
            t++;
        }
        printf("**%d",t);
        if(t==n+1) 
        {
            printf("-1\n");
            continue;
        }
        putchar('1');
        for(int i = t-1;i>1;i--)
        {
            for(int j=0;j<v[i].size();j++)
                num[v[i][j]]--;
            if(judge()) putchar('0');
            else 
            {
                putchar('1');
                for(int j =0;j<v[i].size();j++)
                    num[v[i][j]]++;
            }
        }
        putchar('1');
        puts("");
    }
    return 0;
}

