/*
 *File:  a.cpp
 *Date : 2015-03-08 12:23:59
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
int n;
char str[15][15];
bool zero[26];
bool vis[29];
bool visnum[10];
vector <int > v;
int Hash[30];
int ans;
bool count()
{
    int sum =0;
    for(int i =1;i<=n-1;i++)
    {
        int t = strlen(str[i]);
        int tmp=0;
        for(int j=0;j<t;j++)
        {
            tmp=tmp*10+(Hash[str[i][j]-'A']);
        }
        sum+= tmp;
    }
    int t = strlen(str[n]);
    int result = 0;
    for(int i =0;i<t;i++)
    {
        result = result*10+(Hash[str[n][i]-'A']);
    }
    return sum==result;

}
void dfs(int x)
{
    if(x==v.size())
    {
        ans+=count();
        /*for(int i =0;i<v.size();i++) if(count())
        {
            printf("%d ",Hash[v[i]]);
        }
        printf("\n");
        */
        return ;
        
    }
    for(int i =0;i<10;i++) if(!visnum[i])
    {
        if(zero[v[x]]&&i==0)
            continue;
        visnum[i]=1;
        //printf("%d ",i);
        Hash[v[x]] = i;
        dfs(x+1);
        visnum[i]=0;
    }

        
}

int main()
{
    while(~scanf("%d",&n))
    {
        v.clear();
        ans =0 ;
        memset(vis,0,sizeof vis);
        memset(zero,0,sizeof zero);
        for(int i =1;i<=n;i++)
        {
            scanf("%s",str[i]);
            int t = strlen(str[i]);
            for(int j = 0;j<t;j++) if(!vis[str[i][j]-'A'])
            {
                if(j==0) zero[str[i][j]-'A'] = true;
                vis[str[i][j]-'A'] = 1;
                v.push_back(str[i][j]-'A');
            }
        }
        memset(visnum,0,sizeof visnum);
        dfs(0);
        printf("%d\n",ans);
    }
    

    return 0;
}

