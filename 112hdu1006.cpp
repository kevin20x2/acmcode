/*
 *File:  112hdu1006.cpp
 *Date : 2014-11-02 13:05:36
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
char str[20] = {"pqruvwxyz"};
int num[20];

using namespace std;

int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int flag  =1;
        for(int i =0;i<10;i++)
         {
            scanf("%d",&num[i]);
            if(num[i]!=0) flag = 0;
         }
        int first = 1;
        if(flag )
        {
            puts("0");
            continue;
        }
        for(int i =0;i<9;i++)
        {
            if(num[i]!=0&&first)
            {
                first = 0;
                if(num[i]==1)
                    printf("%c",str[i]);
                else if(num[i]==-1)
                    printf("-%c",str[i]);
                else 
                printf("%d%c",num[i],str[i]);
            }
            else if(num[i]!=0)
            {
                if(num[i]>0)
                {
                    if(num[i]==1)
                        printf("+%c",str[i]);
                    else 
                    printf("+%d%c",num[i],str[i]);
                }
                else if(num[i]!=-1)printf("%d%c",num[i],str[i]);
                else printf("-%c",str[i]);
                
            }
        }
        if(num[9]>0)
        {
            if(first )
                printf("%d",num[9]);
            else 
            printf("+%d",num[9]);
        }
        else if(num[9]<0)
            printf("%d",num[9]);
        printf("\n");
               
    }
    return 0;
}

