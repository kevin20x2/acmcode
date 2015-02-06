/*
 *File:  2006shanghaia.cpp
 *Date : 2014-12-27 12:35:28
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
#define maxn 105
int s,t,m;
bool first[maxn];
int num[maxn];

int main()
{
    int cas =0 ;
    int x,y,z;
    while(~scanf("%d%d%d",&s,&t,&m)&&s&&t&&m)
    {
        memset(num,0,sizeof(num));
        memset(first,0,sizeof first);
        for(int i =1;i<=s;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            num[x] = y+z;
        }
        for(int i = 1;i<=t;i++)
        {
            scanf("%d%d",&x,&y);
            if(y>=m) first[x] = 1;
        }
        int sum = 0;
        for(int i =1;i<=s;i++)
        {
            sum+= num[i]+first[i];
        }
        printf("Case %d: %d\n",++cas,sum);


    }
    return 0;
}

