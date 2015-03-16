/*
 *File:  help.cpp
 *Date : 2015-03-15 12:19:18
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

int main()
{
    int a = 1;
    int b =2;
    int Y ;
    b = &a;
    Y = &b ;
    printf("%p",Y);
    return 0;
}

