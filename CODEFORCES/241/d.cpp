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
#define INF 1000000000000000000LL
#define EPS 1e-9
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

ll a[200100], n;

int main(){
	cin >> n;
	REP(i, n) cin >> a[i];
	ll ans = 0LL;
	ll l = 0LL, r;
	while(l < n){
		ans++;
		
		ll f = l, s;
		while(f < n && a[f] == -1LL) f++;
		if(f == n) break;
		
		s = f+1;
		
		while(s < n && a[s] == -1LL) s++;
		if(s == n) break;
		
		ll ra = (a[s] - a[f]) / (s-f);
		if( (((a[s] - a[f]) % (s-f))  != 0LL) || (a[s] - (s-l) * ra) <= 0LL){
			l = s;
			continue;
		} 
		
		r = s+1;
		while(r < n && (a[s] + (r-s) * ra) > 0LL  && (a[r] == (a[s] + (r-s) * ra) || a[r] == -1LL)) r++;
		if(r == n) break;
		
		l = r;
	}
	cout << ans << endl;
}
