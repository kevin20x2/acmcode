/*
 *File:  9141001.cpp
 *Date : 2014-09-14 12:09:44
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
typedef  long long LL;
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
char app[4][10]={"Apple","iPad","iPod","iPhone"};
char sony[6]="Sony";
int find_str(string& str,int l,int &type)
{
    int ans=inf;
    type = 0;
    for(int i=0;i<4;i++)
    {
        int t;
        if((t=str.find(app[i],l))!=-1)
        {
            ans=min(ans,t);
                type = 1;
        }
    }
    if(str.find(sony,l)!=-1&&str.find(sony,l)<ans)
    {
        ans = str.find(sony,l);
        type =2;
    }
    if(ans==inf)
        return -1;
    else return ans;
}
int main()
{
    string str;
    
    while(cin>>str)
    {
        int l=0;
        int type;
        int t;
        while((t=find_str(str,l,type))!=-1)
        {
            l=t+1;
            if(type == 1) printf("MAI MAI MAI!\n");
            else if(type == 2) printf("SONY DAFA IS GOOD!\n");
        }
    }

    return 0;
}

