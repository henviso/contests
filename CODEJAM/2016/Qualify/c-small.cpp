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
#include <utility>    
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
//L[i]=L[i/2]+1;

int n, j;
vi ans;

void bt(int col, unsigned int chosen, int zero3, int one3, int two3, int zero4, int one4, int two4, int three4, int odd, int even){
	if(ans.size() >= j) return;
	if(__builtin_popcount(chosen) == 12){
		if(zero3 == one3 && two3 == one3 && zero4 == 2 && one4 == two4 && two4 == three4 && two4 == 3 && odd == even){
			//cout << " CHOSEN N CHEGA AQUI " << endl;
			ans.push_back(chosen);
		}
		return;
	}
	if(col == n-1) return;
	bt(col+1, chosen|(1<<col), zero3 + ((col%3) == 0), one3 + ((col%3) == 1), two3 + ((col%3) == 2), 
			   zero4 + ((col%4) == 0), one4 + ((col%4) == 1), two4 + ((col%4) == 2), three4 + ((col%4) == 3), odd + (col%2), even + !(col%2));
	bt(col+1, chosen, zero3, one3, two3, zero4, one4, two4, three4, odd, even);
}

#define SIEVE_MAX 100000000
bitset<SIEVE_MAX+1> _prime; 
vector< ll > primes;

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.pb(2LL);
	for(ll i = 4; i<SIEVE_MAX; i+=2) _prime[i] = 0;
	for(ll i = 3; i<SIEVE_MAX; i+=2){
		if(_prime[i]){ 
			for(ll j = i*i; j<SIEVE_MAX; j+=2*i) _prime[j] = 0;
			primes.push_back((ll) i);
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

ll intWithBase(unsigned int msk, ll b){
	ll ans = 0LL, x = 1;
	REP(i, 32){
		if(msk&(1<<i)) ans += x;
		x *= b;
	}
	return ans;
}

bool test(int msk){
	REPP(b, 2, 11){
		ll x = intWithBase(msk, b);
		if(isPrime(x)) return false;
	}
	return true;
}


int main(){
	n = 16;
	j = 50;
	bt(1, 0x00008001, 2, 0, 0, 0, 0, 0, 1, 1, 1); 
	cout << "Case #1:\n";
	REP(i, ans.size()){
		REPD(j, n){
			if(ans[i]&(1<<j)) cout << "1";
			else cout << "0";
		}
		REPP(j, 2, 10){
			if(j%2) cout << " 2";  
			else{
				if(j == 6) cout << " 43";
				else cout << " 5";
			}
		}
		cout << " 11\n";
	}
	sieve();
	int rem = j-ans.size(), cnt = 0;
	for(unsigned int msk = 1; msk < (1<<n) && cnt < rem; msk++){
		bool reap = false;
		REP(j, ans.size()) if(ans[j] == msk) reap = true;
		if(reap) continue;
		if(msk&(1<<(n-1)) && msk&1 && test(msk)){
			REPD(j, n){
				if(msk&(1<<j)) cout << "1";
				else cout << "0";
			}
			REPP(b, 2, 11){
				ll x = intWithBase(msk, b);
				REP(i, primes.size()){
					if(x%primes[i] == 0){
						cout << " " << primes[i];
						break;
					}
				}
			}
			cout << endl;
			cnt++;
		}
	}
	//cout << ans.size() << endl;
}
