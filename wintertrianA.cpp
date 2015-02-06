/*
 *File:  wintertrianA.cpp
 *Date : 2015-01-04 15:11:28
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
#define maxn 26 
struct seg{
    int num,c;
}used[maxn];
int vis[6][6];
int n,m,k;
bool flag;
int cmp(seg a,seg b)
{
    return a.num>b.num;
}
int dfs(int dep,int x)
{
  
   // printf("%d %d %d\n",dep,x,color);
    if(dep==n+1)
    {
        return 1;
    }
    if(x==m+1)
    {
        return dfs(dep+1,1);
    }
    for(int i =1;i<=k;i++)  if(used[i].num>0)
    {
        if(x>1&&vis[dep][x-1]==i)
            continue;
        if(dep>1&&vis[dep-1][x]==i)
            continue;
        if(x>m&&vis[dep][1]==i)
            continue;
        vis[dep][x] = i;
        used[i].num--;
        if(dfs(dep,x+1))
        return 1;
        used[i].num++;
    }
    return 0;
}

int main()
{
    int T;
    int cas = 0;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof vis);
        flag = 0;
        scanf("%d%d%d",&n,&m,&k);
        int MAX = (n*m+1)/2;
        for(int i =1;i<=k;i++)
        {
            scanf("%d",&used[i].num);
            used[i].c=i;
        }
        sort(used+1,used+k+1,cmp);
        printf("Case #%d:\n",++cas);
        if(used[1].num>MAX)
        {
            puts("NO");
            continue;
        }
        if(dfs(1,1) ) 
        {
            puts("YES");
            for(int i =1;i<=n;i++)
            {
                int first = 1;
                for(int j =1;j<=m;j++)
                {
                    if(first )
                    {
                        printf("%d",used[vis[i][j]].c);
                        first = 0;
                    }
                    else printf(" %d",used[vis[i][j]].c);
                }
                printf("\n");
            }
        }
        else puts("NO");
    }
    return 0;
}

