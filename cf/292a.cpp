/*
 *File:  292a.cpp
 *Date : 2015-02-18 00:38:41
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
int a,b;
int n;

int main()
{
    scanf("%d%d%d",&a,&b,&n);
    int t = n-abs(a)-abs(b);
    if(t<0) 
    { 
        puts("No");

    }else if((t&1)==0)
        puts("Yes");
    else puts("No");
    return 0;
}

