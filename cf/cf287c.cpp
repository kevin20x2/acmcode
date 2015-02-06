/*
 *File:  cf287c.cpp
 *Date : 2015-01-24 01:09:21
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
int s[55],l;
int h;
LL n;

int main()
{
    cin>>h>>n;
    int t = n-1;
    LL ans = 0;
    for(int i =0;i<h;i++)
    {
        s[i] = t%2;
        t/=2;
    }
    int e = 0;
    for(int i = h-1;i>=0;i--)
    {
        if(e==s[i])
        {
            ans+=1;
            e^=1;
        }
        else { 
            ans+=(1<<(i+1));
            e=s[i]^1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

