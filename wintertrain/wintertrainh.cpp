/*
 *File:  wintertrainh.cpp
 *Date : 2015-01-17 18:03:45
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
const int maxn = 110;
using namespace std;
bool vis[1000];
int prime[110];
int tot;
int a[maxn][maxn];
int n,m;
char ans[100];
void getprime()
{
    tot = 0;
    memset(vis,0,sizeof vis);
    for(int i = 2;tot<101;i++)
    {
        if(!vis[i])
        {
            prime[tot++] = i;
        }
        for(int j = 0;(j<tot&&i*prime[j]<=1000);j++)
        {
            vis[i*prime[j] ]=1;
            if(i%prime[j]==0) break;
        }
    }
}
int rank()
{
    int i = 0,j = 0,k,r,u;
    while(i<m &&j<n)
    {
        r = i;
        for(k = i;k<m;k++)
           if(a[k][j]) {r = k;break;}
        if(a[r][j])
        {
            if(r!=i) for(k=0;k<=n;k++) swap(a[r][k],a[i][k]);
            for(u = i+1;u<m;u++) if(a[u][j])
                for(k=i;k<=n;k++) a[u][k] ^= a[i][k];
            i++;
        }
        j++;
    }
    return i;
}
void getans(int x)
{
    if(x==0) {ans[0]='0',ans[1]='\0';return ;}
    while(x--)
    {
        int len = strlen(ans);
        int up = 0;
        for(int i = 0;i<len;i++)
        {
            int t = ans[i]-'0';
            ans[i] = (char)((t*2+up)%10+'0');
            up= (t*2+up)/10;
            if(up&&i==len-1)
            {
                ans[len] = '1';
                ans[len+1]= '\0';
            }
        }
    }
    ans[0]--;

    
}


int main()
{
    getprime();
   // for(int i =0;i<100;i++)
      //  cout<<prime[i]<<' ';
    int T;
    scanf("%d",&T);
    int first = 1;
    while(T--)
    {
        memset(a,0,sizeof a);
        int x;
        scanf("%d%d",&m,&n);
        for(int i =0;i<n;i++)
        {
            scanf("%d",&x);
            for(int j = 0;j<m;j++)
                while(x%prime[j]==0) {
                    x/=prime[j];
                    a[j][i] ^=1;
                }
        }
        int r = rank();
        if(first)
        {
           first = 0;
        }else printf("\n");
        ans[0] = '1';ans[1]='\0';
        getans(n-r);
        int sum = strlen(ans);
        for(int i=sum-1;i>=0;i--)
            putchar(ans[i]);
        printf("\n");

        
    }
    return 0;
}

