/*
 *File:  2006shanghaid.cpp
 *Date : 2014-12-27 13:29:22
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;
#define maxn 105
int numx[maxn][maxn];
int numy[maxn][maxn];
int px[maxn];
int py[maxn];
map <int ,int > mx;
map <int ,int> my;
set <int > x;
set <int > y;
bool on[maxn][maxn];
int n;

int main()
{
    int a,b;
    int cas = 0;
    while(~scanf("%d",&n)&&n)
    {
       x.clear();y.clear();
       mx.clear();my.clear();
       memset(on,0,sizeof on);
       memset(numx,0,sizeof numx);
       memset(numy,0,sizeof numy);
       for(int i =1;i<=n;i++) 
       {
           scanf("%d%d",&a,&b);
           px[i]=a;py[i]= b;
           x.insert(a); y.insert(b);
       }
       int t = 1;
       for(set <int > :: iterator it = x.begin();it!=x.end();it++,t++)
       {
           mx[*it] = t;
         //  printf("x:%d %d\n",*it,t);
            
       }
       int maxx = t;
       t = 1;
       for(set <int >:: iterator it = y.begin();it!=y.end();it++,t++)
       {
           my[*it] = t;
        //   printf("y:%d %d\n",*it,t);
       }
       int maxy =t;
       for(int i = 1;i<=n;i++)
       {
           on[mx[px[i]]][my[py[i]]] = true;
       //    printf("on:%d %d\n",mx[px[i]],my[py[i]]);
       }
       for(set <int> ::iterator it = x.begin();it!=x.end();it++)
       {
           for(int i = 1;i<=n;i++)
           {
               if(px[i]==*it)
               {
                   for(int j =maxy-1;j>=my[py[i]];j--)
                       numx[mx[*it]][j]++;
               }
           }
       }
       
       for(set <int >::iterator it = y.begin();it!=y.end();it++)
       {
        for(int i = 1;i<=n;i++)
        {
            if(py[i]==*it)
            {
                for(int j = maxx-1;j>=mx[px[i]];j--)
                    numy[my[*it]][j]++;
            }
        }
       }
       int ans = 0;
     //  printf("%d %d",maxx,maxy);
      // printf("%d ",numy[my[4]][9]);
      if(maxx==2) {
            ans+=numx[1][maxy-1];
      }
      else if(maxy==2) ans+=numy[1][maxx-1];
       for(int i =1;i<maxx;i++)
       {
           for(int j = 1;j<i;j++)
           {
               for(int k =1;k<maxy;k++ )
               {
                   for(int t = 1;t<k;t++)
                   {
                       int tmp = 0;
                       tmp+=numx[i][k]-numx[i][t-1];
                       tmp+=numx[j][k]-numx[j][t-1];
                       tmp+=numy[k][i]-numy[k][j-1];
                       tmp+=numy[t][i]-numy[t][j-1];
                       if(on[i][k]) tmp--;
                       if(on[i][t]) tmp--;
                       if(on[j][t]) tmp--;
                       if(on[j][k]) tmp--;
                       ans = max(ans,tmp);
                      /* if(ans == tmp )
                      {
                           printf("%d %d %d %d\n",i,j,k,t);
                       }
                       */
                   }
               }
           }
       }
       printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

