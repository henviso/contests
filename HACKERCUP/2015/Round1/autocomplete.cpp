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
#include <sstream>
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
#define REPD(i,n) for(int i = n-1; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n;
set<ll> prefix;

typedef long long unsigned hash;

#define MAXN 1000100
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXN];
char str[MAXN];
int T;

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
}

ll calcHash(){
	ll ans = ((ll) T);
	p[0] = 0ULL;
	REP(j, T){
		p[j+1] = p[j]*B + str[j];
		if(prefix.count(p[j+1]) == 0){
			ans = min(((ll) j+1), ans);
			prefix.insert(p[j+1]);
		}
	}
	return ans;
}

hash calc_dhash(int a, int b) {
	if (a > b) return 0;
	return p[b+1] - p[a] * power[b - a + 1];
}

int main(){
	precalc();
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		prefix.clear();
		scanf(" %d ", &n);
		ll ans = 0LL;
		REP(i, n){
			scanf(" %s ", &str[0]);
			T = strlen(&str[0]);
			ll x = calcHash();
			ans += x;
		}
		cout << "Case #" << ca << ": " << ans << endl;
	}
}
