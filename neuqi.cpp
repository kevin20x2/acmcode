/*
 *File:  neuqi.cpp
 *Date : 2014-11-29 10:00:42
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
#define maxn 10010
int n;
char str[maxn];

int main()
{
    scanf("%d",&n);
    scanf("%s",&str[1]);
    int ans = 0;
    for(int i =1;i<n;i++)
    {
        int k = 1;
        while(str[i-(k-1)]!=str[i+k])
        {
            ans ++;
            k++;
            if((i-(k-1))<=0||i+k>n)
                break;
        }
    }
    printf("%d\n",ans);
    return 0;
}

