/*
 *File:  292c.cpp
 *Date : 2015-02-18 01:48:51
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
int num[4];
int t[4] = {2,3,5,7};
char a[20];
int n;

int main()
{
    scanf("%d",&n);
    scanf("%s",a);
    memset(num,0,sizeof num);
    for(int i =0;i<n;i++)
    {
        int t = a[i]-'0';
        if(t<=1) ;
        else if(t==2) num[0]++;
        else if(t==3) 
        { 
            num[0]++;
            num[1]++;
        }
        else if(t==4) { 
            num[1]++;
            num[0]+=3; 
        }
        else if(t==5) 
        { 
            num[0]+=3;
            num[1]++;
            num[2]++;
        }
        else if(t==6) { 
            num[2]++;
            num[0]+=4;
            num[1]+=2; 
        }
        else if(t==7)
        {
            num[0]+=4;
            num[1]+=2;
            num[2]++;
            num[3]++;
        }
        else if(t==8)
        {
            num[0]+=7;
            num[1]+=2;
            num[2]++;
            num[3]++;
        }
        else if(t==9)
        {
            num[0]+=7;
            num[1]+=4;
            num[2]++;
            num[3]++;
        }
    }
    for(int i =3;i>=0;i--)
    {
        for(int j=0;j<num[i];j++)
        {
            putchar((char)('0'+t[i]));
            if(i==3)
            {
                num[0]-=4;
                num[1]-=2;
                num[2]--;
            }
            if(i==2)
            {
                num[0]-=3;
                num[1]--;
            }
            if(i==1)
            {
                num[0]--;
            }
        }
    }
    putchar('\n');
    return 0;
}

