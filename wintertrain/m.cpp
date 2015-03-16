/*
 *File:  m.cpp
 *Date : 2015-03-01 13:22:05
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
typedef  long long LL;
using namespace std;
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
struct seg {
    int line,p;
    seg(int a,int b):line(a),p(b){
    }
};
int n;
stack <seg > s[30];
stack <int > s2[3000];
string str[55];


int main()
{
    scanf("%d\n",&n);
    int b = 1;
    for(int i =1;i<=n;i++)
    {
        getline(cin,str[i]);
        for(int j= 0;j<str[i].length();j++) if(str[i][j]!=' ')
        {
            if(str[i][j]=='{')
                b++;
            else if(str[i][j]=='}')
            {
                while(!s2[b].empty())
                {
                    int t = s2[b].top();
                    s[t].pop();
                    s2[b].pop();
                }
                b--;
            }
            else {
                if(!s[str[i][j]-'a'].empty())
                {
                    seg tmp = s[str[i][j]-'a'].top();
                    printf("%d:%d: warning: shadowed declaration of %c, the shadowed position is %d:%d\n",i,j+1,str[i][j],tmp.line,tmp.p);
                }
                s[str[i][j]-'a'].push(seg(i,j+1));
                s2[b].push(str[i][j]-'a');
            }
            
        }
    }

    return 0;
}

