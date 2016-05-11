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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//scanf(" %d ", &t);

#define SIEVE_MAX 10000005
bitset<SIEVE_MAX+1> _prime; 

int n;
int cnt[10000100];
int ndiv[10000100];
ll ans[10000100];

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; 
	ndiv[2] += cnt[2];
	for(ll i = 4; i<SIEVE_MAX; i+=2){
		_prime[i] = 0;
		ndiv[2] += cnt[i];
	}
	//cout << " NDIV " << 2 << " EH " << ndiv[2] << endl;
	for(ll i = 3; i<SIEVE_MAX; i+=2){
		if(_prime[i]){ 
			ndiv[i] += cnt[i];
			for(ll j = i*2; j<SIEVE_MAX; j+=i){
				_prime[j] = 0;
				ndiv[i] += cnt[j];
			}
			//cout << " NDIV " << i << " EH " << ndiv[i] << endl;
		}
	}
}

int main(){
	int x;
	scanf(" %d ", &n);
	CLEAR0(ndiv); CLEAR0(cnt);
	REP(i, n){
		scanf(" %d ", &x);
		cnt[x]++;
	}
	
	sieve();
	
	ans[0] = 0LL;
	for(int i = 1; i<=10000000; i++){
		ans[i] = ans[i-1] + ((ll) ndiv[i]);
	}
	
	int q, l, r;
	scanf(" %d ", &q);
	REP(i, q){
		scanf(" %d %d ", &l, &r);
		l = min(10000000, l);
		r = min(10000000, r);
		cout << ans[r] - ans[l-1] << endl;
	}
	
	//cout << " NR PRIMOS " << primes.size() << " " << primes[primes.size()-1] << endl;
}
