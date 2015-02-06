/*
 *File:  2007d.cpp
 *Date : 2015-01-02 16:59:15
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
#define maxn 1000
int a[13];
int b[105];
int m,n;
int now;
int ans[105][maxn][13];
int size[105][maxn];
int l,r;
int tot[105];
int tmp[13];
void dfs(int re)
{
    if(re<=0)
    {
        size[now][tot[now]] = r;
        for(int i =0;i<r;i++)
            ans[now][tot[now]++][i] = tmp[i];
        return ;
    }
    for(int i= 1;i<=m;i++) if(re>=a[i])
    {
        tmp[r++] = a[i];
        dfs(re-a[i]);
        tmp[r--] = 0;
    }
}

int main()
{
    while(~scanf("%d",&m))
    {
        for(int i =1;i<=m;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+m+1);
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
            scanf("%d",&b[i]);

    }
    return 0;
}

