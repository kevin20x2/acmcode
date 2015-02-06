/*
 *File:  1006.cpp
 *Date : 2014-09-27 14:28:46
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
int T;
LL x;
char ans[30];
char * co(LL x)
{
    
}

int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        printf("Case #%d:",cas);
        scanf("%I64d",&x);
        printf("%I64d\n",8*x*x-7*x+1);
    }
    return 0;
}

