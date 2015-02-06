/*
 *File:  9121006.cpp
 *Date : 2014-09-21 12:37:58
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
int T;
int n,m,l;
int a[200050];

int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        scanf("%d%d%d",&n,&m,&l);
        loop(i,1,n)
        {
            scanf("%d",&a[i]);
        }
        a[n+1]=m;
        sort(a+1,a+n+2);
        int cp=0;
        int last =-1;
        int ans=0;
        loop(i,1,n+1)
        {
            if(a[i]-cp<=l&&i<n+1)
                last = i;
            else if(a[i]-cp<=l&&i==n+1)
            {
                ans ++;
            }
            else if(a[i]-cp>l&&last!=-1){
                cp=a[last];
                last =-1;
                i--;
                ans++;
            }else if(a[i]-cp>l&&last==-1)
            {
                int res = (a[i]-cp)/l;
                if((a[i]-cp)%l<=1)
                    ans+=res+1;
                else ans+=res+2;
                cp=a[i];
            }
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}

