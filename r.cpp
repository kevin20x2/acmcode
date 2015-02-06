/*
 *File:  r.cpp
 *Date : 2014-11-08 21:20:46
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
#define maxn 10

int main()
{
    srand(time(NULL));
    int n = rand()%maxn+6;
    printf("%d\n",n);
    for(int i =1;i<=n;i++)
        printf("%d ",rand()%10000+1);
    
    return 0;
}

