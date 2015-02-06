
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cctype>
#include <ctime>
#include <utility>
 
using namespace std;
 
#define M0(x) memset(x, 0, sizeof(x))
#define clr(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(v) ((int)(v).size())
#define all(t) t.begin(),t.end()
#define unq(x) sort(all(x)),(x).erase(unique(all(x)),(x).end())
#define repf(i, a, b) for(int i = (a); i <= (int)(b); i ++)
#define repd(i, a, b) for(int i = (a); i >= (int)(b); i --)
#define repcase int T, cas = 0; for (scanf ("%d", &T); T; --T)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) cout<<#x<<":"<<(x)<<endl
#define tst(a) cout<<a<<" "
#define tst1(a) cout<<#a<<endl
 
typedef long long LL;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef vector<pii > vii;
typedef pair<pii, int> piii;
typedef vector<piii > viii;
 
const double eps = 1e-10;
const double PI = atan(1.0)*4;



 
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> int sgn(T x) { return (x > eps) - (x < -eps);}


int n;
int start1,start2;

int dirx[8]={-1,-1,0,1,1,1,0,-1};
int diry[8]={0,-1,-1,-1,0,1,1,1};



char mapp[110][110];
int map2[110][110];

int ans;
int maxx;

void dfs(int x,int y)
{
	if(start1!=-1&&start2!=-1)
		{
			int dx=dirx[start2];
		int dy=diry[start2];
		int tempx=x+dx;
		int tempy=y+dy;
		if(map2[tempx][tempy])
		{
			ans++;
			dfs(tempx,tempy);
			ans--;
			
		}
		else
		{
			if(maxx<ans)
				maxx=ans;
			//printf("%d %d\n",x,y);
			return;
		}

   return;

			
		}
		else if(start1!=-1&&start2==-1)
		{
			int dx=dirx[start1];
		int dy=diry[start1];
		int tempx=x+dx;
		int tempy=y+dy;
		if(map2[tempx][tempy])
		{
			ans++;
			dfs(tempx,tempy);
			ans--;
		}

		
		for(int i=0;i<8;i++)
		{
			start2=i;
			if(abs(start2-start1)==6||abs(start2-start1)==2)
			{
				//printf("%d %d\n",start1,start2);
			int dx=dirx[start2];
		int dy=diry[start2];
		int tempx=x+dx;
		int tempy=y+dy;
		if(map2[tempx][tempy])
		{
			ans++;
			dfs(tempx,tempy);
			ans--;


		}
	}

		}
		if(maxx<ans)
				maxx=ans;
			return;

	




		}
		else  if(start1==-1&&start2==-1)
		{
	for(int i=0;i<8;i++)
	{

		start1=i;
		int dx=dirx[start1];
		int dy=diry[start1];
		int tempx=x+dx;
		int tempy=y+dy;
		if(map2[tempx][tempy])
		{
			//printf("%d %d %d\n",start1,tempx,tempy);
			ans++;

			dfs(tempx,tempy);
           ans--;
		}
		




	}
}
}
int main()
{

while(scanf("%d",&n)==1&&n)
{
	memset(map2,0,sizeof(map2));
	for(int i=0;i<n;i++)
	{
		scanf("%s",mapp[i]);
		for(int j=0;j<strlen(mapp[i]);j++)
		{
			if(mapp[i][j]=='.')
				map2[i][j]=1;
		}


	}

	ans=0;
	maxx=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<strlen(mapp[i]);j++)
		{
			if(map2[i][j]==1)
			{
				//printf("%d %d\n",i,j);
				start1=-1;
				start2=-1;
				ans=0;
				dfs(i,j);

			}
		}
	}


printf("%d\n",maxx+1);







}
return 0;
}


