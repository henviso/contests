#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include <cctype>
#include <vector>
#include <queue>
#include <tr1/unordered_map>
#include <cmath>
#include <map>
#include <bitset>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n, m;
int nxt[1100];
int c[1100];
int s[1100];
int N;

ll dp[1100][1100];
ll sum[1100][1100];
int last[1100];

ll dist(){
	CLEAR0(dp);
	dp[0][0] = 1;
	REP(i, 1002){
		sum[i][0] = sum[i-1][0] + dp[i][0];
		last[i] = -1;
	}
	REPP(i, 1, N+1){
		REPP(k, 1, m+1){
			if(last[s[i]] >= 0) dp[i][k] = (sum[i-1][k-1]-sum[last[s[i]]-1][k-1])%MOD;
			else dp[i][k] = sum[i-1][k-1];
			sum[i][k] = (sum[i-1][k] + dp[i][k])%MOD;
		}
		last[s[i]] = i;
	}
	ll ans = 0LL;
	REPP(k, 1, m+1){
		//cout << " SUM[" << N << "][" << k << "] = " << sum[N][k] << endl;
		ans = (ans+sum[N][k])%MOD;
	}
	if(ans < 0LL) ans += MOD;
	
	/*cout << "TABELA COMPLETA\n";
	REPP(i, 0, N+1){
		REPP(k, 0, m+1) cout << dp[i][k] << " ";
		cout << endl;
	}
	
	cout << "TABELA SUM COMPLETA\n";
	REPP(i, 0, N+1){
		REPP(k, 0, m+1) cout << sum[i][k] << " ";
		cout << endl;
	}*/
	
	return ans;
}

int main(){
	cin >> t;
	while(t--){
		cin >> n >> m;
		int x;
		CLEAR0(nxt);
		REPP(i, 1, n+1){
			cin >> x >> c[i];
			nxt[x] = i;
		}
		N = 0;
		x = 0;
		while(nxt[x] != 0){
			x = nxt[x];
			s[++N] = c[x];
		}
		//	REPP(i, 1, N+1) cout << s[i] << " ";
		//  cout << endl;
		ll ans = dist();
		cout << ans << endl;
	}
}
