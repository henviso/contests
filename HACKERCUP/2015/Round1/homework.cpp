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

#define SIEVE_MAX 10000100
bitset<SIEVE_MAX+1> _prime; 
vi primes;

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.push_back(2);
	for(ll i = 4; i<SIEVE_MAX; i+=2) _prime[i] = 0;
	for(ll i = 3; i<SIEVE_MAX; i+=2){
		if(_prime[i]){ 
			for(ll j = i*i; j<SIEVE_MAX; j+=2*i) _prime[j] = 0;
			primes.push_back((int) i);
		}
	}
}

bool isPrime(ll N){
	if(N <= SIEVE_MAX) return _prime[N];
	for(int i = 0; i<(int) primes.size(); i++){
		if(N%primes[i] == 0) return false;
	}
	return true;
}

int numPf(ll N){
	ll PF_idx = 0, PF = primes[PF_idx];
	int ans = 0;
	while(N > 1 && (PF*PF <= N)){
		if(N%PF == 0){ ans++; while(N%PF == 0) N /= PF; }
		PF = primes[++PF_idx];
	}
	if(N > 1) ans++;
	return ans;
}

vi g[10000100];
int t, a, b, k;

int main(){
	sieve();
	REPP(i, 2, 10000001){
		int x = numPf((ll) i);
		g[x].push_back(i);
	}
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		scanf(" %d %d %d ", &a, &b, &k);
		int ans = (lower_bound(g[k].begin(), g[k].end(), b+1) - lower_bound(g[k].begin(), g[k].end(), a)); 
		cout << "Case #" << ca << ": " << ans << endl;
	}
}
