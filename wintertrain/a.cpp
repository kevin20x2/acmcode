/*
 *File:  a.cpp
 *Date : 2015-03-01 14:22:55
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
const int maxn = 100005;
struct edge{
    int x,y;
}a[maxn];
struct node{
    int l ,r;
    vector <edge> v;
}tree[maxn<<1];
int n,m,q;
vector <edge> ans;
vector <int > m[maxn];
void build(int x,int l,int r)
{
    int mid = (l+r)>>1;
    if(l==r)
    {
        tree[x].v.push_back(a[l]);
        break;
    }
    build(x<<1,l,mid);
    build(x<<1|1,mid+1,r);
    for(int i =0;i<tree[x<<1].v.size();i++)
        tree[x].v.push_back(tree[x<<1].v[i]);
    for(int i =0;i<tree[x<<1|1].v.size();i++)
        tree[x].v.push_back(tree[x<<1|1].v[i]);
}
void query(int l,int r,int x,int L,int R)
{
    if(L>=l&&R<=r)
    {
        for(int i =0;i<tree[x].v.size();i++)
            ans.push_back(tree[x].v[i]);
    }
    int mid = (L+R)>>1;
    if(l<=mid) query(l,r,x<<1,L,mid);
    if(mid<r) query(l,r,x<<1|1,mid+1,R);
    
}

int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",a[i].x,a[i].y);
    }
    build(1,1,m);
    int l,r;
    for(int i =1;i<=q;i++)
    {

        scanf("%d%d",&l,&r);
        ans.clear();
        query(l,r,1,1,n);
    }

    return 0;
}

