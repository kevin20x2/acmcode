/*
 *File:  cf276a.cpp
 *Date : 2014-11-06 14:10:41
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
#define maxn 100050
int n,m;
int vis[maxn];

int main()
{
    clr(vis);
    scanf("%d%d",&n,&m);
    if(n>=m&&n%m==0)
    {
        puts("Yes");
        return 0;
    } else n = n%m;
    while(n!=0)
    {
        if(vis[n] ==1) break;
        vis[n] =1;
        n=(n+(n%m))%m;
    }
    if(n) puts("No") ;
    else puts("Yes");
    return 0;
}

