/*
 *File:  wintertrainA2.cpp
 *Date : 2015-01-04 17:04:47
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;
struct seg{
    int num,c;
    friend bool operator <(seg a,seg b)
    {
       if(a.num<b.num) return false ;
       else if(a.num==b.num&&a.c>b.c) return false;
       return true;
    }
    seg(int num,int c):num(num),c(c){}
};
set <seg> s;
int n,m,k;
int vis[6][6];

int main()
{
    int T;
    scanf("%d",&T);
    int cas = 0;
    int x;
    while(T--)
    {
        memset(vis,0,sizeof vis);
        scanf("%d%d%d",&n,&m,&k);
        s.clear();
        bool flag = 0;
        for(int i =1;i<=k;i++)
        {
            scanf("%d",&x);
            s.insert(seg(x,i));
        }
        for(set <seg>::iterator it = s.begin();it!=s.end();it++)
            printf("%d %d\n",it->num,it->c);
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
                set <seg> :: iterator it= s.begin();
                while(it!=s.end())
                {
                    if(it->num ==0) {it++;continue;}
                    if(i!=1&&vis[i-1][j]==(*it).c) {it++;continue;}
                    if(j!=1&&vis[i][j-1]==(*it).c) {it++;continue;}
                    vis[i][j] = it->c;
                    printf("%d ",vis[i][j]);
                    seg *t = new seg(it->num-1,it->c);
                    s.erase(it);
                    s.insert(*t);
                    break;
                }
                if(it==s.end()) flag = 1;
                
            }
            if(flag ) break;
            printf("\n");
        }
        printf("Case #%d\n",++cas);
        if(flag) puts("NO");
        else {
            puts("YES");
            for(int i =1;i<=n;i++)
            {
                int first = 1;
                for(int j = 1;j<=m;j++)
                    if(first)
                    {
                        printf("%d",vis[i][j]);
                        first  =0;
                    }else printf(" %d",vis[i][j]);
                printf("\n");
            }
        }
        
    }
    return 0;
}

