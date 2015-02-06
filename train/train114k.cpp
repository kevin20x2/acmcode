/*
 *File:  train114k.cpp
 *Date : 2014-11-14 09:17:28
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
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100010;
int n,m;
int col[maxn<<2];
int sum[maxn<<2];
void push_up(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void push_down(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1] = col[rt<<1|1] = col[rt];
        sum[rt<<1] = (m-(m>>1))*col[rt];
        sum[rt<<1|1] =(m>>1)*col[rt];
        col[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    col[rt] = 0;
    sum[rt] =0;
    if(l==r) return ;
    int m = (l+r)>>1;
    build(lson);
    build(rson);
    push_up(rt);
}
void update(int L ,int R,int c ,int l,int r,int rt)
{
    if(L<=l && r<=R)
    {
        col[rt]= c;
        sum[rt] = c*(r-l+1);
        return ;
    }
    push_down(rt,r-l+1);
    int m = (l+r)>>1;
    if(L <= m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    push_up(rt);
}
LL query(int L,int R,int l,int r,int rt)
{
    if(L<=l && r <=R)
    {
        return sum[rt];
    }
    push_down(rt,r-l+1);
    int m = (l+r) >>1;
    LL ret = 0;
    if(L<=m) ret+= query(L,R,lson);
    if(m<R) ret += query(L,R,rson);
    return ret;
}
int main()
{
    while(~scanf("%d",&n)&&n)
    {
       // build(1,n,1);
        clr(sum);clr(col);
        scanf("%d",&m);
        int l,r,d;
        for(int i =1;i<=m;i++)
        {
            scanf("%d%d%d",&l,&r,&d);
            update(l,r,d,1,n,1);
        }
        int ans = 0;
        int k = 0;
        scanf("%d",&k);
        LL x;
        for(int i=1;i<=k;i++)
        {
            scanf("%I64d%d",&x,&r);
            LL t = query(r,n,1,n,1);
            if(x>t)
                ans ++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


