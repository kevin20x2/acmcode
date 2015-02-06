/*
 *File:  cf479b.cpp.cpp
 *Date : 2014-10-19 17:26:35
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
int n,k;
struct seg{
    int a,c;
};
seg a[1010];
int cmp(seg a,seg b)
{
    return a.a>b.a;
}
vector <int > v;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].a);
        a[i].c = i;
    }
    sort(a+1,a+n+1,cmp);
    int ans=0;
    while(ans<k)
    {
        if(a[1].a-a[n].a<=1)
            break;
        else 
        {
            a[1].a --;
            a[n].a ++;
            v.push_back(a[1].c);
            v.push_back(a[n].c);
        }
        sort(a+1,a+n+1,cmp);
        ans++;
    }
    printf("%d %d\n",a[1].a-a[n].a,ans);
    for(int i=1;i<=ans;i++)
        printf("%d %d\n",v[2*(i-1)],v[2*(i-1)+1]);
    return 0;
}

