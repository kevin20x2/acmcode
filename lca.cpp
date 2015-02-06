/*
 *File:  lca.cpp
 *Date : 2014-10-04 19:03:18
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<string>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)
#define N 210
using namespace std;
map <string, int > ma;

struct seg{
    string name;
    int fa,dep;
}a[N];

int n,m;
int getdep(int x)
{
    if(a[x].dep!=0) return a[x].dep;
   if(a[x].fa==-1) 
   {
       return  a[x].dep = 1;
   }
   a[x].dep = getdep(a[x].fa)+1;
   return a[x].dep;
}
int main()
{
    loop(i,0,N)
    {
        a[i].fa = -1;
        a[i].dep = 0;
    }
    int tol = 0;
    cin>>n;
    loop(i,1,n)
    {
        int f,c;
        string fa,child;
        cin>>fa>>child;
        if(ma.find(fa)==ma.end())
        {
            f = tol;
            a[tol++].name=fa;
            ma.insert(make_pair(fa,tol-1));
        }
        else  {
            f = ma.find(fa)->second;

        }
        if(ma.find(child)==ma.end())
        {
            c =tol;
            a[tol++].name = child;
            ma.insert(make_pair(child,tol-1));
        }
        else {
            c = ma.find(child)->second;
        }
        a[c].fa = f;
    }
    loop(i,0,tol-1)
    {
        getdep(i);
    }
    cin>>m;
    loop(i,1,m)
    {
        string sa,sb;
        cin>>sa>>sb;
        int x = ma.find(sa)->second;
        int y = ma.find(sb)->second;
        while(x!=y&&(x!=-1||y!=-1))
        {
           
            if(a[x].dep>a[y].dep) x= a[x].fa;
            else if(a[x].dep<a[y].dep) y = a[y].fa;
            else {
                x = a[x].fa;
                y = a[y].fa;
            }
            
        }
        if(x!=-1)
            cout<<a[x].name<<endl;
        else cout<<-1<<endl;
    }
        

    return 0;
}

