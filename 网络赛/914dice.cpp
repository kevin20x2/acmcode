/*
 *File:  914dice.cpp
 *Date : 2014-09-14 13:05:03
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
typedef  long long LL;
#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
 void lr(struct dice &a,struct dice & temp);
void rr(struct dice & a,struct dice & temp);
void fr(struct dice &a,struct dice &temp);
void br(struct dice &a,struct dice &temp);
void (*p[4])(struct dice &,struct dice &);
struct dice {
    int a[7];
    int * t ;
    int * b ;
    int * l ;
    int * r ;
    int * f ;
    int * ba;
    bool judge(struct dice & o);
    dice ()
    {
        t = &a[1];
        b = &a[2];
        l = &a[3];
        r = &a[4];
        f = &a[5];
        ba = &a[6];
    }
    void input(){
        for(int i=1;i<=6;i++)
            scanf("%d",&a[i]);
    }
    void out()
    {
        for(int i=1;i<=6;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    int operator == (dice & o)
    {
        for(int i=1;i<=6;i++)
            if(a[i]!=o.a[i])
                return 0;
        return 1;
    }
   

};
    bool dice::judge(struct dice & o)
    {
        int ada[7][5];
        int ado[7][5];
        ada[*l][1]=*t;ada[*l][2]=*f;ada[*l][3]=*b;ada[*l][4]=*ba;
        ada[*r][1]=*t;ada[*r][2]=*f;ada[*r][3]=*b;ada[*r][4]=*ba;
        ada[*f][1]=*t;ada[*f][2]=*l;ada[*f][3]=*b;ada[*f][4]=*r;
        ada[*ba][1]=*t;ada[*ba][2]=*l;ada[*ba][3]=*b;ada[*ba][4]=*r;
        ada[*t][1]=*l;ada[*t][2]=*f;ada[*t][3]=*r;ada[*t][4]=*ba;
        ada[*b][1]=*l;ada[*b][2]=*f;ada[*b][3]=*r;ada[*b][4]=*ba;

        ado[*o.l][1]=*o.t;ado[*o.l][2]=*o.f;ado[*o.l][3]=*o.b;ado[*o.l][4]=*o.ba;
        ado[*o.r][1]=*o.t;ado[*o.r][2]=*o.f;ado[*o.r][3]=*o.b;ado[*o.r][4]=*o.ba;
        ado[*o.f][1]=*o.t;ado[*o.f][2]=*o.l;ado[*o.f][3]=*o.b;ado[*o.f][4]=*o.r;
        ado[*o.ba][1]=*o.t;ado[*o.ba][2]=*o.l;ado[*o.ba][3]=*o.b;ado[*o.ba][4]=*o.r;
        ado[*o.t][1]=*o.l;ado[*o.t][2]=*o.f;ado[*o.t][3]=*o.r;ado[*o.t][4]=*o.ba;
        ado[*o.b][1]=*o.l;ado[*o.b][2]=*o.f;ado[*o.b][3]=*o.r;ado[*o.b][4]=*o.ba;
        
        for(int i=1;i<=6;i++)
        {
            for(int j=1;j<=4;j++){
                int t;
                for(t=1;t<=4;t++){
                    if(ada[i][j]==ado[i][t])
                        break;
                }
                if(t==5) return false ;
            }
        }
        return true;
    }
 void lr(struct dice &a,struct dice & temp)
{
    *temp.f=*a.f;*temp.ba=*a.ba;*temp.b=*a.l;*temp.l=*a.t;*temp.t=*a.r;*temp.r=*a.b;
}
void rr(struct dice &a,struct dice & temp)
{
    *temp.f=*a.f;*temp.ba=*a.ba;*temp.t=*a.l,*temp.r=*a.t,*temp.l=*a.b,*temp.b=*a.r;
}
void fr(struct dice &a,struct dice &temp)
{
    *temp.l=*a.l;*temp.r=*a.r;*temp.b=*a.f;*temp.f=*a.t;*temp.t=*a.ba;*temp.ba=*a.b;
}
void br(struct dice &a,struct dice &temp)
{
    *temp.l=*a.l,*temp.r=*a.r;*temp.t=*a.f;*temp.ba=*a.t;*temp.b=*a.ba;*temp.f=*a.b;
}
dice *a=new dice();
dice *b=new dice();
vector <dice> q;
int bfs(dice &x)
{
    q.clear();
    q.push_back(x);
    if(x==*b) return 0;
    dice *temp=new dice();
    int tsize=1;
    int size;
    int ans=1;
    int l=0;
    while(!q.empty())
    {
        size =tsize;
        tsize = 0;
        //printf("%d\n",q.size());
        for(int i=0;i<size;i++)
        {
            dice  t = q[l++];
            //t.out();
           for(int j=0;j<4;j++)
           {
               temp =new dice();
               p[j](t,*temp);
               //temp->out();
               if(*temp==*b) return ans;
               vector <dice> :: iterator it;
               for(it=q.begin();it!=q.end();it++)
               {
                   if(*it==*temp)
                       break;
               }
               if(it==q.end())
               {
                    q.push_back(*temp);
                    tsize++;
               }
           }
            
        }
        ans++;
    }
    return ans;
    
}
int main()
{
    p[0]=lr;p[1]=rr;p[2]=fr;p[3]=br;
    while(~scanf("%d%d%d%d%d%d",&a->a[1],&a->a[2],&a->a[3],&a->a[4],&a->a[5],&a->a[6]))
    {
        b->input();
        if(a->judge(*b)==false)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",bfs(*a));
    }

    return 0;
}

