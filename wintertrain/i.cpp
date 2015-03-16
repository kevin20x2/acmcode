/*
 *File:  i.cpp
 *Date : 2015-03-01 13:03:47
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
int n ;
int p[2100];

int main()
{
    scanf("%d",&n);
    for(int i =1;i<=n;i++)
        scanf("%d",&p[i]);
    sort(p+1,p+n+1);
    int t = p[n];
    int ans = 1;
    int s = 1;
    while(s<n)
    {
        t-=p[s];
        if(t<0) break;
        ans++;
        s++;
    }
    printf("%d\n",ans);
    return 0;
}

