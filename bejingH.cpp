/*
 *File:  bejingH.cpp
 *Date : 2014-11-01 13:28:12
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
#define maxn 20010
int bemin[maxn];
int bemax[maxn];
int afmin[maxn];
int afmax[maxn];
int a[maxn];
int MIN[maxn];
int MAX[maxn];
int n;

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas-- )
    {
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
            scanf("%d",&a[i]);
        MAX[1] =a[1];
        MIN[1] =a[n];
        for(int i =2;i<=n;i++)
        {
            MIN[i] = MIN[i-1];
            MAX[i] = MAX[i-1];
            if(a[i]>MAX[i-1])
                MAX[i] = a[i];
            if(a[n-i+1]>MIN[i])
                MIN[i] = a[n-i+1];
        }
        
        for(int i =1;i<=n;i++)
        {
            bemax[i] = (lower_bound(MAX+1,MAX+i,a[i])-MAX)-1;
            afmax[i] = (lower_bound(MIN+1,MIN+n-i+1,a[i])-MIN)-1;
            afmin[i] = n-i-afmax[i];
            bemin[i] = i-1-bemax[i];
            printf("%d %d %d %d\n",bemax[i],bemin[i],afmax[i],afmin[i]);
        }
        LL ans = 0;
        for(int i=1;i<=n;i++)
        {
            ans += 1LL*bemax[i]*afmin[i]+1LL*bemin[i]*afmax[i] ;
        }
        printf("%I64d\n",ans);

    }
    return 0;
}

