/*
 *File:  zoj3829.cpp
 *Date : 2014-10-17 20:22:38
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
stack <int> last;

char str[1010];
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        while(!last.empty()) last.pop();
        int a,b;
        a = 0;b=0;
        int ans = 0;
        scanf("%s",str);
        for(int i =0;i<strlen(str);i++)
        {
            if(str[i]=='*') a++;
            else last.push(i);
        }
        if(a+1>last.size()) ans = a+1-last.size();
        int t = ans;
        for(int i =0;i<strlen(str);i++)
        {
            if(str[i]=='*'&&t>1) --t;
            else if(str[i]=='*'&&t<=1) 
            {
                str[i] = str[last.top()];
                str[last.top()] = '*';
                last.pop();
                ans++; 
                t++;
            }
            else ++t;
        }
        printf("%d\n",ans);

        
    }
    return 0;
}

