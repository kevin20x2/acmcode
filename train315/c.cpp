/*
 *File:  c.cpp
 *Date : 2015-03-15 14:30:19
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
struct seg{
    int v,c;
    seg (){}
    seg (int a ,int b):v(a),c(b){}
};
seg a[3000];
seg b[3000];
int n;
int cmp(seg a,seg b)
{
    if(a.v<b.v) return 1;
    else if(a.v==b.v)
    {
        if(a.c<b.c) return 1;
    }
    return 0;
}
int bis(int p,int m)
{
    int l = p;int r =n;
    while(l<r)
    {
        int mid = (l+r)>>1;
        if(b[mid].v<m) r= mid;
        else if(b[mid].v>m) l= mid+1;
        else {
            l = mid ;break;
        };
    }
    while(b[l].v==m&&l>=p)l-- ;
    if(b[l+1].v==m) return b[l+1].c;
    else return -1;
}

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i = 1;i<=n;i++)
        {
            scanf("%d",&a[i].v);
            a[i].c = i;
        }
        int x,y;
        int ans = 0;
        vector <int > ans_v;
        for(int i =1;i<=n;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                b[j] = a[j];
            }
            for(int j = i+1;j<=n;j++)
            {
                vector <int > t;
                x = a[i].v;
                y = a[j].v;
                t.push_back(i);
                t.push_back(j);
                int no = j;
                sort(b+no+1,b+n+1,cmp);
                while(no!=-1&&no<n)
                {
                    no=bis(no+1,x+y);
                    if(no!=-1) t.push_back(no);
                    else break;
                    y = x+y;
                    x= y-x;
                }
                ans = max(ans,(int)t.size());
                if(ans ==t.size())
                    ans_v = t;
            }
        }
        printf("%d\n",ans);
        int first = 1;
        for(int i = 0;i<ans_v.size();i++)
            if(first){
                first = 0;
                printf("%d",ans_v[i]);
            }else printf(" %d",ans_v[i]);
        
    }
    return 0;
}

