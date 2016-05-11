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

#define SIEVE_MAX 1000
bitset<SIEVE_MAX+1> _prime; 
vi primes;
int nPrimes[1000];

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.pb(2);
	nPrimes[0] = nPrimes[1] = 0; nPrimes[2] = 1;
	for(ll i = 4; i<SIEVE_MAX; i+=2) _prime[i] = 0;
	for(ll i = 3; i<SIEVE_MAX; i++){
		if(_prime[i]){ 
			for(ll j = i*i; j<SIEVE_MAX; j+=2*i) _prime[j] = 0;
			primes.push_back((int) i);
		}
		nPrimes[i] = primes.size();
	}
}


int t;
int r, c;
char m[600][600];
int rgt[600][600];
int l[600][600];
int u[600][600];
int d[600][600];

int main(){
	sieve();
	
	cin >> t;
	while(t--){
		scanf(" %d %d ", &r, &c);
		
		CLEAR0(u); CLEAR0(d); CLEAR0(l); CLEAR0(rgt);
		REPP(i, 1, r+1){
			REPP(j, 1, c+1){
				scanf(" %c ", &m[i][j]);
				if(m[i][j] == '#') u[i][j] = d[i][j] = l[i][j] = rgt[i][j] = 0;
				else{
					u[i][j] = u[i-1][j]+1;
					l[i][j] = l[i][j-1]+1;
				}
			}
		}
		int mns = 0;
		for(int i = r; i>0; i--){
			for(int j = c; j>0; j--){
				if(m[i][j] == '^'){
					d[i][j] = d[i+1][j]+1;
					rgt[i][j] = rgt[i][j+1]+1;
					mns += nPrimes[min(min(u[i][j], d[i][j]), min(l[i][j], rgt[i][j]))-1];
				}
			}
		}
		printf("%d\n", mns);
	}
}
