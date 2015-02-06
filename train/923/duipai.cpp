
#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1000100
#define M 1000000007
typedef long long ll;
using namespace std;

ll f[4][maxn],ans;
ll n,m,l0,r0,x3,x2,x1,x0,l1,R1,R2;
char s[55];

void mod(ll& ppp) { if (ppp<0) ppp+=M; }

ll get(ll id ,ll pos)
{
    if (pos<0) return 0;
    return f[id][pos];
}

struct tree{
    ll col[4*maxn+5],sum[4*maxn+5];
    void PushDown(ll rt,ll l,ll r,ll id)
    {
        if (col[rt]==0) return;
        ll mid=(l+r)/2;
        sum[2*rt]+=col[rt]*(f[id][mid]-get(id,l-1));
        sum[2*rt+1]+=col[rt]*(f[id][r]-get(id,mid));
        sum[2*rt]%=M,sum[2*rt+1]%=M;
        col[2*rt]+=col[rt],col[2*rt+1]+=col[rt];
        col[2*rt]%=M,col[2*rt+1]%=M;
        mod(col[2*rt]),mod(col[2*rt+1]);
        mod(sum[2*rt]),mod(sum[2*rt+1]);
        col[rt]=0;
    }

    void update(ll rt,ll l,ll r,ll L,ll R,ll id,ll v)
    {
        if (L<=l && R>=r)
        {
            col[rt]+=v;
            sum[rt]+=v*(f[id][r]-get(id,l-1));
            col[rt]%=M,sum[rt]%=M;
            mod(col[rt]),mod(sum[rt]);
            return;
        }
        PushDown(rt,l,r,id);
        ll mid=(l+r)>>1;
        if (L<=mid) update(2*rt,l,mid,L,R,id,v);
        if (R> mid) update(2*rt+1,mid+1,r,L,R,id,v);
        sum[rt]=(sum[2*rt]+sum[2*rt+1])%M;
        mod(sum[rt]);
    }

    ll query(ll rt,ll l,ll r,ll L,ll R,ll id)
    {
        if (L<=l && R>=r) return sum[rt];
        PushDown(rt,l,r,id);
        ll mid=(l+r)/2;
        ll tot=0;
        if (L<=mid) tot=query(2*rt,l,mid,L,R,id);
        if (R> mid) tot+=query(2*rt+1,mid+1,r,L,R,id);
        return tot%M;
    }
}t[4];

ll power(ll x,ll y)
{
    ll tot=1;
    while (y)
    {
        if (y&1) tot=(tot*x)%M;
        x=(x*x)%M;
        y>>=1;
    }
    return tot;
}

void init_f()
{
    f[0][0]=1;
    for (ll i=0; i<4; i++)
    {
        for (ll j=1; j<maxn; j++)
            f[i][j]=(f[i][j-1]+power(j,i))%M;
    }
}

void init_tree()
{
    for (ll i=0; i<4; i++)
    {
        memset(t[i].col,0,sizeof t[i].col);
        memset(t[i].sum,0,sizeof t[i].sum);
    }
}

int main()
{
    init_f();
    ll T,cas=0;
    scanf("%lld",&T);
    while (T--)
    {
        printf("Case #%lld:\n",++cas);
        init_tree();
        scanf("%lld",&n);
        while (n--)
        {
            scanf("%s",s);
            if (s[0]=='p')
            {
                scanf("%lld%lld%lld%lld%lld%lld",&l0,&r0,&x3,&x2,&x1,&x0);
                t[3].update(1,0,maxn,l0,r0,3,x3);
                t[2].update(1,0,maxn,l0,r0,2,x2);
                t[1].update(1,0,maxn,l0,r0,1,x1);
                t[0].update(1,0,maxn,l0,r0,0,x0);
            }
            else if (s[0]=='t')
            {
                scanf("%lld%lld%lld%lld%lld%lld",&l0,&r0,&x3,&x2,&x1,&x0);
                ans=0;
                ans+=t[3].query(1,0,maxn,l0,r0,3),mod(ans);
                ans%=M;
                ans+=t[2].query(1,0,maxn,l0,r0,2),mod(ans);
                ans%=M;
                ans+=t[1].query(1,0,maxn,l0,r0,1),mod(ans);
                ans%=M;
                ans+=t[0].query(1,0,maxn,l0,r0,0),mod(ans);
                ans%=M;
                printf("%lld\n",ans);
                R1=(ans*l0)%1000000;
                R2=(ans*r0)%1000000;
                l0=min(R1,R2),r0=max(R1,R2);
                t[3].update(1,0,maxn,l0,r0,3,x3);
                t[2].update(1,0,maxn,l0,r0,2,x2);
                t[1].update(1,0,maxn,l0,r0,1,x1);
                t[0].update(1,0,maxn,l0,r0,0,x0);
            }
        }
    }
    return 0;
}
