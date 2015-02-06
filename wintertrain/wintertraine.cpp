/*
 *File:  wintertraine.cpp
 *Date : 2015-01-08 21:31:42
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;

struct seg{
    int num;
    int f;
    seg (int num,int f):num(num),f(f){}
    seg (){num =0;f =0;}
    bool operator <(const seg &a) const
    {
        if(f>a.f) return 1;
        else if(f==a.f&&num<a.num) return 1; 
        else return 0;
    }
}s[10000];
int l,r;
int n;
int h;
int ans[26][26];
int res[26];
int t[26];
int sum[26];
int f[26];
int d[26];
int main()
{
    int fi = 1;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&h);
        h=h*12;
        for(int i =1;i<=n;i++)
            scanf("%d",&f[i]);
        for(int i = 1;i<=n;i++)
            scanf("%d",&d[i]);
        for(int i =1;i<=n-1;i++)
            scanf("%d",&t[i]);
        sum[0] = 0;t[0] = 0;
        for(int i = 1;i<=n;i++)
            sum[i] = sum[i-1]+t[i-1];
        memset(ans,0,sizeof ans);
        l =r =0;
        for(int i =1;i<=n;i++)
        {
            int re = h - sum[i];
            int tmp = f[i];
            for(int j =1;j<=re;j++)
            {
                s[r++] = seg(i,tmp);
                if(tmp>d[i])
                    tmp -= d[i];
                else tmp =0;
            }
        }
        sort(s,s+r);
        for(int i = 1;i<=n;i++)
        {
            res[i] = 0;
            int re = h- sum[i];
            for(int j =0;j<r;j++) if(s[j].num<=i)
            {
                if(re<=0) break;
                re --;
                ans[i][s[j].num]++;
                res[i]+= s[j].f;
            }
        }
        int maxn = 0;
        int no = 0;
        for(int i = n;i>=1;i--)
        {
            maxn = max(maxn,res[i]);
            if(maxn == res[i])
                no = i;
        }
        int first  =1;
        if(fi) fi = 0;
        else printf("\n");
        
        for(int i = 1;i<=n;i++)
        {
            if(first){
                printf("%d",ans[no][i]*5);
                first = 0;
            }else printf(", %d",ans[no][i]*5);
        }
        printf("\nNumber of fish expected: %d\n",res[no]);

        
    }
    return 0;
}

