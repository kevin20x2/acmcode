/*
 *File:  cf276c.cpp
 *Date : 2014-11-06 15:12:41
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
#define maxn 65
int sx[maxn],lx,rx;
int sy[maxn],ly,ry;
int n;
LL x,y;

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%I64d%I64d",&x,&y);
        lx = rx = 0;
        if(x<y) swap(x,y);
        LL tx =x,ty = y;
        while(x!=0)
        {
            sx[rx++] = x&1;
            x/=2;
        }
        ly = ry = 0;
        while(y!=0)
        {
            sy[ry++] = y&1;
            y/=2;
        }
        if(rx!=ry)
        {
            if(tx==1LL*((1<<rx)-1))
                printf("%I64d\n",tx);
            else printf("%I64d\n",1LL*(1<<(rx-1))-1);
            
        }
        else {
            rx --;
            LL ans = 0;
            while(sx[rx] == sy[rx]) 
            {
                if(sx[rx]==1)
                    ans += 1<<rx;
                rx --;
            }
           // printf("%I64d",ans);
            if(rx>=0)
            {
                if((tx&1LL*((1<<(rx+1))-1))==1LL*((1<<(rx+1))-1))
                    ans += (1<<(rx+1))-1;
                else ans += (1<<rx) -1;
            }
            printf("%I64d\n",ans);
        }
    }

    return 0;
}

