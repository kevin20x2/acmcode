


#include <stdio.h>
#include <string.h>
#define N 19
#define MOD 2520
typedef __int64 LL;
int t[200],cnt;
LL dp[N][MOD][48];
int digit[N];
int GCD(int a,int b)
{
    while(a%b)
    {
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return b;
}
int LCM(int a,int b)
{
    return a/GCD(a,b)*b;
}
int bs(int x)
{
    int mid,min=0,max=cnt;
    while(min+1!=max)
    {
        mid=min+max>>1;
        if(t[mid]>x)    max=mid;
        else    min=mid;
    }
    return min;
}
LL dfs(int pos,int mod,int lcmid,int f)
{
    if(pos==-1) return (mod%t[lcmid])?0:1;
    if(!f&&dp[pos][mod][lcmid]!=-1)   return dp[pos][mod][lcmid];
    int max=f?digit[pos]:9;
    LL ret=0;
    for(int i=0;i<=max;i++)
    {
        int nmod=(mod*10+i)%MOD;
        int nlcmid=lcmid;
        if(i)   nlcmid=bs(LCM(t[lcmid],i));
        ret+=dfs(pos-1,nmod,nlcmid,f&&i==max);
    }
    if(!f)  dp[pos][mod][lcmid]=ret;
    return ret;
}
LL cal(LL x)
{
    int pos=0;
    while(x)
    {
        digit[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,0,0,1);
}
void init()
{
    cnt=0;
    for(int i=1;i<=MOD;i++)
    {
        if(MOD%i==0)    t[cnt++]=i;
    }
    memset(dp,-1,sizeof(dp));
}
int main()
{
    int t;
    init();
    scanf("%d",&t);
    while(t--)
    {
        LL x,y;
        scanf("%I64d%I64d",&x,&y);
        printf("%I64d\n",cal(y)-cal(x-1));
    }
    return 0;
}

