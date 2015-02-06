/*
 *File:  data.cpp
 *Date : 2014-09-25 22:32:20
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<ctime>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
char str[3] ={"pt"};

int main(int arg,char ** argv)
{
    srand(arg);
    printf("1\n");
    int n = rand()%100000+1;
    printf("%d\n",n);
    srand(time(NULL));
    loop(i,1,n)
    {
        printf("%c ",str[rand()%2]);
        int x1 = rand()%1000000;
        int x2 = rand()%1000000;
        int maxn = max(x1,x2);
        int minn = min(x1,x2);
        int a = rand();
        int b = rand();
        int c = rand();
        int d = rand();
        printf("%d %d %d %d %d %d\n",minn,maxn,a,b,c,d);
    }
    return 0;
}

