/*
 *File:  newmobang.cpp
 *Date : 2014-09-23 22:20:05
 */
#include<cstdio>
#include<iostream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
 
#define lowbit(x) (x&(-x))
 
using namespace std;
 
struct N
{
    int Min,Max;
}st[805<<2][805<<2];
 
int num[810][810];
 
void Init_Y(int s1,int s2,int l,int r,int t,int b)
{
 
    if(t == b)
    {
        if(l == r)
        {
            st[s1][s2].Max = num[l][t];
            st[s1][s2].Min = num[l][t];
        }
        else
        {
 
            st[s1][s2].Max = max(st[s1<<1][s2].Max,st[s1<<1|1][s2].Max);
            st[s1][s2].Min = min(st[s1<<1][s2].Min,st[s1<<1|1][s2].Min);
        }
        return ;
    }
 
    int mid = (t+b)>>1;
 
    Init_Y(s1,s2<<1,l,r,t,mid);
    Init_Y(s1,s2<<1|1,l,r,mid+1,b);
 
    st[s1][s2].Max = max(st[s1][s2<<1].Max,st[s1][s2<<1|1].Max);
    st[s1][s2].Min = min(st[s1][s2<<1].Min,st[s1][s2<<1|1].Min);
}
 
void Init_X(int s1,int s2,int l,int r,int t,int b)
{
    if(l != r)
    {
        int mid = (l+r)>>1;
 
        Init_X(s1<<1,s2,l,mid,t,b);
        Init_X(s1<<1|1,s2,mid+1,r,t,b);
    }
 
    Init_Y(s1,s2,l,r,t,b);
}
void update_y(int y,int data,int l,int r,int t,int b,int s2,int s1)
{
    if(t==b) 
    {
        if(l==r)
        {
            st[s1][s2].Max=data;
            st[s1][s2].Min=data;
        }
        else {
            st[s1][s2].Max=max(st[s1<<1][s2].Max,st[s1<<1|1][s2].Max);
            st[s1][s2].Min=min(st[s1<<1][s2].Min,st[s1<<1|1][s2].Min);
        }
        return ;
    }
    int mid = (t+b)/2;
    if(y<=mid)
        update_y(y,data,l,r,t,mid,s2*2,s1);
    else update_y(y,data,l,r,mid+1,b,s2*2+1,s1);
    st[s1][s2].Max=max(st[s1][s2<<1].Max,st[s1][s2<<1|1].Max);
    st[s1][s2].Min=min(st[s1][s2<<1].Min,st[s1][s2<<1|1].Min);
}
void update_x(int x,int y,int data,int l,int r,int t,int b,int s1)
{
    if(l==r)
    {
        update_y(y,data,l,r,t,b,1,s1);
        return ;
    }
    int mid = (l+r)/2;
    if(x<=mid) update_x(x,y,data,l,mid,t,b,s1*2);
    else update_x(x,y,data,mid+1,r,t,b,s1*2+1);
    update_y(y,data,l,r,t,b,1,s1);
}
 
N Query_Y(int s1,int s2,int L,int R,int T,int B,int l,int r,int t,int b)
{
    if(T == t && B == b)
        return st[s1][s2];
 
    int mid = (T+B)>>1;
 
    if(b <= mid)
        return Query_Y(s1,s2<<1,L,R,T,mid,l,r,t,b);
    else if(mid < t)
        return Query_Y(s1,s2<<1|1,L,R,mid+1,B,l,r,t,b);
    N temp,t1,t2;
 
    t1 = Query_Y(s1,s2<<1,L,R,T,mid,l,r,t,mid);
    t2 = Query_Y(s1,s2<<1|1,L,R,mid+1,B,l,r,mid+1,b);
 
    temp.Max = max(t1.Max,t2.Max);
    temp.Min = min(t1.Min,t2.Min);
    return temp;
}
 
N Query_X(int s1,int s2,int L,int R,int T,int B,int l,int r,int t,int b)
{
    if(L == l && R == r)
    {
        return Query_Y(s1,s2,L,R,T,B,l,r,t,b);
    }
 
    int mid = (L+R)>>1;
 
    if(r <= mid)
        return Query_X(s1<<1,s2,L,mid,T,B,l,r,t,b);
    else if(mid < l)
        return Query_X(s1<<1|1,s2,mid+1,R,T,B,l,r,t,b);
    N temp,t1,t2;
    t1 = Query_X(s1<<1,s2,L,mid,T,B,l,mid,t,b);
    t2 = Query_X(s1<<1|1,s2,mid+1,R,T,B,mid+1,r,t,b);
    temp.Max = max(t1.Max,t2.Max);
    temp.Min = min(t1.Min,t2.Min);
    return temp;
}
 
int main()
{
    int T;
    int n,m,k,b,i,j,x,y;
    int l;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
 
        scanf("%d",&n);
        for(i = 1;i <= n; ++i)
        {
            for(j = 1;j <= n; ++j)
            {
                scanf("%d",&num[i][j]);
            }
        }
        Init_X(1,1,1,n,1,n);
        scanf("%d",&k);
        printf("Case #%d:\n",cas);
        while(k--)
        {
            scanf("%d%d%d",&x,&y,&l);
            int li=max(1,x-((l-1)/2));
            int r=min(n,x+(l-1)/2);
            int t=max(1,y-(l-1)/2);
            int b=min(n,y+(l-1)/2);
            N temp = Query_X(1,1,1,n,1,n,li,r,t,b);
            printf("%d\n",(temp.Max+temp.Min)/2);
            update_x(x,y,(temp.Max+temp.Min)/2,1,n,1,n,1);
           /* for(int i=1;i<=2*n;i++){
                for(int j=1;j<=2*n;j++)
                    printf("%d ",st[i][j].Min);
                printf("\n");
            }
            */
        }
    }

    return 0;
}

