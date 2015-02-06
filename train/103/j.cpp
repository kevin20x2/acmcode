/*
 *File:  j.cpp
 *Date : 2014-10-03 21:46:14
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
#define maxn 2020
using namespace std;
struct seg{
    int lson,rson;
    int fa,dep;
    int lx,ly,rx,ry;
    void init(int de,int f)
    {
        lson = rson = 0;
        fa =f;
        dep = de;
    }
    void update(int a,int b , int c, int d)
    {
        lx = a,ly =b ,rx = c,ry = d;
    }
} node[maxn];
int tol;
int num[maxn];
int root;

int find(int root,int x,int y)
{
    int tmp = root,t;
    while(1)
    {
        if(node[tmp].lson == 0) return tmp;
        t = node[tmp].lson ;
        if(x<=node[t].rx&&x>=node[t].lx&&y<=node[t].ry&&y>=node[t].ly)
            tmp =t;
        else tmp =node[tmp].rson;
    }
}
int get_num(int now)
{
    num[now] = 0;
    if(node[now].lson==0)
    {
        return num[now] =1;
    }
    else {
        num[now] +=get_num(node[now].lson);
        num[now] += get_num(node[now].rson);
    }
    return num[now];
}
int lx,ly,rx,ry;
int n,q;

int main()
{
    while(~scanf("%d%d%d%d",&lx,&ly,&rx,&ry))
    {
        root = 0;
        node[root].init(1,-1);
        node[root].update(lx,ly,rx,ry);
        tol =1;
        
        scanf("%d%d",&n,&q);
        loop(i,1,n)
        {
            scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
            if(lx>rx) swap(lx,rx);
            if(ly>ry) swap(ly,ry);
            int pos = find(root,(lx+rx)/2,(ly+ry)/2);
            int dep = node[pos].dep;

            node[pos].lson = tol;
            node[tol].init(dep+1,pos);
            node[tol].update(node[pos].lx,node[pos].ly,rx,ry);
            tol++;
            node[pos].rson =tol;
            node[tol].init(dep+1,pos);
            node[tol].update(lx,ly,node[pos].rx,node[pos].ry);
            tol ++;

        }
        get_num(root);
        while(q--)
        {
            scanf("%d%d%d%d",&lx,&ly,&rx,&ry);
            int t1 = find(root,lx,ly); 
            int t2 = find(root,rx,ry);
            while(t1!=t2)
            {
                if(node[t1].dep<node[t2].dep) t2 = node[t2].fa;
                else if(node[t1].dep>node[t2].dep) t1 = node[t1].fa;
                else{
                    t1 =node[t1].fa;
                    t2 = node[t2].fa;
                }
            }
            printf("%d\n",n+1-num[t1]+1);
        }
    }

    return 0;
}

