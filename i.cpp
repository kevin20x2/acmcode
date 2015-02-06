#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;

int a[maxn];
int dp[maxn];

void init(){
	memset(dp, 0, sizeof(dp));
}
int main(){
	int T;
	scanf("%d",&T);
	while ( T-- ){
		init();
		int n;
		scanf("%d",&n);
		for (int i=1; i<=n; i++){
			scanf("%d",&a[i]);
		}

		int res = 1;

		for (int i=1; i<=n; i++){
			int x = a[i];
			int val = 0;

			for (int j=2; j*j <= x; ++j){
				if ( x % j == 0 ){
					dp[j]++;
					val = max( val, dp[j] );	
					while ( x % j == 0 ){
						x /= j;
					}
				}
			}
			if ( x != 1 ){
				dp[x]++;
				val = max( val, dp[x] );
			}

			x = a[i];
			for (int j=2; j*j <= x; ++j){
				if ( x % j == 0 ){
					dp[j] = val;
					while ( x % j == 0 ){
						x /= j;
					}
				}
			}	
			if ( x != 1 ){
				dp[x] = val;
			}
			res = max( res, val );
		}	
			
		printf("%d\n",res);
	}
	return 0;
}
