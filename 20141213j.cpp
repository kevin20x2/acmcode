/*
 *File:  20141213j.cpp
 *Date : 2014-12-13 10:07:52
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
int a[33];
int b[33];
int T;
int cmp()
{
    for(int i =1;i<=32;i++)
        if(a[i]!=b[i]) return 0;
    return 1;
}
int shift()
{
    for(int i = 1;i<=32;i++)
        a[i-1] = a[i];
    a[32] = a[0];
}
int right_shift()
{
    int t = a[32];
    for(int i = 31;i>0;i--)
        a[i+1] = a[i];
    a[1] = t;

}

int main()
{
    LL x,y;
    int cas = 0;
    scanf("%d",&T);
    while(T--)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        scanf("%llx%llx",&x,&y);
        int t = 32;
        while(x)
        {
            a[t--] = x%2;
            x/=2;
        }
        t  =32;
        while(y)
        {
            b[t--] = y%2;
            y/=2;
        }
        int ans_left = inf;
        int ans_right = inf;
        printf("Case #%d:",++cas);
        if(cmp())
        {
            printf(" 0 Any\n");
            continue;
        }
        for(int i =1;i<=32;i++) 
        {
            shift();
            if(cmp()) 
            {
                ans_left = min(ans_left,i);
            }
        }
        for(int i =1;i<=32;i++)
        {
            right_shift();
            if(cmp())
            {
                ans_right = min(ans_right,i);
                break;
            }
        }
        if(ans_left ==inf&&ans_right ==inf)
        {
            printf(" Not possible\n");
        }
        else if(ans_left<ans_right)
        {
            printf(" %d Left\n",ans_left);
        }
        else if(ans_left==ans_right)
        {
            printf(" %d Any\n",ans_left);
        }
        else printf(" %d Right\n",ans_right);
        
    }
    return 0;
}

