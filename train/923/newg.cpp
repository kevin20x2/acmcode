/*
 *File:  newg.cpp
 *Date : 2014-09-23 19:06:16
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
    int l,r;
    int maxn,minn;

};
struct tree{
    int l,r;
    int maxn,minn;
    seg t[802<<2];
} tt[802<<2];
int a[802<<1][802<<1];
int T;
int n;
int q;
void seg_build(int l,int r,int x,int idx)
{
    tt[idx].t[x].l=l;
    tt[idx].t[x].r=r;
    tt[idx].t[x].maxn = -inf;
    tt[idx].t[x].minn = inf;
    if(l==r) {
        tt[idx].t[x].minn = a[idx][l];
        tt[idx].t[x].maxn = a[idx][l];
        return ;
    }
    int mid = (l+r)/2;
    seg_build(l,mid,x*2,idx);
    seg_build(mid+1,r,x*2+1,idx);
}
void build(int l,int r,int subl,int subr,int idx)
{
    tt[idx].l = l ,tt[idx].r =r;
    seg_build(subl,subr,1,idx);
    if(l==r) return ;
    int mid=(l+r)/2;
    build(l,mid,subl,subr,idx*2);
    build(mid+1,r,subl,subr,idx*2+1);
}
void sub_update(int l,int r, int maxn,int minn,int subidx,int idx)
{
    seg & p =tt[idx].t[subidx];
    p.maxn= max(p.maxn,maxn);
    p.minn= min(p.minn,minn);
    if(p.l==p.r) return ;
    int mid = (p.l+p.r)/2;
    if(r <= mid)
        sub_update(l,r,maxn,minn,subidx*2,idx);
    else if(l>mid) sub_update(l,r,maxn,minn,subidx*2+1,idx);
    else{
        sub_update(l,mid,maxn,minn,subidx*2,idx);
        sub_update(mid+1,l,maxn,minn,subidx*2+1,idx);
    }
   
}
void update(int l,int r,int subl,int subr,int maxn,int minn,int idx)
{
    if(tt[idx].l>=l&&tt[idx].r <=r)
    {
        sub_update(subl,subr,maxn,minn,1,idx);
        return ;
    }
    int mid = (tt[idx].l+tt[idx].r)/2;
    if( r<=mid)
        update(l,r,subl,subr,maxn,minn,idx*2);
    else if(l>mid) update(l,r,subl,subr,maxn,minn,idx*2+1);
    else {
        update(l,mid,subl,subr,maxn,minn,idx*2);
        update(mid+1,r,subl,subr,maxn,minn,idx*2+1);
    }
}
seg sub_get(int l,int r,int subidx,int idx)
{
    seg &p = tt[idx].t[subidx];
    seg t;
    if(p.l >= l&&p.r<=r)
    {
        t.maxn = p.maxn;
        t.minn = p.minn;
        return t;
    }
    int mid = (p.l+p.r)/2;
    if(r <=mid) return sub_get(l,r,subidx*2,idx);
    else if(l>mid) return sub_get(l,r,subidx*2+1,idx);
    else {
        t.maxn = max(sub_get(l,mid,subidx*2,idx).maxn,sub_get(mid+1,r,subidx*2+1,idx).maxn);
        t.minn = min(sub_get(l,mid,subidx*2,idx).minn,sub_get(mid+1,r,subidx*2+1,idx).minn);
        return t;
    }
}
seg get(int l,int r,int subl,int subr,int idx)
{
    seg t;
    if(tt[idx].l >=l&&tt[idx].r <=r)
        return sub_get(subl,subr,1,idx);
    int mid = (tt[idx].l+tt[idx].r)/2;
    if(r<=mid)
        return get(l,r,subl,subr,idx*2);
    else if(l >mid)
        return get(l,r,subl,subr,idx*2+1);
    else {
        t.maxn = max(get(l,mid,subl,subr,idx*2).maxn,get(mid+1,r,subl,subr,idx*2+1).maxn);
        t.minn = min(get(l,mid,subl,subr,idx*2).minn,get(mid+1,r,subl,subr,idx*2+1).minn);
        return t;
    }
}
int x,y,l;
int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        scanf("%d",&n);
        loop(i,1,n)
        {
            loop(j,1,n)
            {
                scanf("%d",&a[i][j]);
                update(i,i,j,j,a[i][j],a[i][j],1);
            }
        }
        build(1,n,1,n,1);
       loop(i,1,2*n)
        {
            loop(j,1,2*n)
                printf("%d ",tt[i].t[j].maxn);
            printf("\n");
        }
        
        scanf("%d",&q);
        printf("Case #%d:\n",cas);
        loop(i,1,q)
        {
            scanf("%d%d%d",&x,&y,&l);
            seg t = get(x-(l-1)/2,x+(l-1)/2,y-(l-1)/2,y+(l-1)/2,1);
            int c = (t.maxn+t.minn)/2;
            printf("%d\n",c);
            update(x-(l-1)/2,x+(l-1)/2,y-(l-1)/2,y+(l-1)/2,c,c,1);
        }
        
    }
    return 0;
}

