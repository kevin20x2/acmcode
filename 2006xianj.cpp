/*
 *File:  2006xianj.cpp
 *Date : 2014-12-06 18:56:19
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
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
char g[6][12];
bool vis[6][12];
char a[4][7] ={" _ _ ",
               "|   |",
               "|_ _|"};
bool judge(int x,int y)
{
    for(int i =0;i<3;i++)
        for(int j =0;j<5;j++)
        {
            if(i==0&&(j==0||j==2||j==4))
            {
                if(g[x+i][y+j]==' '||g[x+i][y+j]=='|'||g[x+i][y+j]=='a');
            }
            else if(g[x+i][y+j] != a[i][j]&&g[x+i][y+j]!='a')
                return false ;

        }
    return true;
}
void change(int x,int y)
{
    for(int i=0;i<3;i++)
        for(int j = 0;j<5;j++)
        {
            if(i==0&&(j==0||j==2||j==4))
                ;
            else 
            g[x+i][y+j] ='a';
        }
}
bool over()
{
     bool  ans = 1;
       for(int i=1;i<=5;i++)
           for(int j =1;j<=8;j++)
               if(g[i][j]!='a'&&g[i][j]!=' ')
               {
                   ans = 0;
                   break;
               } 
       return ans;
    
}

int main()
{
    int cas= 0;
    while(gets(&g[1][1])&&g[1][1]!='0')
    {
       for(int i =2;i<=5;i++) 
           gets(&g[i][1]);
       int t =1;
       memset(vis,0,sizeof(vis));
       for(int i =1;i<=5;i++)
           for(int j = 1;j<=9;j++)
           {
               if((g[i][j] == ' '||g[i][j]=='|')&&(g[i][j+1] =='_')&&g[i+1][j] == '|')
                   vis[i][j] =1;
               if(i>2&&(g[i][j] == '|'&&g[i][j+1]=='_'))
                   vis[i-2][j]=1;
               if(j>4&&(g[i][j]==' '||g[i][j]=='|')&&g[i+1][j]=='|'&&g[i][j-1]=='_')
                   vis[i][j-4] = 1;
               if(i>2&&j>4&&g[i][j]=='|'&&g[i][j-1] == '_')
                   vis[i-2][j-4]= 1;
           }
       int res = 7;
       bool ans=0;
       while(res )
       {
           if(ans=over())
               break;
           int j;
           int t = res;
           for(int i =1;i<=3;i++)
           {
               for(j = 1;j<=5;j++) if(vis[i][j])
                   if(judge(i,j)==true)
                   {
                       res --;
                       vis[i][j] = 0;
                       change(i,j);
                      // for(int t = 1;t<=5;t++)
                        //   printf("%s\n",&g[t][1]);
                   }
           }
           if(t==res) break;
       }
            if(ans == 1)
           printf("Case %d: Yes\n",++cas);
       else printf("Case %d: No\n",++cas);

    }
    return 0;
}

