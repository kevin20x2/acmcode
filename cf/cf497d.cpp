/*
 *File:  cf497d.cpp
 *Date : 2014-10-19 18:13:18
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
#define maxn 100020
int n,l,x,y;
int a[maxn];
bool find(int length,int &posx,int &posy)
{
    for(int i =1;i<n;i++)
    {
        int l =i+1;int r = n;
        while(l<r)
        {
            int mid = (l+r)/2;
            if(a[mid]-a[i]==length)
            {
                posx = a[i];posy = a[mid];
                return true;
            }
            else if(a[mid]-a[i]<length) l=mid+1;
            else r=mid;
        }
        if(a[l]-a[i]==length)
        {
            posx = a[i];posy=a[l];
            return true;
        }
    }
    return false;

    
}
int main()
{
    scanf("%d%d%d%d",&n,&l,&x,&y);
    for(int i =1;i<=n;i++)
        scanf("%d",&a[i]);
    int posx,posy;
    bool flagx =find(x,posx,posy);
    bool flagy=find(y,posx,posy);
    if(flagx&&flagy)
        printf("0\n");
    else if(flagx){
        printf("1\n");
        printf("%d\n",y);
    }
    else if(flagy){
        printf("1\n");
        printf("%d\n",x);
    }
    else if(find(y+x,posx,posy))
    {
        printf("1\n");
        printf("%d\n",posx+x);
    } else if(find(y-x,posx,posy))
    {
        if(posx-x>=0)
        {
            printf("1\n");
            printf("%d\n",posx-x);
        }else
            if(posy+x<=l)
            {
                printf("1\n");
                printf("%d\n",posy+x);
            }
        else{
            printf("2\n");
            printf("%d %d\n",x,y);
        } 
    }
    else {
        printf("2\n");
        printf("%d %d\n",x,y);
    }
        
   
    return 0;
}

