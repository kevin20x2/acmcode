/*
 *File:  913overt.cpp
 *Date : 2014-09-13 12:39:05
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
int T;
char op[42][3];
int n;
unsigned int num[42];
unsigned int f()
{
    unsigned temp;
    unsigned sum=0;
    int s;
    for(int t=0;t<8;t++){
        unsigned int res = 0;
        temp=(0xf<<(t*4));
        for(int i=0;i<16;i++)
        {
            unsigned int ans=i;
            for(int j=1;j<=n;j++){
                switch(op[j][0])
                {
                    case '+':
                        ans+=(num[j]&temp)/(int)pow(16,t);
                        ans%=16;
                        break;
                    case '-':
                        s = (num[j]&temp)/(int)pow(16,t);
                        ans=ans<s?ans+16-s:ans-s;
                        ans%=16;
                        break;
                    case '&':
                        ans=ans&((num[j]&temp)/(int)pow(16,t));
                        ans%=16;
                        break;
                    case '^':
                        ans=ans^((num[j]&temp)/(int)pow(16,t));
                        ans%=16;
                        break;
                    case '|':
                        ans=ans|((num[j]&temp)/(int)pow(16,t));
                        ans%=16;
                        break;
                }
            }
            res = max(res,ans%16);
        }
        sum+=res*pow(16,t);
    }
}
int main()
{
    scanf("%d",&T);
    while(T--){
        unsigned int res=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%s%x",op[i],&num[i]);
        }
        unsigned ans=f();
        printf("%x\n",ans);
        
    }
    return 0;
}

