/*
 *File:  cfdiv281b.cpp
 *Date : 2014-12-14 00:59:08
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
#define maxn 100
int n;
int a[maxn];
int b[maxn];
int mypow[maxn][maxn];
int tot;
int ans;
int x,y;

void factor(int n)
{
    int temp,i,now;
    temp=(int)((double )sqrt(n)+1);
    tot = 0;
    now = n;
    for(i =2;i<=temp;++i)if(now%i==0){
        a[++tot] = i;
        b[tot] = 0;
        while(now%i==0){
            ++b[tot];
            now/=i;
        }
    }
    if(now!=1)
    {
        a[++tot] =now;
        b[tot] =1;
    }
    for(int i =1;i<=tot;i++)
    {
        mypow[i][0] =1;
        for(int j= 1;j<=b[i];j++)
        {
            mypow[i][j] = mypow[i][j-1]*a[i];
        }
    }
    
}
void dfs(int dep,int now)
{
    if(dep==tot+1)
    {
        if(now>y)
            ans++;
        return ;
    }
    for(int i =0;i<=b[dep];i++)
    {
        dfs(dep+1,now*mypow[dep][i]);
    }
    
}
int main()
{
    tot=0;
    ans = 0;
    scanf("%d%d",&x,&y);
    if(x==y) 
    {
        puts("infinity");
        return 0;
    }else if(y>x) {
        puts("0");
        return 0;
    }
    factor(x-y);
    dfs(1,1);
    printf("%d\n",ans);
    return 0;
}

