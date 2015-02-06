/*
 *File:  cf1123a.cpp
 *Date : 2014-11-23 17:12:29
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
vector <int> v[4];

int main()
{
    int n;
    scanf("%d",&n);
    int x;
    for(int i =1 ;i<=n;i++)
    {
        scanf("%d",&x);
        v[x].push_back(i);
    }
    int num = inf;
    for(int i =1;i<=3;i++)
        num = min(num,(int)v[i].size());
    printf("%d\n",num);
    for(int i=0;i<num;i++)
    {
        printf("%d %d %d\n",v[1][i],v[2][i],v[3][i]);
    }
    return 0;
}

