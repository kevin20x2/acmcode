/*
 *File:  cfdiv281c.cpp
 *Date : 2014-12-14 01:53:41
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
#define maxn 100010
char str[maxn];

int main()
{
    scanf("%s",str);
    int l =0;
    int r = 0;
    for(int i= strlen(str)-1;i>=0;i--)
    {
        if(str[i]=='(') l++;
        else if(str[i]==')') r++;
        else if(str[i]=='#')
        {
            if(l>r) { 
                puts("-1");
                return 0;
            }
            break;
        }
    }
    l=r=0;
    int lnum=0;
    int rnum =0;
    int mnum = 0;
    for(int i =0;i<strlen(str);i++)
    {
        if(str[i]=='(') lnum++;
        if(str[i]==')') rnum++;
        if(str[i]=='#') mnum++;
    }
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='(') l++;
        else if(str[i]==')') r++;
        else if(str[i]=='#') r++;
        if(r>l) 
        {
            puts("-1");
            return 0;
        }
        
    }
    for(int i=1;i<mnum;i++)
        printf("%d\n",1);
    printf("%d\n",lnum-rnum-(mnum-1));
    return 0;
}

