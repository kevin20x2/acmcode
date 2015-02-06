/*
 *File:  3820.cpp
 *Date : 2014-10-15 21:04:47
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

#define maxn 200010
using namespace std;
struct seg{
    int to,next;
    seg()
    {
        to = -1;
        next = -1;
    }
}edge[2*maxn];
int  head[maxn],tot;
int q[maxn],l,r;
int vis[maxn];
int vis1[maxn],vis2[maxn];
int fa[maxn];
int n;
int id[maxn];

void addedge(int u ,int v)
{
    edge[tot].to = v; 
    edge[tot].next = head[u];
    head[u] = tot++;
}
int bfs(int x)
{
    memset(vis,0x3f,sizeof(vis));
    memset(fa,-1,sizeof(fa));
    l=r=0;
    vis[x] = 1;
    q[r++] = x;
    fa[x] =-1;
    while(l!=r)
    {
        int t = q[l++];
        for(int i = head[t];i!=-1;i=edge[i].next) if(vis[edge[i].to]>vis[t])
        {
            int v = edge[i].to;
            fa[v] = t;
            vis[v] = vis[t]+1;
            q[r++] = v;
        }
        
    }
    return q[l-1];
}
void check(int x,int length,int *vis)
{
    l =r =0;
    vis[x] = 1;
    q[r++] = x;
    int size ;
    int tsize =1;
    while(length--)
    {
        size = tsize;
        tsize=0;
        for(int j = 1;j<=size;j++){
            int t = q[l++];
            for(int i = head[t];i!=-1;i=edge[i].next) if(!vis[edge[i].to])
            {
                int v = edge[i].to;
                vis[v]  =1;
                q[r++] = v;
                tsize ++;
            }
        }
    }
}
bool judge(int x,int y,int length)
{
    memset(vis1,0,sizeof(vis1));
    memset(vis2,0,sizeof(vis2));
    check(x,length,vis1);check(y,length,vis2);
    for(int i =1;i<=n;i++)
    {
        if(vis1[i]==0&&vis2[i]==0) return false;
    }
    return true;
}
void init()
{
    memset(head,-1,sizeof(head));
    memset(edge,-1,sizeof(edge));
    memset(id,0,sizeof(id));
    tot = 1;
    
}
int main()
{
    int cas;
    int x,y;
    scanf("%d",&cas);
    while(cas--)
    {
        scanf("%d",&n);
        init();
        for(int i = 1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        int first = bfs(1);
        int last = bfs(first);
        int num =0;
        for(int i =last;i!=-1;i=fa[i])
        {
            id[num++] = i;
        }
        int left = 0;int right =num/2;
        int minn =num;
        int x,y;
        int ansx,ansy;
        while(left<=right)
        {
            int mid = (left+right)/2;
            x = id[mid],y = id[num-mid-1];
            if(x == y ) y = id[num-mid];
            if(judge(x,y,mid)==true)
            {
                right = mid;
                minn = min(minn,mid);
                if(minn == mid) ansx=x,ansy = y;
                if(left==right) break;
            }
            else left = mid+1;
        }
        printf("%d %d %d\n",minn,ansx,ansy);
        
    }
    return 0;
}

