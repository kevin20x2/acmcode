/*
 *File:  2012tianjinga.cpp
 *Date : 2014-10-19 13:20:41
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
int num[4][10];
int numc[8];
bool judge()
{
    int pair=0;
    int meld=0;
    for(int i =1;i<=7;i++)
        if(numc[i])
        {
            if(numc[i]==2) pair++;
            if(numc[i]==3) meld++;
        }
    for(int t =0;t<4;t++)
        for(int i =1;i<=9;i++)
        {
        
        }
    
}

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        
    }
    return 0;
}

