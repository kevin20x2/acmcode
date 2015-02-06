/*
 *File:  2012hangzhoui.cpp
 *Date : 2014-10-26 13:15:09
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
int n;
map <char ,int > m;
char str[10];

int main()
{
    int cas;
    scanf("%d",&cas);
    m.insert(make_pair('A',16));
    m.insert(make_pair('B',7));
    m.insert(make_pair('C',8));
    m.insert(make_pair('D',1));
    m.insert(make_pair('E',1));
    m.insert(make_pair('F',2));
    m.insert(make_pair('G',3));
    while(cas--)
    {
        scanf("%d",&n);
        int red=0;
        bool flagb  = false;
        bool flagc = false;
        for(int i =1;i<=n;i++)
        {
            scanf("%s",str);
            if(str[0] == 'B')
                flagb =true;
            if(str[0] == 'C')
                flagc = true;
            red += m.find(str[0])->second;
        }
        if(!(flagb&&flagc)&&red>1)
        {
            red--;
        }
        scanf("%d",&n);
        int  black=0;
        flagb = false ;
        flagc =false;
        for(int i =1;i<=n;i++)
        {
            scanf("%s",str);
            if(str[0] == 'B')
                flagb =true;
            if(str[0] == 'C')
                flagc = true;
            black+= m.find(str[0])->second;
        }
        if(!(flagb&&flagc)&&black>1)
        {
            black--;
        }
        if(red>black)
            puts("red");
        else if(red==black)
            puts("tie");
        else puts("black");
    }
    return 0;
}

