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
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
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
//__builtin_popcount(m)
//scanf(" %d ", &t);
//ios::sync_with_stdio(false);

#define SIEVE_MAX 100000

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

vi primeFactors(ll N) {
	vi factors;     //TROCAR PRA vll SE O NUMERO FOR > QUE INT
	ll PF_idx = 0, PF = primes[PF_idx];
	while(N > 1 && (PF*PF <= N)){
		while(N%PF == 0){ N /= PF; factors.push_back((int) PF); }
		PF = primes[++PF_idx];
	}
	if(N > 1) factors.push_back((int) N);
	return factors; 
}

vi uniquePrimeFactors(ll N) {
	vi factors;     //TROCAR PRA vll SE O NUMERO FOR > QUE INT
	ll PF_idx = 0, PF = primes[PF_idx];
	while(N > 1 && (PF*PF <= N)){
		if(N%PF == 0){
			factors.push_back((int) PF); 
			while(N%PF == 0){ N /= PF; }
		}
		PF = primes[++PF_idx];
	}
	if(N > 1) factors.push_back((int) N);
	return factors; 
}

struct QUERY{
	int G;
	int x, y;
	int id;
};

//bool cmp(const QUERY &a, const QUERY &b, 

int a[100100];
int n, m;

vii A[9600];
vii ST[9600];

void st_build(vii &st, int id, int vertex, int L, int R) {
  if (L == R){                              //as L == R, either one is fine
    st[vertex].first = A[id][L].second;
    st[vertex].second = 1;                        //store the index
  }
  else {   // recursively compute the values in the left and right subtrees
    int nL = 2 * vertex, nR = 2 * vertex + 1;
    st_build(st, id, nL, L              , (L + R) / 2);
    st_build(st, id, nR, (L + R) / 2 + 1, R          );
    ii lContent = st[nL]     , rContent = st[nR];
    int lValue   = lContent.first, rValue   = rContent.first;
    st[vertex] = (lValue >= rValue) ? lContent : rContent;
    if(lValue == rValue) st[vertex].second += rContent.second;
}}

void st_create(vii &st, int id) {       // if original array size is N,
     // the required segment tree array length is 2*2^(floor(log2(N)) + 1);
  int len = (int)(2*pow(2.0, floor((log((double)A[id].size())/log(2.0)) + 1)));
  st.assign(len, ii(0,0)); // create vector of size `len' and fill it with zeroes
  st_build(st, id, 1, 0, (int)A[id].size() - 1);              // recursive build
}

ii st_rmq(vii &st, int id, int vertex, int L, int R, int i, int j) {
  if (i >  R || j <  L) return ii(-1,-1);   // current segment outside query range
  if (L >= i && R <= j) return st[vertex];            // inside query range

     // compute the min position in the left and right part of the interval
  ii p1 = st_rmq(st, id, 2 * vertex    , L              , (L+R) / 2, i, j);
  ii p2 = st_rmq(st, id, 2 * vertex + 1, (L+R) / 2 + 1, R          , i, j);
                        // return the position where the overall minimum is
  if(p1.first == -1) return p2;     // if we try to access segment outside query
  if(p2.first == -1) return p1;
  if(p1.first > p2.first) return p1;
  else if(p1.first < p2.first) return p2;
  else return ii(p1.first, p1.second+p2.second);
}

ii st_rmq(vii &st, int id, int i, int j) {     // function overloading
  return st_rmq(st, id, 1, 0, A[id].size() - 1, i, j); }

int main(){
	sieve();
	cin >> n >> m;
	int POS[100100];
	REP(i, n) cin >> a[i];
	REP(i, primes.size()){
		//cout << " PRIMO " << primes[i] << endl;
		POS[primes[i]] = i;
	}
	REP(i, n){
		vi upf = uniquePrimeFactors(a[i]);
		//cout << "EL " << a[i] << " FATORES: "; REP(j, upf.size()) cout << upf[j] << " "; cout << endl;
		REP(j, upf.size()){
			//cout << "a[i] = " << a[i] << " SENDO COLOCADO NA LISTA DO " << upf[j] << " POS " << POS[upf[j]] << endl;
			A[POS[upf[j]]].push_back(ii(i+1, a[i]));
		}
	}
	
	//REP(i, n) if(isPrime(a[i])) A[a[i]][i] = a[i];  
	REP(i, primes.size()) if(A[i].size()) st_create(ST[i], i); 
	int G, x, y;
	REP(i, m){
		cin >> G >> x >> y;
		ii ans(-1, -1);
		vi upf = uniquePrimeFactors(G);
		REP(j, upf.size()){
			int f = POS[upf[j]];
			int l = lower_bound(A[f].begin(), A[f].end(), ii(x, -1)) - A[f].begin();
			if(l == A[f].size()) continue;
			int r = lower_bound(A[f].begin(), A[f].end(), ii(y+1, -1)) - A[f].begin();
			ii tans = st_rmq(ST[f], f, l, r-1);
			//cout << " TO EM G " << G << " PRIMO " << upf[j] << " LISTA EH " << endl;
			//REP(k, A[f].size()) cout << "(" << A[f][k].first << "," << A[f][k].second << ") ";
			//cout << "\nRESP " << tans.first << " " << tans.second << endl;
			if(tans.first > ans.first) ans = tans;
		}
		if(ans.first == -1) cout << -1 << " " << -1 << endl;
		else cout << ans.first << " " << ans.second << endl;
	}

}
