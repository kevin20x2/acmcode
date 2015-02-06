/*
 *File:  cfdiv281a.cpp
 *Date : 2014-12-14 00:34:19
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
int a[10];
int main()
{
    a[0] = 2;
    a[1] = 7;
    a[2] = 2;
    a[3] = 3;
    a[4] = 3;
    a[5] = 4;
    a[6] = 2;
    a[7] = 5;
    a[8] = 1;
    a[9] = 2;
    char x;
    int ans = 1;
    x = getchar();
    ans*= a[x-'0'];
    x = getchar();
    ans*=a[x-'0'];
    printf("%d\n",ans);
    return 0;
}

