/*
 *File:  shuzhuangshuzu.cpp
 *Date : 2014-09-25 15:22:27
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
#define MAXN 1000000

using namespace std;
int b[MAXN];
int c[MAXN];
void add_b(int x, int c)
{
    for(;x;x-=x&(-x)) b[x] +=c;
}
void add_c(int x,int c)
{
    for(int i = x;i<=MAXN;i+=i&(-i)) c[i]+=x*c;
}
int sum_b(int x)
{
    int ans = 0;
    for(;x<=MAXN;x+=x&(-x)) ans +=b[x];
    return ans;
}
int sum_c(int x)
{
    int ans = 0;
    for(;x;x-=x&(-x)) ans +=c[x];
    return ans;
}
inline int sum(int x)//1-x的和
{
    if(x) return sum_b(x)*x+sum_c(x-1);
    else return 0;
}


int main()
{
    return 0;
}

