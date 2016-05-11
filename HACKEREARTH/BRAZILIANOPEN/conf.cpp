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


ll fastExp(ll base, ll p, ll m){
	if(p == 0LL) return 1LL;
	else if(p == 1LL) return base%m;
	else{
		unsigned long long res = fastExp(base, p/2LL, m);
		res = (res*res);
		if(p%2LL == 1LL) res = (res*base);
		if(res > m) return 0;
		return res;
	}
}

int n, m;
ll a[1000100];
ll bst[100];

int main(){
	/*
	while(cin >> n >> m){
		REPP(i, 1, n+1) cin >> a[i];
		int l, r;
		ll ans = 1LL;
		ll p = 1LL;
		REP(i, m){
			cin >> l >> r;
			p = a[r];
			for(int j = r-1; j>=l; j--){
				p = fastExp(a[j], p, 9223372036854775807LL);
				cout << p << endl;
			}
			ans *= p;
		}
		cout << ans << endl;
	}*/
	REP(i, 100) bst[i] = 1;
	REPP(i, 2, 60)
	REPP(j, 2, 60-i){
		ll p = fastExp(i, j, 1000000000000000001LL);
		if(p == 0LL || p > 60LL) continue;
		bst[p] = 2;
		for(ll i = 1; i*p<100; i++) bst[i*p] = 2;
	}
	bst[16] = 3;
	for(ll i = 1; i*16<100; i++) bst[i*16] = 3;
	REP(i, 100) cout << bst[i] << endl;
	
	
}
