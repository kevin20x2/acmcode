/*
 *File:  1004.cpp
 *Date : 2014-09-27 13:06:39
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 2 
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)
#define MAXN 11
#define eps 1e-6

using namespace std;
int T;
double a[11][1050];
int n,m;
int nx,ny;
int match[MAXN];
double lx[MAXN],ly[MAXN],slack[MAXN];
int visx[MAXN],visy[MAXN];
double w[MAXN][MAXN];
int dfs(int x)
{
    visx[x] = 1;
    for(int y = 1;y <= ny;y++)
    {
        if (visy[y])
            continue;
        double t = lx[x] + ly[y] - w[x][y];
        if(t <eps)
        {
            visy[y] = 1;
            if(match[y] == -1|| dfs(match[y]))
            {
                match[y] = x;
                return 1;
            }
        }
        else if(slack[y] > t)
            slack[y] = t;
    }
    return 0;
}
double km()
{
    int i,j;
    memset(match,-1,sizeof(match));
    memset(ly,0,sizeof(ly));
    for(i=1;i<=nx;i++)
        for(j=1,lx[i] = -inf;j <= ny; j++)
            lx[i]=max(lx[i],w[i][j]);
    for (int x = 1 ;x <= nx;x ++)
    {
        for(i = 1;i <= ny;i ++)
            slack[i] = inf;
        while(1)
        {
            memset (visx,0,sizeof(visx));
            memset (visy,0,sizeof(visy));
            if(dfs(x))
                break;
            double d= inf;
            for(i = 1;i <= ny;i ++)
                if(!visy[i]&&d > slack[i])
                    d = slack[i];
            for(i = 1;i <= nx;i ++)
                if(visx[i])
                    lx[i] -= d;
            for(i = 1;i <= ny;i ++)
                if(visy[i])
                    ly[i] += d;
            else 
                slack[i] -= d;
        }

    }
    double res = 0;
    for(i = 1;i <= ny;i ++)
        if( match[i] > -1)
            res += w[match[i]][i];
    return res;
        
}
int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        double sum=0;
        clr(a);
        clr(w);
        printf("Case #%d: ",cas);
       scanf("%d%d",&n,&m); 
       loop(i,1,n)
       {
            loop(j,1,m)
            {
                scanf("%lf",&a[i][j]);
            }
       }
       loop(i,1,m/n+1)
       {
           loop(t,1,n){
               loop(j,1,n)
               {
                   w[t][j] = a[t][(i-1)*n+j];
                   //printf("%f ",w[t][j]);
               }
           }
           nx=ny= n;
           sum+=km();
       }
       printf("%.5f\n",sum);
    }
    return 0;
}

