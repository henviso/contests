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

#define SIEVE_MAX 100000000LL
bitset<SIEVE_MAX+1> _prime; 
vector<ll> primes;

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.push_back(2);
	for(ll i = 4; i<SIEVE_MAX; i+=2) _prime[i] = 0;
	for(ll i = 3; i<SIEVE_MAX; i+=2){
		if(_prime[i]){ 
			for(ll j = i*i; j<SIEVE_MAX; j+=2*i) _prime[j] = 0;
			primes.push_back(i);
		}
	}
}

bool isPrime(ll N){
	if(N <= SIEVE_MAX) return _prime[N];
	for(int i = 0; i<(int) primes.size(); i++){
		if(N%primes[i] == 0LL) return false;
	}
	return true;
}

vector<ll> primeFactors(ll N) {
	vector<ll> factors; 
	ll PF_idx = 0, PF = primes[PF_idx];
	while(N > 1LL && (PF*PF <= N)){
		while(N%PF == 0){ N /= PF; factors.push_back((ll) PF); }
		if(PF_idx == primes.size()-1) break;
		PF = primes[++PF_idx];
	}
	if(N > 1) factors.push_back((ll) N);
	return factors; 
}

int t, n, m;
ll x;
ll ans[1000100];
int l[1000100];
int r[1000100];
ll bst[100];

void longestPath(ll e){
	vector<ll> fa = primeFactors(e);
	ll ba = 1LL;
	ll ex = -1LL;
	while(!fa.empty()){
		ll p = fa[fa.size()-1];
		ll E = 0;
		while(fa[fa.size()-1] == p){ fa.pop_back(); E++; }
		ba *= p;
		if(ex == -1LL) ex = E;
		else if(E != ex){
			ans[++n] = e;
			r[m++] = n;
			return;
		}
	}
	if(ex != 1LL){
		for(ll i = 0; i<=ex)
		ans[++n] = ba;
		longestPath(ex);
	}
	else{
		ans[++n] = ba;
		r[m++] = n;
	}
}

int main(){
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
	
	sieve();
	cin >> t;
	while(t--){
		cin >> x;
		n = 0; m = 0;
		vector<ll> pf = primeFactors(x);
		while(!pf.empty()){
			ll p = pf[pf.size()-1];
			ans[++n] =  p;
			l[m] = n;
			ll e = 0;
			while(pf[pf.size()-1] == p){ pf.pop_back(); e++; }
			if(e == 1LL){
				r[m++] = n;
				continue;
			}
			ll mx = 0, B = -1LL;
			for(ll i = 0; i<=e; i++){
				if(bst[i]+bst[e-i] > mx){
					mx = bst[i]+bst[e-i];
					B = i;
				}
			}
			
		}
		cout << n << " " << m << endl;
		cout << ans[1]; REPP(i, 2, n+1) cout << " " << ans[i]; 
		cout << endl;
		REP(i, m) cout << l[i] << " " << r[i] << endl;
	}
}