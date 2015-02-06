/*
 *File:  20141213a.cpp
 *Date : 2014-12-18 14:23:20
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;
#define N 1200
#define M 4020
int vis[N];
int counts[N];
int head[N];
int vi[M];
int next[M];
int w[M];
bool inque[N];
int n,m;
int tot;
void add(int u,int v,int c)
{
    vi[++tot] = v;
    w[tot] = c;
    next[tot] = head[u];
    head[u]  = tot;
}
bool spfa()
{
    queue <int> q;
    memset(vis,0x3f,sizeof vis); 
    memset(counts,0,sizeof counts);
    memset(inque,0,sizeof inque);
    q.push(0);
    vis[0] = 0;
    counts[0]++;
    inque[0] = true;
    while(!q.empty())
    {
        int t = q.front();
        q.pop(); inque[t] = false ;
        for(int i = head[t];~i;i= next[i])
        {
            int v = vi[i];
            int wi = w[i];
            if(vis[v] > vis[t] + wi)
            {
                vis[v] = vis[t] +wi;
                if(vis[0]<0) return true;
                if(!inque[v])
                {
                    counts[v]++;
                    if(counts[v]==n) 
                    {
                        vis[v] = -inf;
                        if( v== 0) return true;
                    }
                    else if(counts[v]>n) continue;
                    inque[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return false ;
}

int main()
{
    int T;
    int x,y,z;
    int cas = 0;
    scanf("%d",&T);
    while(T--)
    {
        memset(head,-1,sizeof head);
        tot = 0;
        scanf("%d%d",&n,&m);
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,z);
        }
        printf("Case #%d: ",++cas);
        if(spfa())
            puts("possible");
        else puts("not possible");

        
    }
    return 0;
}

