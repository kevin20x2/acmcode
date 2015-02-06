/*
 *File:  help.cpp
 *Date : 2014-10-05 20:17:52
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdlib>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;


int main()
{
    char sb[200];
    long long a,b;
    while(scanf("%s",sb)!=EOF)
    {
        scanf("%I64d %I64d",&a,&b);
        int p=0;
        while(sb[p]==' ')
            p++;
        if(sb[p]=='-'&&sb[1+p]=='0')
        {
            puts("NO1");
            continue;
        }
        bool flag=true;
        for(int i=p+1;i<strlen(sb);i++)
        {
            if(sb[i]<'0'||sb[i]>'9')
            {
                flag=false;
                break;

            }
        }
        if(!flag)
        {
            puts("NO2");
            continue;
        }
        if(sb[p]=='0'&&sb[p+1]>='0'&&sb[p+1]<='9')
        {
            puts("NO3");
            continue;

        }

        if(strlen(sb)>12)
        {
            puts("NO");
            continue;
        }
        long long ans=atoll(sb);
        printf("%I64d",ans);
        if(ans>=a&&ans<=b)
            puts("YES");
        else
            puts("NO");



    }
    return 0;
}

