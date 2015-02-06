/*
 *File:  2012hangzhouk.cpp
 *Date : 2014-10-26 13:41:14
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
#define maxn 5000
struct edge{
    int x,y;
    double w;
    edge(int x =0 ,int y =0 ,double w=0 ):x(x),y(y),w(w){}
}e[maxn];
int fa[maxn];
int x[55];
int y[55];
int nike,apple;
int n,m;
int getfather(int x)
{
    if(x == fa[x]) return x;
    else return fa[x] = getfather(fa[x]);
}
double dist(int a,int b )
{
    return sqrt(pow((double)(x[a]-x[b]),2)+pow((double)(y[a]-y[b]),2));
}


int cmp(edge a,edge b)
{
    return a.w<b.w;
}
double kruscal()
{
    sort(e+1,e+m+1,cmp);
    int cnt = n;
    for(int i =1;i<=n;++i) fa[i] = i;
    fa[nike] = fa[apple];
    double ans  = dist(nike,apple);
    for(int i =1;i<=m;++i) {
        int  t1 = getfather(e[i].x);
        int t2 = getfather(e[i].y);
        if(t1!=t2)
        {
            fa[t1] =t2;
            ans+= e[i].w;
            if(cnt ==1) break;
        }
    }
    return ans;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d%d",&nike,&apple);
        for(int i =1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        m = 0;
        for(int i =1;i<=n;i++)
            for(int j =i+1;j<=n;j++)
                e[++m] = edge(i,j,dist(i,j));
        double ans = kruscal(); 
        printf("%.2f\n",ans);
    }
    
    return 0;
}

