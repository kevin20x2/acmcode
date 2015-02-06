#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
#define maxn 12
struct seg{
    int t,no,c;
    friend bool operator <(seg n1,seg n2)
    {
        if(n1.t<n2.t) return 1;
        else if(n1.t==n2.t&&n1.c<n2.c) return  1;
        else return 0;
    }
    seg(){}
    seg(int _t,int _no, int _c )
    {
        t = _t; no= _no;c = _c;
    }
}s[maxn];
set <seg> q;
int a[maxn];
int b[maxn];
int c[maxn];

int n;
int main()
{
    int cas= 0;
    while(~scanf("%d",&n)&&n)
    {
        int num = 0;
        q.clear();
        for(int i =1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        for(int i =1;i<=n;i++) 
        {
            if(a[i]>=c[i])
            {
                q.insert(seg(a[i]-c[i]+1,i,1));
                s[i] = seg(a[i]-c[i]+1,i,1);
                num++;
            }
            else if(c[i]>a[i])
            {
                q.insert(seg(a[i]+b[i]-c[i]+1,i,0));
                s[i] = seg(a[i]+b[i]-c[i]+1,i,0);
            }
        }
        int ans = -1;
        int res = 1000005;
        int flag =0;
        int now ;
        seg t = seg(0,0,0);
        while(res--)
        {
            now = t.t;
            t =*q.begin(); 
            if(now!=t.t)
            {
                num+=flag;
                flag = 0;
            }
            if(num==n) {
                ans = t.t;
                break;
            }
            q.erase(q.begin());
            //printf("%d %d %d %d\n",t.t,t.no,num,t.c);
            if(t.c==0) 
            {
               flag++;
               q.insert(seg(t.t+a[t.no],t.no,1));
            }else if(t.c==1)
            {
                if(num>=n-num)
                {
                    q.insert(seg(t.t+a[t.no],t.no,1));
                }else {
                    q.insert(seg(t.t+b[t.no],t.no,0));
                    flag--;
                }
            }
            
        }
        printf("Case %d: %d\n",++cas,ans);
        
    }
    return 0;
}
