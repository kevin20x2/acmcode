/*
 *File:  2014119a.cpp
 *Date : 2014-11-09 12:33:16
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
int dx[] ={1,2,3,3,4,10};
int dy[] ={1,2,2,2,3,5,10};

int T;
int main()
{
    scanf("%d",&T);
    for(int cas= 1;cas<=T;cas++)
    {
        printf("Battle %d: ",cas);
        int suma =0,sumb=0;
        int x;
        for(int i =0;i<6;i++)
        {
            scanf("%d",&x);
            suma+=x*dx[i];
        }
        for(int i =0;i<7;i++)
        {
            scanf("%d",&x);
            sumb+=x*dy[i];
        }
        if(suma>sumb)
            puts("Good triumphs over Evil");
        else if(suma<sumb) puts("Evil eradicates all trace of Good");
        else puts("No victor on this battle field");
        
    }
    return 0;
}

