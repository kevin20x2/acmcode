/*
 *File:  timus2034.cpp
 *Date : 2014-10-27 22:48:59
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
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
#define maxn 100010
struct seg{
    int v,next;
}edge[maxn<<2];
int tot;
int head[maxn];

int q[maxn<<6],l,r;
int ro[maxn];
int inque[maxn];
int r2[maxn];
int minn[maxn];
int n ,m;
int s,f,ri;
void addege(int u ,int v)
{
    edge[++tot].v =v;
    edge[tot].next = head[u];
    head[u] = tot;
}
void bfs1(int x)
{
    l=r = 0;
    memset(ro,0x3f,sizeof(ro));
    memset(inque,0,sizeof(inque));
    q[r++] = x;
    inque[x] = 1;
    ro[x] = 0;
    while(l!=r)
    {
        int t = q[l++];
        inque[t] = 0;
        for(int i =head[t];~i;i=edge[i].next) 
        {
            int v = edge[i].v;
            if(ro[v]>ro[t]+1)
            {
                ro[v] = ro[t] +1;
                if(!inque[v])
                {
                    q[r++] = v;
                    inque[v]=1;
                }

            }
        }
        
    }
}
void bfs2(int x)
{
    l=r = 0;
    memset(r2,0x3f,sizeof(r2));
    for(int i =1;i<=n;i++)
        minn[i] = ro[i];
    q[r++] = x;
    r2[x] = 0;
    while(l!=r)
    {
        int t = q[l++];
        for(int i =head[t];~i;i=edge[i].next) 
        {
            int v = edge[i].v;
            if(r2[v]>r2[t]+1)
            {
                r2[v] = r2[t]+1;
                minn[v] = min(ro[v],minn[t]);
                q[r++] =v;
            }
            else if(r2[v]==r2[t]+1)
            {
                int tmp = min(ro[v],minn[t]);
                minn[v] =max(minn[v],tmp);
            }
        }
    }
    
}



int main()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i =1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        addege(x,y);addege(y,x);
    }
    scanf("%d%d%d",&s,&f,&ri);
    bfs1(ri);
    bfs2(s);
    printf("%d\n",minn[f]);
    return 0;
}

