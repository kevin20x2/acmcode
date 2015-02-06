/*
 *File:  20141213e.cpp
 *Date : 2014-12-13 15:35:43
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
#define maxn 5050
struct seg{
    int h,v,next;
}edge[20020<<1];
int head[maxn];
int num[maxn];
int tot;
void addedge(int u,int v )
{
    edge[++tot].v = v;
    edge[tot].h = u;
    edge[tot].next = head[u];
    head[u] = tot;
}
int n,m;
int now;
LL ans1,ans2,ans3;
bool g[5100][5100];
int T;
int main()
{
    scanf("%d",&T);
    int x,y;
    int cas = 0;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        tot = 0;
        memset(head,-1,sizeof(head));
        memset(num,0,sizeof(num));
        ans1=ans2=ans3=0;
        memset(g,0,sizeof(g));
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);addedge(y,x);
            num[x]++;num[y]++;
            g[x][y]=g[y][x] =1;
        }
        for(int i =1;i<=n;i++)
        {
            int t = num[i];
            ans1 += 1LL*t*(t-1)/2;
            ans2 += 1LL*t*(n-t-1);
            ans3+= 1LL*(n-t-1)*(n-t-2)/2;
        }
        LL sum = 0;
            for(int i =1;i<=m;i++)
            {
                int u = edge[2*i].h;
                int v = edge[2*i].v;
                if(u>v)  swap(u,v);
                for(int j = 1;j<u;j++)
                if(g[u][j]==1&&g[v][j]==1)
                    sum++;
            }
        LL ans = (ans1+ans2+ans3)/3-ans2/2-sum;
        printf("Case #%d: %lld\n",++cas,ans);
                  
    }

    return 0;
}

