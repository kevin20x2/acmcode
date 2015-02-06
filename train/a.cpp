/*
 *File:  a.cpp
 *Date : 2014-09-19 19:04:43
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
int T;
int n,m;
int s[100002];
int p[100002];
int q[100002];
LL minn[100002];
LL minsum[100002];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        loop(i,1,n)
        {
            scanf("%d%d",&s[i],&p[i]);
        }
        loop(i,1,n)
        {
            minn[i]=(LL)s[i]*p[i];
        }
        minsum[n] = minn[n];
        iloop(i,1,n-1)
        {
            minsum[i]=min(minn[i],minsum[i+1]);
        }
        loop(i,1,m)
        {
            scanf("%d",&q[i]);
            int num;
            LL ans = 1e14+2;
            int l =1,r=n;
            while(l<=r)
            {
                int mid = (l+r)/2;
                if(q[i]>=s[l]&&q[i]<=s[mid]) r=mid;
                else if(q[i]>s[mid]&&q[i]<=s[r]) l=mid+1;
                if(q[i]>=s[l]&&q[i]<s[l+1]) break;
            }
            ans = min((LL)q[i]*p[l],minsum[l+1]);
            printf("%I64d\n",ans);
        }

    }
    return 0;
}

