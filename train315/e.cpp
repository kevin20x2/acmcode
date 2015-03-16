/*
 *File:  e.cpp
 *Date : 2015-03-15 16:07:39
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
int n,p;
int mod;
LL pow(LL a)
{
    LL t = p;
    vector <LL > v;
    while(a>1)
    {
        if(a&1) v.push_back(t);
        t = (t*t)%mod;
        a /=2;
        
    }
    for(int i = 0;i<v.size();i++)
        t = (t*v[i])%mod;
    return t%mod;
}

int main()
{
    bool flag =0;
    while(~scanf("%d%d",&p,&n))
    {
        if(flag) printf("\n");
        flag = 1;
        mod = 1;
        for(int i =2;i<=n;i++)
            mod*= i;
        LL ans = p;
        for(int i = 0;i<=100010;i++)
        {
            ans = pow(ans);
        }
        cout<<ans<<endl;
    }

    return 0;
}

