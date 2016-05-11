#include <iostream>
#include <cstdio>
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
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, k;
string s;
ll power[100100];
ll h[100100];
ll dp[100100];
ll rac[100100];
ll f[100100];

ll x, y, d;

void extendedEuclid(int a, int b){
	if(b == 0){ x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a%b);
	ll x1 = y;
	ll y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

ll invMult(ll a, ll m){
	extendedEuclid(a, m);
	x = x%m;
	if(x < 0) x += m;
	return x;
}

ll num(int a, int b){
	if(a > b) return 0LL;
	ll ans = (h[b+1] - h[a] * power[b-a+1])%MOD;
	return ans;
}

ll comb(int a, int b){
	if(a < 0 || b < 0 || a < b) return 0LL;
	ll ans = f[a] * invMult((f[b]*f[a-b])%MOD, MOD);
	return ans%MOD;
}

int main(){
	cin >> n >> k >> s;
	f[0] = power[0] = 1LL;
	REPP(i, 1, 100050){
		power[i] = (power[i-1]*10LL)%MOD;
		f[i] = (f[i-1]*i)%MOD;
	}
	rac[n] = h[n] = dp[0] = 0LL;
	REP(i, n) h[i+1] = (h[i]*10LL + (s[i]-'0'))%MOD;
	for(int i = n-1; i>=0; i--) rac[i] = rac[i+1]+(s[i]-'0');
	REPP(i, 1, n+1){
		dp[i] = ((dp[i-1] - num(n-i+1, n-1))*10LL)%MOD;
		dp[i] = (dp[i] + rac[i-1])%MOD;
		if(dp[i] < 0LL) dp[i] += MOD;
	}
	ll ans = 0LL;
	REPP(i, 1, n){
		ll x = (num(n-i, n-1)+num(0, i-1))%MOD;
		ans += (((dp[i]-x)%MOD) * comb(n-i-2, k-2))%MOD;
		ans = ans%MOD;
		ans += (x * comb(n-i-1, k-1))%MOD;
		ans = ans%MOD;
	}
	if(k == 0) ans = (ans+dp[n])%MOD;
	if(ans < 0LL) ans += MOD;
	cout << ans << endl;
}

