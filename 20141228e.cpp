/*
 *File:  20141228e.cpp
 *Date : 2014-12-28 17:14:28
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<list>
#include<algorithm>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;
#define maxn 1005
list <int > l;
int a[maxn];
bool ans[maxn];
int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(ans,0,sizeof ans);
        l.clear();
        int sum =0;
        for(int i =1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        bool flag = 0;
        while(sum)
        {
            if(sum&1&&sum!=1)
            {
                flag =1;
                break;
            }
            sum /=2;
        }
        if(flag)
        {
            puts("no");
            continue;
        }
        l.push_back(a[1]);
        for(int i=2;i<=n;i++)
        {
            if(a[i]>l[0]) 
            {
                int t = l.size();
                if(l[t-1]==a[i])
                {
                    l.pop_back();
                    l.pop_back(2*a[i]);
                }
            }

        }
    }
    return 0;
}

