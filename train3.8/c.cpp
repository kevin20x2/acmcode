/*
 *File:  c.cpp
 *Date : 2015-03-08 15:02:59
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
const int maxn =200010;
int a[maxn];
int b[maxn];
int n,m;

int main()
{
    scanf("%d",&n);
    for(int i =1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    scanf("%d",&m);
    for(int i =1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+m+1);
    int ans = 0;
    for(int i =1;i<=m;i++) if(b[i])
    {
        
    }

    return 0;
}

