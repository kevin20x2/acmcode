/*
 *File:  wintertraink.cpp
 *Date : 2015-01-23 14:48:04
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;
set <int > s;
typedef set <int> :: iterator IT;
LL dp[22][3000][49];
int hash[49];
int mp[3000];
LL fr[22];
int num;
int mod;
LL l, r;
int gcd(int a, int b)
{
    if(a<b) swap(a,b);
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    if(a<b) swap(a,b);
    if(a==0) return 1;
    if(b==0) return a;
    int t = gcd(a,b);
    return a*b/t;
}
LL dfs(int pos,int _mod,int _lcm,LL f)
{
    if(pos==-1) if(_mod%hash[_lcm]==0) return  1;
    else return  0;
    if(f!=fr[pos+1]&&dp[pos][_mod][_lcm]!=-1) return dp[pos][_mod][_lcm];
    LL sum = 0;
    for(int i = 0;i<10;i++) if(f*10+i<=fr[pos])
    {
        sum+=dfs(pos-1,(_mod*10+i)%mod,mp[lcm(hash[_lcm],i)],f*10+i);
    }
    if(f!=fr[pos+1]) dp[pos][_mod][_lcm] = sum;
    return sum;
}
LL get(LL x)
{
    num =0;
    LL t = x;
    while(t)
    {
        fr[num] = t;
        t/=10;
        num++;
    }
    fr[num] =0;
    return dfs(num-1,0,0,0LL);
}

int main()
{
    s.clear();
    s.insert(1);
    for(int i =2;i<10;i++)
    {
        for(IT it=s.begin();it!=s.end();it++)
        {
            s.insert(lcm(*it,i));
        }
    }
    int i =0;
    for(IT it = s.begin();it!=s.end();it++,i++)
    {
        hash[i] = *it;
        mp[*it] = i;
    }
    mod = hash[i-1];
    memset(dp,-1,sizeof dp);
    int T;
    cin>>T;
    while(T--)
    {
        cin>>l>>r;
        cout<<get(r)-get(l-1)<<endl;
       
        
    }

    return 0;
}

