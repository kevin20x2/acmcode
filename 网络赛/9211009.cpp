/*
 *File:  9211009.cpp
 *Date : 2014-09-21 14:06:19
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<queue>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)
using namespace std;
struct seg{
    int x,y;
    int type;
    int moving;
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char dir[5]={"SNEW"};
char g[502][502];
bool insight[4][502][502];
vector <seg> ca;
queue <seg> q;
int vis[4][502][502];
int n;
int T;
void update(int x)
{
    clr(insight[x]);
    for(int i=0;i<ca.size();i++)
    {
        insight[x][ca[i].x][ca[i].y]=true;
        char &c = g[ca[i].x][ca[i].y];
        if(c=='N') c='E';
        else if(c=='E') c='S';
        else if(c=='S') c= 'W';
        else if(c=='W') c='N';
        loop(k,0,3) if(c==dir[k]) 
        {
            int ansx = ca[i].x+dx[k];
            int ansy = ca[i].y+dy[k];
            if(ansx>=1&&ansx<=n&&ansy>=1&&ansy<=n)
                insight[x][ansx][ansy]=true;
        }
    }
}
int bfs(seg x)
{
    while(!q.empty())
        q.pop();
    q.push(x);
    int ans = 0;
    vis[x.type][x.x][x.y]=0;
    seg t;
    int tsize =1;
    int size =0;
    while(!q.empty())
    {
        size = tsize;
        tsize = 0;
        loop(i,1,size)
        {
           t=q.front(); 
          // printf("%d %d %d %d\n",t.x,t.y,t.type,t.moving);
           q.pop();
           
           if(t.moving>0)
           {
                t.type = (t.type+1)%4;
                t.moving--;
                q.push(t);
                tsize++;
                continue;
           }
           if(g[t.x][t.y]=='T')
               return ans;
           loop(j,0,3)
           {
            int ansx = t.x+dx[j];
            int ansy = t.y+dy[j];
            if(ansx>=1&&ansx<=n&&ansy>=1&&ansy<=n&&g[ansx][ansy]!='#')
            {
                seg temp;
                temp.x=ansx;temp.y=ansy;temp.type=(t.type+1)%4;temp.moving=t.moving;
                if((insight[t.type][t.x][t.y]==true||insight[t.type][ansx][ansy]==true)&&(ans+3<vis[temp.type][ansx][ansy]))
                {
                   vis[temp.type][ansx][ansy]=ans+3;
                   temp.moving = 2;
                   q.push(temp);
                   tsize++;
                }
                else if(ans<vis[temp.type][ansx][ansy]&&(insight[t.type][t.x][t.y]==false)&&insight[t.type][ansx][ansy]==false){
                    vis[temp.type][ansx][ansy]=ans;
                    q.push(temp);
                    tsize++;
                }
            }
           }
           t.type= (t.type+1)%4;
           if(ans<vis[t.type][t.x][t.y])
           {
               vis[t.type][t.x][t.y]=ans;
               q.push(t);
               tsize++;
           }
        }
        ans++;
     // printf("\n");
        
    }
    return -1;
    
}
int main()
{
    scanf("%d",&T);
    loop(cas,1,T)
    {
        ca.clear();
        memset(vis,0x3f,sizeof(vis));
        clr(insight);
        scanf("%d",&n);
        seg t;
        loop(i,1,n)
        {
            scanf("%s",&g[i][1]);
            loop(j,1,n)
            {
                if(g[i][j]=='M')
                {
                    t.x=i,t.y=j;
                    t.type=0;t.moving=0;
                }
                else
               loop(k,0,3) if(g[i][j]==dir[k]) 
               {
                   seg temp;
                   temp.x=i;temp.y=j;
                   temp.type =0;temp.moving=0;
                   ca.push_back(temp);
                   int ansx = i+dx[k];
                   int ansy = j+dy[k];
                   insight[0][i][j]=true;
                   if(ansx>=1&&ansx<=n&&ansy>=1&&ansy<=n)
                       insight[0][ansx][ansy]=true;
               }
            }
        }
        loop(i,1,3)
           update(i);
        /*loop(i,0,3)
            loop(j,1,n){
                loop(k,1,n)
                    printf("%d ",insight[i][j][k]);
                printf("\n");
            }
            */
        printf("Case #%d: %d\n",cas,bfs(t));
        
    }

    return 0;
}

