/*
 *File:  291c.cpp
 *Date : 2015-02-15 02:01:32
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#include<map>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
const LL p = (LL)1e9+7;
const LL q = (LL)1e9+9;
const int maxn = 600050;
LL sp[maxn];
LL sq[maxn];
int n,m;
set <pair<LL,LL> > s;
char str[maxn];
void init()
{
    sp[0]=1;
    sq[0]=1;
    for(int i =1;i<maxn;i++)
    {
        sp[i] =sp[i-1]*1234567;
        sp[i]%=p;
        sq[i] = sq[i-1]*1234567;
        sq[i]%=q;
    }
}

int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;i++)
    {
        scanf("%s",str);
        int len = strlen(str);
        pair <LL,LL> now = make_pair(1,1);
        for(int j = 0;j<len;j++)
        {
            now.first*=sp[1];
            now.first+=str[j];
            now.first%=p;

            now.second*=sq[1];
            now.second+=str[j];
            now.second%=q;
        }
        s.insert(now);
    }
    for(int i =1;i<=m;i++)
    {
        scanf("%s",str);
        int len = strlen(str);
        pair <LL,LL> now =make_pair(1,1);
        for(int j =0;j<len;j++)
        {
            now.first*=sp[1];
            now.first+=str[j];
            now.first %=p;

            now.second*=sq[1];
            now.second+=str[j];
            now.second%=q;
        }
        bool st = false;
        for(int j =0;j<len;j++)
        {
            for(char c = 'a';c<='c';c++)
            {
                if(str[j]!=c)
                {
                    pair <LL,LL> nnow = now;
                    nnow.first -= str[j]*sp[len-j-1];
                    nnow.first += c*sp[len-j-1];
                    nnow.first %=p;
                    nnow.first +=p;
                    nnow.first %=p;
                    
                    nnow.second -=str[j]*sq[len-j-1];
                    nnow.second +=c*sq[len-j-1];
                    nnow.second %=q;
                    nnow.second +=q;
                    nnow.second %=q;
                    if(s.count(nnow))
                        st = true;
                }
                
            }
        }
        if(st)
        {
            puts("YES");
        }
        else puts("NO");
    }
    
    return 0;
}

