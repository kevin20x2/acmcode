/*
 *File:  newceshi.cpp
 *Date : 2014-12-26 13:31:20
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

struct A{
    char *a,b,*geta();
    char A::*p;
    char *A::*q();
    char *(A::*r)();
}

int main()
{
    A a;
    a.p =&A::a;
    a.p =&A::b;
    a.q=&A::geta;
    a.r = a.geta;
    return 0;
}

