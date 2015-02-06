/*
 *File:  train117b.cpp
 *Date : 2014-11-07 12:53:04
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
const int days = 365;
const int s[]  = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,mi;
int hour[2600];
int life,cost,num[2600];
int ti;
int year,day;
string month;
char str[10];
map <string ,int > m;
vector <int > v[2600];
int co[100010];
int leap(int y)
{
    if(!y) return 0;
    return y/4-y/100+y/400;
}
bool Isleap(int y)
{
    if(y%400==0|| y%100&&y%4==0) return 1;
    return 0;
}
int clac(int day ,int mon ,int year)
{
    int res = (year-1) *days +leap(year-1);
    for(int i =1;i<mon ;++i)
    {
        res += s[i];
    }
    if(Isleap(year)&& mon >2) res ++;
    res +=day;
    return res;
}
void init ()
{
    m["Jan"] = 1;
    m["Feb"]  =2 ;
    m["Mar"]  =3;
    m["Apr"] =4;
    m["May"] =5;
    m["Jun"] =6;
    m["Jul"] =7;
    m["Aug"] =8;
    m["Sep"] =9;
    m["Oct"] =10;
    m["Nov"] =11;
    m["Dec"] =12;
    
}

int main()
{
    init();
    while(~scanf("%d%d",&n,&mi)&&n*mi)
    {
        int stdhour= clac(1,1,2000);
        for(int i =1;i<=n;i++)
        {
            //cin>> month>>day>>year>>ti>>num[i];
            scanf("%s%d%d%d%d",str,&day,&year,&ti,&num[i]);
            month = str;
            hour[i] = 24*(clac(day,m[month],year)-stdhour)+(ti+1);
        }
        scanf("%d%d",&life,&cost);
        for(int i =1;i<=mi;i++)
        {
            scanf("%d",&co[i]);
        }
        LL sum =0;
        for(int i =1;i<=n;i++)
        {
            LL ans = 1LL*co[hour[i]-1]*num[i]+1*cost*num[i];
            for(int j =2;j<=life&&(hour[i]-j>=1);j++) if(co[hour[i]-j]<co[hour[i]-1])
            {
                ans = min(ans,1LL*co[hour[i]-j]*num[i]+j*cost*num[i]);
            }
            sum+=ans;
        }
        printf("%I64d\n",sum);
        
    }
    return 0;
}

