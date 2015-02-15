/*
 *File:  291a.cpp
 *Date : 2015-02-15 00:32:34
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
char str[20];

int main()
{
    scanf("%s",str);
    int n = strlen(str);
    for(int i =0;i<n;i++)
        if(str[i]>='5')
        {
            if(i!=0||str[i]!='9')
            str[i] = '0'+(9-(str[i]-'0'));
        }
    printf("%s\n",str);
    return 0;
}

