/*
 *File:  b.cpp
 *Date : 2015-03-08 13:26:02
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
const int maxn = 10010;
struct seg {
    int v;
    LL l;
    seg(int _v,LL _l):v(_v),l(_l){};
};
vector <seg > v[maxn];
int n,m;
LL ans ;
LL dist[maxn];
bool inque[maxn];
bool vis[maxn];
void spfa()
{
    memset(dist, 0x7f,sizeof dist);
    memset(inque,0,sizeof inque);
    dist[n-1]=0;
    queue <int>q;
    q.push(n-1);
    inque[n-1]=true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i<v[u].size();i++)if(dist[u]+v[u][i].l<dist[v[u][i].v]){
            dist[v[u][i].v] = dist[u]+v[u][i].l;
            if(!inque[v[u][i].v])
            {
                inque[v[u][i].v] = true;
                q.push(v[u][i].v);
            }
            
        }
        inque[u] = false;
    }
    
}
void get(int x)
{
    if(x==n-1) return ;
    LL len = dist[x];
    for(int i=0;i<v[x].size();i++)
    {
        if(dist[v[x][i].v]==len-v[x][i].l) 
        {
            ans += v[x][i].l;
            if(!vis[v[x][i].v])
            {
                vis[v[x][i].v]=1;
                get(v[x][i].v);
            }
        }
        
    }
    
}

int main()
{

    int x,y,l;
    while(~scanf("%d%d",&n,&m))
    {
        ans =0;
        for(int i = 0;i<=n;i++)
            v[i].clear();

        for(int i =0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&l);
            v[x].push_back(seg(y,l));
            v[y].push_back(seg(x,l));
        }
         spfa();
         memset(vis,0,sizeof vis);
         get(0);
        cout<<ans*2<<endl;
    }
   
    return 0;
}

