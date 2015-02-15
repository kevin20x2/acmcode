/*
 *File:  291b.cpp
 *Date : 2015-02-15 00:48:05
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
struct seg{
    int x,y;
}res[1010];
int x[1010];
int y[1010];

int n;
int cmp(seg a,seg b)
{
    return a.y*b.x<a.x*b.y;
}

int main()
{
    int a,b;
    scanf("%d%d%d",&n,&a,&b);
    for(int i =1;i<=n;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        if(x[i]>a)
        {
            res[i].x = x[i]-a;
            res[i].y = y[i]-b;
        }else {
            res[i].x = a-x[i];
            res[i].y = b-y[i];
        }
    }
    sort(res+1,res+n+1,cmp);
    int ans = 1;
    for(int i = 2;i<=n;i++)
    {
        if(res[i].x*res[i-1].y==res[i].y*res[i-1].x)
            ;
        else if(res[i].x*res[1].y!=res[1].x*res[i].y) ans++;
        
    }
    printf("%d\n",ans);
    
    return 0;
}

