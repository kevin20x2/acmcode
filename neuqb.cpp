/*
 *File:  neuqb.cpp
 *Date : 2014-11-29 09:37:35
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
#define maxn 200010
int n;

int main()
{
    int last,last2,now;
    scanf("%d",&n);
    for(int i =0;i<n;i++)
    {
        if(i>=2) last2 = last;
        if(i>=1) last = now;
        scanf("%d",&now);
        if(i==1&&now>last) {
            puts("YES");
            return 0;
        }else if(i==n-1&&now<last)
        {
            puts("YES");
            return 0;
            
        }
        else if(now>last&&last2>last)
        {
            puts("YES");
            return 0;
        }
    }
       
    return 0;
}

