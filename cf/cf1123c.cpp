/*
 *File:  cf1123c.cpp
 *Date : 2014-11-23 17:27:35
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
#define maxn 1000050
char str[maxn];
bool ans[maxn];
int a,b;
int dpow[maxn];
int n;

void powinit()
{
    dpow[0] = 1;
    for(int i =1;i<n;i++)
        dpow[i] = dpow[i-1]*10%b;


}
int main()
{
    memset(ans,0,sizeof(ans));
    scanf("%s",str);
    scanf("%d%d",&a,&b);
    n = strlen(str);
    powinit();
    int res = 0;
    if(str[0]=='0')
    {
        puts("NO");
        return 0;
    }
    for(int i =0;i<n;i++)
    {
        res = (res*10%a+(int )(str[i]-'0')%a)%a;
        if(res==0)
            ans[i] =1;
    }
    res = 0;
    for(int i =n-1;i>=0;i--)
    {
        if(str[i]!='0')
        {
            res = (dpow[n-i-1]*(int)(str[i]-'0')%b+res)%b;
            if(res == 0&&ans[i-1]==1)
            {
                puts("YES");
                for(int j=0;j<i;j++)
                    putchar(str[j]);
                putchar('\n');
                for(int j = i;j<n;j++)
                    putchar(str[j]);
                putchar('\n');
                return 0;

            }
            
        }
    }
    puts("NO");
    return 0;
}

