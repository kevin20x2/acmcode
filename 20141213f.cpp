/*
 *File:  20141213f.cpp
 *Date : 2014-12-13 12:50:49
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
int T;
char g[200][255];
int num[200];
int res,tot;
int sum[200];
int a,b,c,d,e;
int f(char *p)
{
    int t = strlen(p);
    if(t>6)
        return 3;
    else if(t==6)
    {
        for(int i =0;i<t-1;i++)
            if(p[i]=='n'&&(p[i+1]=='y'||p[i+1]=='g'))
                return 2;
        return 3;
    }
    else if(t>=4&&t<=5) return 2;
    else if(t==3&&(p[0]=='a'||p[0]=='e'||p[0]=='i'||p[0]=='o'||p[0]=='u'||p[0]=='A'||p[0]=='E'||p[0]=='I'||p[0]=='O'||p[0]=='U'))
        return 2;
    else return 1;
}
void count()
{
    num[0] = 0;
    for(int i =1;i<=res;i++)
    {
        sum[i] = 0;
        for(int j=num[i-1]+1;j<=num[i];j++)
        {
            sum[i]+=f(g[j]);
        }
        if(sum[i]>=8&&sum[i]<=12&&i<=4)
            a+=10;
    }
    int t[res+1];
    for(int i = 1;i<=res;i++)
    {
        t[i] = strlen(g[num[i]]);
    }
    
    for(int i =1;i<=min(res/2,2);i++)
    {
        if(i+2<=res)
        {
            if(g[num[i]][t[i]-2]==g[num[i+2]][t[i+2]-2]&&g[num[i]][t[i]-1]==g[num[i+2]][t[i+2]-1])
                b+=20;
            if(sum[i]==sum[i+2]) c+=10;
        }
    }
    if(res>4)
    d = 10*(res-4);
    e = a+b+c-d;
    
}

char p;
int main()
{
    scanf("%d",&T);
    int cas =0;
    while(T--)
    {
        memset(g,0,sizeof(g));
        memset(num,0,sizeof(num));
        tot = 1;
        res = 1;
        a=b=c=d=e=0;
        int l =0;
        int flag = 0;
        while((p=getchar())==' '||p=='\n');
        do
        {
            if(p!=' '&&p!=','&&p!='.'&&p!='\n')
            {
                if(flag == 1)
                {
                    g[tot][l]='\0';
                    tot++;
                    l=0;
                }
                g[tot][l++]= p;
                flag = 0;
            }
            else if(p==' '||p==','||p=='\n')
            {
                if(p==',')
                    num[res++] = tot;
                flag = 1;
            }
            else if(p=='.')
            {
                num[res] = tot;
                break;
            }
            
        }while((p=getchar())!=EOF);
        count();
        printf("Case #%d: %d %d %d %d %d\n",++cas,a,b,c,d,e);
        
    }
    return 0;
}

