/*
 *File:  mytree.cpp
 *Date : 2014-09-25 20:47:51
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
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define mod 1000000007

using namespace std;

const int maxn = 1000010;

LL f[4][maxn];
LL get(int id,int x)
{
    if(x<0 ) return 0;
    return f[id][x];
}
void Mod(LL & x)
{
    x= (x + mod)%mod;
}
struct tree{
    LL add[maxn<<2];
    LL sum[maxn<<2];
    void PushUp(int rt) {
        sum[rt] = (sum[rt<<1] + sum[rt<<1|1]+mod)%mod;
    }
    void PushDown(int rt,int l,int r,int id) {
        if (add[rt]) {
            int mid = (l+r)>>1;
            add[rt<<1] += add[rt];
            add[rt<<1|1] += add[rt];
            sum[rt<<1] += add[rt] * (f[id][mid] - get(id,l-1));
            sum[rt<<1|1] += add[rt] * (f[id][r]-get(id,mid));
            Mod(sum[rt<<1]);
            Mod(sum[rt<<1|1]);
            Mod(add[rt<<1]);
            Mod(add[rt<<1|1]);
            add[rt] = 0;
        }
    }
    void build(int l,int r,int rt) {
        add[rt] = 0;
        if (l == r) {
            scanf("%lld",&sum[rt]);
            return ;
        }
        int m = (l + r) >> 1;
        build(lson);
        build(rson);
        PushUp(rt);
    }
    void update(int L,int R,int c,int l,int r,int rt,int id) {
        if (L <= l && r <= R) {
            add[rt] += c;
            sum[rt] += (LL)c * (f[id][r]-get(id,l-1));
            Mod(add[rt]);
            Mod(sum[rt]);
            return ;
        }
        PushDown(rt , l , r ,id);
        int m = (l + r) >> 1;
        if (L <= m) update(L , R , c , lson,id);
        if (m < R) update(L , R , c , rson,id);
        PushUp(rt);
    }
    LL query(int L,int R,int l,int r,int rt,int id) {
        if (L <= l && r <= R) {
            return sum[rt];
        }
        PushDown(rt , l, r, id);
        int m = (l + r) >> 1;
        LL ret = 0;
        if (L <= m) ret += query(L , R , lson,id);
        if (m < R) ret += query(L , R , rson,id);
        return ret%mod;
    }
};
tree t[4];
LL power(int x,int y)
{
    if(y==0) return 1LL;
    if(y==1) return 1LL*x;
    if(y==2) {
        return (1LL*x*x+mod)%mod;
    }
    if(y==3)
    {
        return ((1LL*x*x)%mod*x+mod)%mod;
    }
    
}
void init_f()
{
    f[0][0]=1;
    loop(i,0,3)
    {
        loop(j,1,maxn-1)
        {
            f[i][j] = (f[i][j-1]+power(j,i))%mod;
        }
    }
    
}
void init_tree()
{
    loop(i,0,3)
    {
            clr(t[i].add);
            clr(t[i].sum);
    }
    
}
int T;
int n;
char str[2];
int a,b,c,d;
int x1,x2;
int main()
{
    init_f();
    scanf("%d",&T);
    loop(cas,1,T)
    {
        init_tree();
        scanf("%d",&n);
        printf("Case #%d:\n",cas);
        while(n--)
        {
            scanf("%s",str);
            if(str[0]=='p')
            {
                scanf("%d%d%d%d%d%d",&x1,&x2,&a,&b,&c,&d);
                t[0].update(x1,x2,d,0,maxn,1,0);
                t[1].update(x1,x2,c,0,maxn,1,1);
                t[2].update(x1,x2,b,0,maxn,1,2);
                t[3].update(x1,x2,a,0,maxn,1,3);
                
            }
            else {
                scanf("%d%d%d%d%d%d",&x1,&x2,&a,&b,&c,&d);
                LL ans = 0;
                loop(i,0,3)
                {
                    ans = (ans+t[i].query(x1,x2,0,maxn,1,i)+mod)%mod;
                }
                printf("%lld\n",ans);
                LL r1 = (ans%1000000)*(x1%1000000)%1000000;
                LL r2 = (ans%1000000)*(x2%1000000)%1000000;
                int l = (int ) min(r1,r2);
                int r = (int ) max(r1,r2);
                t[0].update(l,r,d,0,maxn,1,0);
                t[1].update(l,r,c,0,maxn,1,1);
                t[2].update(l,r,b,0,maxn,1,2);
                t[3].update(l,r,a,0,maxn,1,3);
                
            }
        }
       
    }
    return 0;
}

