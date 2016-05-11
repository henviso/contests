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

#define SIEVE_MAX 100001
bitset<SIEVE_MAX+1> _prime; 
vi primes;

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.pb(2);
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

ii a[111111];
ii  b[111111];
ii o[1111111];
int pos[111111];

vi c[111111];

int n;

int main(){
	cin >> n;
	sieve();
	
	REP(i, primes.size()) c[primes[i]].push_back(primes[i]-1);
	
	for(int k = 5; k<n+1; k += 2){
		if(isPrime(k)) continue;
		for(int i = 0; i < primes.size(); i++){
			int x = primes[i]-1, y = k-x;
			if(isPrime(y)){
				c[k].push_back(x);
				c[k].push_back(y-1);
				break;
			}
		}
	}
	
	
	for(int k = 4; k<n+1; k += 2){
		if(isPrime(k)) continue;
		c[k] = c[k-1];
		c[k].push_back(1);
	}	
		
	REP(i, n){
		cin >> a[i].first;
		a[i].second = pos[i] = i;
		b[i] = a[i];
	}
	int ans = 0;
	sort(b, b+n);
	REP(i, n){
		int ind = pos[b[i].second];
		int d = abs(ind-i)+1;
		if(ind > i){
			stack<int> st;
			int x = i, y;
			st.push(x);
			REP(k, c[d].size()){
				y = x+c[d][k];
				o[ans++] = ii(min(y,x), max(y,x));
				x = y;
				st.push(y);
			}
			st.pop();
			while(st.size() >= 2){
				x = st.top(); st.pop();
				y = st.top();
				o[ans++] = ii(min(y,x), max(y,x));
			}
		}
		else if(ind < i){
			stack<int> st;
			int x = i, y;
			st.push(x);
			REPD(k, c[d].size()){
				y = x-c[d][k];
				o[ans++] = ii(min(y,x), max(y,x));
				x = y;
				st.push(y);
			}
			st.pop();
			while(st.size() >= 2){
				x = st.top(); st.pop();
				y = st.top();
				o[ans++] = ii(min(y,x), max(y,x));
			}
		}
		pos[a[i].second] = ind;
		swap(a[i], a[ind]);
	}
	printf("%d\n", ans);
	REP(i, ans) printf("%d %d\n", o[i].first+1, o[i].second+1);
}

