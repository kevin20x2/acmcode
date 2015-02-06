/*
 *File:  g.cpp
 *Date : 2014-10-01 13:17:43
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
#define maxn 100005

using namespace std;
struct seg{
    int c,x,y;
};
seg a[maxn];
int b[maxn];
int id[maxn];

int n;
int first;
int cmp(seg x,seg y)
{
    if(x.x<y.x) return 1;
    else if(x.x==y.x&&x.y>y.y) return 1;
    else return 0;
}
void out(int x)
{
    if(x == -1) return ;
    out(b[x]);
    if(first)
    {
        printf("%d",a[x].c);
        first = 0;
    }
    else printf(" %d",a[x].c);

    
}
int main()
{
    scanf("%d",&n);
    loop(i,1,n)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].c = i;
    }
    sort(a+1,a+n+1,cmp);
    int len = 1;
    id[0] = 1;
    first = 1;
    memset(b,-1,sizeof(b));
    loop(i,2,n)
    {
        if(a[i].y > a[id[len-1]].y)
        {
            id[len] = i;
            b[i] = id[len-1];
            ++len;
            
        }
        else 
        {
            int l =0 ,r = len -1;
            while(l<r)
            {
                int mid = (l+r)/2;
                if(a[i].y>a[id[mid]].y) l = mid+1;
                else r = mid;
            }
            id[l] = i;
            if(l==0) b[l] = -1;
            else b[i] = id[l-1];
        }
    }
    printf("%d\n",len);
    out(id[len-1]);
    printf("\n");
    
    return 0;
}

