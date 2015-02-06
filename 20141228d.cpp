/*
 *File:  20141228d.cpp
 *Date : 2014-12-28 16:09:10
 */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
struct lunzi
{
    double x,y;
    double r;
    int fangxiang;
    int speed[2];

}a[10005];
vector <int> v[1005];
bool vis[1005];
int gcd(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b,b=r;
        r=a%b;
    }
    return b;
}
void dfs(int x)
{
    vis[x] =1;
    for(int i =0;i<v[x].size();i++) if(!vis[v[x][i]])
    {
        int t = v[x][i];
        if(a[x].speed[0]!=0&&a[t].speed[0]==0){
            a[t].speed[0]=a[x].r*a[x].speed[0];
            a[t].speed[1]=a[t].r*a[x].speed[1];
        }
        if(a[x].fangxiang==1)
            a[t].fangxiang=0;
        else if(a[x].fangxiang==0)
            a[t].fangxiang=1;
        dfs(t);
    }
    
}



int main()
{
    int t;
    int cas=0;
    scanf("%d",&t);
    while(t--)
    {
        cas++;
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof a);
        memset(vis,0,sizeof vis);
        for(int i =0;i<n;i++)
            v[i].clear();
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r),a[i].speed[0]=a[i].speed[1]=0,a[i].fangxiang=-1;
        a[0].speed[0]=a[0].speed[1]=1;
        a[0].fangxiang=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) if(i!=j)
            {
                double dis=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
                if(dis==(a[i].r+a[j].r))
                {
                    v[i].push_back(j);
                    v[j].push_back(i);
                }

            }
        }
        dfs(0);
        for(int i=0;i<n;i++)
        {
            if(a[i].speed[0]==0)
                printf("not moving\n");
            else
            {
                if(a[i].speed[0]%a[i].speed[1]==0)
                    printf("%d ",a[i].speed[0]/a[i].speed[1]);
                else
                {
                    int r=gcd(a[i].speed[0],a[i].speed[1]);
                    a[i].speed[0]/=r;
                    a[i].speed[1]/=r;
                    printf("%d/%d ",a[i].speed[0],a[i].speed[1]);
                }
                if(a[i].fangxiang==1)
                    printf("clockwise\n");
                else
                    printf("counterwise\n");
            }
        }
    }
    return 0;
}

