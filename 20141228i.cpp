/*
 *File:  20141228i.cpp
 *Date : 2014-12-28 12:44:30
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
#define maxn 100050

int T;
int n;
int a[maxn];
bool W[maxn];
int main()
{
    char c[2];
    int x;
    scanf("%d",&T);
    while(T--)
    {
        int numb=0;
        int numw=0;
        memset(W,0,sizeof W);
        scanf("%d",&n);
        for(int i =1;i<=n;i++)
        {
            scanf("%d%s",&a[i],c);
            if(c[0]=='W')
            {
                W[i] = true;
                numw+=a[i];
            }else numb+=a[i];
        }
        int ans =0;
        if(numw==0||numb==0)
        {
            printf("%d\n",numw+numb);
            continue;
        }
        LL sumw =0; 
        LL sumb =0;
        for(int i=1;i<=n;i++)
        {
            if(W[i])
            {
                if(sumw*numb<sumb*numw)
                {
                    LL t = sumb*numw/numb;
                    LL mod = sumb*numw%numb;
                    if(mod==0&&1LL*a[i]>=(t-sumw))
                    {
                        sumw = a[i]-(t-sumw);
                        sumb = 0;
                        ans++;
                    }
                    else sumw+=1LL*a[i];
                }
                else 
                sumw+=1LL*a[i];
            }
            else
            { 
                if(sumb*numw<sumw*numb)
                {
                    int t = sumw*numb/numw;
                    int mod = sumw*numb%numw;
                    if(mod==0&&a[i]>=(t-sumb))
                    {
                        sumb = a[i]-(t-sumb);
                        sumw = 0;
                        ans++;
                    }
                    else sumb +=1LL*a[i];
                }
                else 
                sumb+=1LL*a[i];
            }
            //printf("%d %d\n",sumw,sumb);
        }
        printf("%d\n",ans);

        
    }
    return 0;
}

