/*
 *File:  neuqj.cpp
 *Date : 2014-11-29 10:12:24
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

int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
        if(c>='A'&&c<='Z') putchar(c);
        else if(c>='a'&&c<='z') putchar(c);
        else if(c==' '||c=='\n') putchar(c);
    }
    printf("\n");
    return 0;

}

