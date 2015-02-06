/*
 *File:  d.cpp
 *Date : 2014-10-07 20:55:49
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
#define maxn 100010
struct seg{
    int v,next;
}edge[maxn*2];
int tol;
int begin[maxn];
void addedge(int u,int v)
{
    edge[tol].v = v;
    edge[tol].next = begin[u];
    begin[u] =tol++;
}
int fa[maxn],dep[maxn],son[maxn],p[maxn],num[maxn],top[maxn],cnt;
int val1[maxn];
int val[maxn];
void init()
{
    cnt = 0;
    tol = 0;
    memset(son,-1,sizeof(son));
    memset(begin,-1,sizeof(begin));
}

void dfs(int x,int f,int d)
{
    fa[x] =f;
    dep[x] =d;
    num[x] =1;
    for(int i = begin[x];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v!=f)
        {
            dfs(v,x,d+1);
            num[x] +=num[v];
            if(son[x] == -1||num[v]>num[son[x]])
                son[x] = v;
        }
    }
    
}
void getpos(int x,int sp)
{
    top[x] = sp;
    p[x] = cnt++;
    if(son[x]==-1) return ;
    getpos(son[x],sp);
    for(int i = begin[x];i!=-1;i= edge[i].next)
    {
        int v = edge[i].v;
        if(v!=fa[x]&&v!=son[x])
        {
            getpos(v,v);
        }
    }
}
struct node{
    int lc,rc;
    int sum,col;
    node(){sum =0;}
}tree[maxn<<2];
void push_up(int rt)
{
    tree[rt].sum = tree[rt<<1].sum+tree[rt<<1|1].sum;
    tree[rt].lc = tree[rt<<1].lc;
    tree[rt].rc = tree[rt<<1|1].rc;
    if(tree[rt<<1].rc == tree[rt<<1|1].lc) tree[rt].sum--;
    
}
void push_down(int rt )
{
    if(tree[rt].col)
    {
        tree[rt<<1].col =  tree[rt<<1|1].col =tree[rt].col;
        tree[rt<<1].lc = tree[rt<<1|1].lc=tree[rt<<1].rc = tree[rt<<1|1].rc = tree[rt].col;
        tree[rt<<1].sum = tree[rt<<1|1].sum = 1;
        tree[rt].col  = 0;
    }
}
void build(int rt,int l,int r)
{
    tree[rt].col = 0;
    if(l == r) 
    {
        tree[rt].lc=tree[rt].rc = val[l];
        tree[rt].sum = 1;
        return ;
    }
    int m = (l+r)>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    push_up(rt);
}
void update(int rt,int L,int R,int l,int r,int c)
{
    if(L <=l&&r<=R)
    {
        tree[rt].lc = tree[rt].rc = c;
        tree[rt].col = c;
        tree[rt].sum = 1;
        return ;
    }
    push_down(rt);
    int m = (l+r)>>1;
    if(L <= m) update(rt<<1,L,R,l,m,c);
    if(R > m ) update(rt<<1|1,L,R,m+1,r,c);
    push_up(rt);
}
node  merge(node a,node b)
{
    node ans;
    if(a.sum == 0) return b;
    if(b.sum == 0) return a;
    ans.lc = a.lc;
    ans.rc = b.rc;
    ans.sum = a.sum+b.sum;
    if(a.rc==b.lc) ans.sum --;
    return ans;
}
node query(int rt,int L,int R,int l, int r)
{
    if(l>=L&&r<=R)
     {
        return tree[rt];
     }
    push_down(rt);
    node ans;
    int mid = (l+r)/2;
    if(L<=mid) ans = merge(query(rt<<1,L,R,l,mid),ans);
    if(R>mid) ans = merge(ans,query(rt<<1|1,L,R,mid+1,r));
    push_up(rt);
    return ans;
}
void C(int u,int v,int c)
{
    int f1 = top[u],f2 = top[v];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        update(1,p[f1],p[u],1,cnt,c);
        u = fa[f1];
        f1 = top[u];
    }
    if(dep[u]>dep[v]) swap(u,v);
    update(1,p[u],p[v],1,cnt,c);
}
int Q(int u,int v)
{
    int f1 = top[u],f2 = top[v];
    node ans1,ans2 ;
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])
        {
            swap(f1,f2);
            swap(u,v);
            swap(ans1,ans2);
        }
        ans1 = merge(query(1,p[f1],p[u],1,cnt),ans1);
        u =fa[f1];
        f1 = top[u];
        
    }
    if(dep[u] >dep[v]){
        swap(ans1,ans2);
        swap(u,v);
        
    }
    ans2 = merge(query(1,p[u],p[v],1,cnt),ans2);
    if(ans1.sum== 0) return ans2.sum;
    if(ans2.sum==0) return ans1.sum;
    int ans = ans1.sum +ans2.sum;
    if(ans1.lc == ans2.lc) ans --;
    return ans;
}
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    init();
    for(int i =1;i<=n;i++)
    {
        scanf("%d",&val1[i]);
    }
    int x,y;
    for(int i =1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs(1,0,0);
    getpos(1,1);
    for(int i =1;i<=n;i++)
    {
        val[p[i]] =val1[i];
    }
    build(1,1,cnt);
    char str[3];
    int a,b,c;
    while(m--)
    {
        scanf("%s",str);
        if(str[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            int ans = Q(a,b);
            printf("%d\n",ans);
            
        }
        if(str[0]=='C')
        {
            scanf("%d%d%d",&a,&b,&c);
            C(a,b,c);
        }
        
    }

    return 0;
}

