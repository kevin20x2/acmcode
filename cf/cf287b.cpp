/*
 *File:  cf287b.cpp
 *Date : 2015-01-24 00:17:54
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
#define eps 1e-9

using namespace std;
int main()
{
    double x,y,lx,ly,r;
    cin>>r>>x>>y>>lx>>ly;
    double len = sqrt((x-lx)*(x-lx)+(y-ly)*(y-ly));
    int ans = 0;
    while(2*r*ans<len)
    {
        ans ++;
    }
    printf("%d\n",ans);

    return 0;
}

