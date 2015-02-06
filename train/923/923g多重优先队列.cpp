/*
 *File:  g.cpp
 *Date : 2014-09-23 18:39:53
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;

int T;
int n;
char str[2];
priority_queue <int> q[102];


int main()
{
    scanf("%d",&T);
    int t,s,r;
    loop(cas,1,T)
    {
        int ct = 0;
        loop(i,0,100)
            while(q[i].size()) q[i].pop();
        scanf("%d",&n); 
        printf("Case #%d:\n",cas);
        while(n--)
        {
            scanf("%s",str);
            if(str[0]=='P')
            {
                scanf("%d%d%d",&t,&s,&r);
                s-=r*t;
                q[r].push(s);
            }
            else {
                scanf("%d",&t);
                ct = t;
                int ans = -inf;
                int maxn;
                loop(i,0,100) if(q[i].size())
                {
                    ans = max(ans,q[i].top()+i*ct);
                    if(ans==q[i].top()+i*ct)
                        maxn=i;
                }
                q[maxn].pop();
                printf("%d %d\n",ans,maxn);
            }
        }
    }
    return 0;
}

