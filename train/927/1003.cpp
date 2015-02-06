/*
 *File:  1003.cpp
 *Date : 2014-09-27 16:08:29
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
int id[100050];
int fa[100050];
int co_id[100050];
vector <int > a[100050];
bool vis[100050];
int last[100050];
int n,m;
int T;
int x,y,v;
int res;
char str[10];
int value[100050];
vector < pair<int ,int> > edge;
int edge_value[100050];

void topsort(int x)
{
    vis[x]=true;
    id[x]=res;
    co_id[res] = x;
    res++;
    for(int i=0;i<a[x].size();i++) if(!vis[a[x][i]])
    {
        fa[a[x][i]] = x;
        topsort(a[x][i]);
    }
    last[id[x]]=res;
}
int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        printf("Case #%d:\n",cas);
        scanf("%d%d",&n,&m);
        loop(i,1,n)
            a[i].clear();
        loop(i,1,n-1)
        {
            scanf("%d%d",&x,&y);
            a[x].push_back(y);
            a[y].push_back(x);
            edge.push_back(make_pair(min(x,y),max(x,y)));
        }
        res = 1;
        clr(vis);
        clr(value);
        clr(id);
        clr(co_id);
        clr(fa);
        clr(last);
        fa[1]= -1;
        topsort(1);
        loop(i,1,m)
        {
            scanf("%s",str);
            if(str[3]=='1')
            {
                scanf("%d%d%d",&x,&y,&v);
                int maxn = max(id[x],id[y]);
                int minn = min(id[x],id[y]);
                if(maxn<last[minn])
                {
                    int l = maxn;
                    while(l!=minn)
                    {
                        value[co_id[l]]+=v;
                        l=id[fa[co_id[l]]];
                    }
                    value[co_id[l]]+=v;
                   continue; 
                }
                else 
                {
                    int l =maxn;
                    while(l>minn)
                    {
                        value[co_id[l]]+=v;
                        l=id[fa[co_id[l]]];
                    }
                    int r = minn;
                    while(r!=l)
                    {
                        value[co_id[r]]+=v;
                        r=id[fa[co_id[r]]];
                    }
                    value[co_id[l]]+=v;
                    continue;
                }
                
            }
            else if(str[3]=='2')
            {
                scanf("%d%d%d",&x,&y,&v);
                int maxn = max(id[x],id[y]);
                int minn = min(id[x],id[y]);
                if(maxn<last[minn])
                {
                    int l = maxn;
                    while(l!=minn)
                    {
                        edge_value[]+v=;
                        l=id[fa[co_id[r]]];
                    }
                    
                }
                
            }
        }
        loop(i,1,n)
            printf(" %d",value[i]);
        printf("\n");
    }
    return 0;
}

