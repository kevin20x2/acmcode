/*
 *File:  9201002.cpp
 *Date : 2014-09-20 12:34:02
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
#define N 1000050
struct seg{
    int l,r;
    int add;
    int sum;
};
seg tree[5*N];
int n,m;
int l,r;
int cl;
char str[2];

using namespace std;

void bulid(int k,int l,int r)
{
    int mid;
    int L,R;
    tree[k].l=l,tree[k].r = r;
    tree[k].add = 0;
    if(tree[k].r==tree[k].l)
    {
        tree[k].sum=1<<(2-1);
        return ;
    }
    L= 2*k,R=L+1;
    mid = (tree[k].l+tree[k].r)/2;
    bulid(L,l,mid);
    bulid(R,mid+1,r);
    tree[k].sum = tree[L].sum|tree[R].sum;
    return ;
}
void p(int k,int l,int r,int cl)
{
    int mid ;
    int L,R;
    
    if(l<=tree[k].l&&tree[k].r<=r) 
    {
        tree[k].sum = 1<<(cl-1);
        tree[k].add =1<<(cl-1);
        return ;
    }
    L= 2*k;R=L+1;
    if(tree[k].add)
    {
        tree[L].add =tree[k].add;
        tree[R].add =tree[k].add;
        tree[L].sum = tree[k].add;
        tree[R].sum = tree[k].add;
        tree[k].add = 0;
    }
    mid = (tree[k].l+tree[k].r)/2;
    if(l<=mid) p(L,l,r,cl);
    if(r>mid) p(R,l,r,cl);
    tree[k].sum = tree[L].sum|tree[R].sum;
      
}
int q(int k,int l,int r)
{
    int ans=0;
    int mid = (tree[k].l+tree[k].r)/2;
    int L=2*k,R=L+1;
    if(tree[k].add)
    {
        tree[L].add = tree[k].add;
        tree[R].add = tree[k].add;
        tree[L].sum = tree[k].add;
        tree[R].sum = tree[k].add;
        tree[k].add = 0;
    }
    if(l<=tree[k].l&&tree[k].r<=r) return tree[k].sum;
    if(l<=mid) ans |= q(L,l,r);
    if(r>mid) ans |= q(R,l,r);
    return ans;
}
int main()
{
    while(~scanf("%d%d",&n,&m)&&n*m){
        clr(tree);
        bulid(1,1,n);
        loop(i,1,m)
        {
            scanf("%s",str);
            if(str[0]=='P')
            {
                scanf("%d%d%d",&l,&r,&cl);
                p(1,l,r,cl);
               // loop(i,1,2*n+2)
                 // printf("%d ",tree[i].sum);
                //printf("\n");
            }
            else{
                scanf("%d%d",&l,&r);
                int x = q(1,l,r);
                //printf("\n%d\n",x);
                int first =1;
                loop(i,1,30)
                {
                    
                    if((x&(1<<(i-1)))!=0)
                    {
                        if(first)
                        {
                            printf("%d",i);
                            first =0;
                        }
                        else{
                            printf(" %d",i);
                        } 
                    }
                }
                printf("\n");
            } 
        }
    }
    return 0;
}

