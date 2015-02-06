/*
 *File:  cf1025d.cpp
 *Date : 2014-10-25 16:30:45
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
#define maxn 200050
struct seg{
    LL a;
    int c ;
    int p ;
};
int vis[maxn];
seg a[maxn];
int n;
int res[maxn];
LL m;
int cmp(seg a,seg b)
{
    if(a.a>b.a) return 1;
    else if(a.a==b.a&&a.p>b.p) return 1;
    return 0;
}

int main()
{
    scanf("%d%lld",&n,&m);
    for(int i =1;i<=n;i++)
    {
        scanf("%d%d",&a[i].a,&a[i].p);
        a[i].c = i;
    }
    sort(a+1,a+n+1,cmp);
    LL sum = 0;
    int ans = 0;
    int num = 0;
    while(sum<m)
    {
        res[++ans] = a[ans].c;
        sum += a[ans].a;
        if(a[ans].p) num++;
    }
    memset(vis,0,sizeof(vis));
    for(int i = ans;i>=1;i--) if(a[i].p==0)
    {
        for(int j =ans+1;j<=n;j++) if(a[j].p == 1&&vis[j]==0)
        {
            if(sum -a[i].a+a[j].a>=m)
            {
                sum = sum-a[i].a+a[j].a;
                vis[j] =1;
                num++;
                res[i] = a[j].c;
                break;
            }
            else {
                goto inx;
               
            }
        }
        
    }
inx:
    printf("%d %d\n",ans,num);
    int first = 1;
    for(int t =1;t<=ans;t++)
    {
        if(first)
        {
            printf("%d",res[t]);
            first = 0;
        }
        else printf(" %d",res[t]);
    }
    printf("\n");

    return 0;
}

