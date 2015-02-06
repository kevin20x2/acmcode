/*
 *File:  exgcd.cpp
 *Date : 2014-10-03 12:10:43
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

using namespace std;
int exgcd(int a, int b , int &x,int &y)
{
    int t,tx;
    if(b==0){
        x = 1;y=0;
        return a;
    }
    t  = exgcd(b,a%b,x,y);
    tx = x;
    x = y;
    y = tx -a /b *y;
    return t;
}

int main()
{
    return 0;
}

