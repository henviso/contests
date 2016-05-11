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
typedef vector< ll > vll;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(ll i = 0LL; i<n; i++)
#define REPP(i,a,n) for(ll i = a; i<n; i++)
#define REPD(i,n) for(ll i = n-1; i>-1LL; i--)
#define REPDP(i,a,n) for(ll i = n-1; i>=a; i--)
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

class Fenwick{
  ll *m, *mt, N;
public:
  Fenwick(ll n);
  Fenwick(ll a[], ll n);
  void add_range(ll r, ll d);
  void add_range(ll l, ll r, ll d);
  ll sum(ll r);
  ll sum(ll l, ll r);
};

Fenwick::Fenwick(ll n){
  N = n;
  m = new ll[N];
  mt = new ll[N];
  memset(m, 0, sizeof(ll)*N);
  memset(mt, 0, sizeof(ll)*N);
}

Fenwick::Fenwick(ll a[], ll n){
  N = n;
  m = new ll[N];
  mt = new ll[N];
  memset(m, 0, sizeof(ll)*N);
  memset(mt, 0, sizeof(ll)*N);
  for(ll i=0;i<N;++i){
    m[i] += a[i];
    if((i|(i+1))<N) m[i|(i+1)] += m[i];
  }
}

void Fenwick::add_range(ll r, ll d){
  if(r<0) return;
  for(ll i=r;i>=0;i=(i&(i+1))-1) mt[i] += d;
  for(ll i=r|(r+1);i<N;i|=i+1) m[i] += d*(r-(i&(i+1))+1);
}

void Fenwick::add_range(ll l, ll r, ll d){
  add_range(r, d);
  add_range(l-1, -d);
}

ll Fenwick::sum(ll r){
  if(r<0) return 0;
  ll res = 0;
  for(ll i=r;i>=0;i=(i&(i+1))-1) res += m[i] + mt[i]*(i-(i&(i+1))+1);
  for(ll i=r|(r+1);i<N;i|=i+1) res += mt[i]*(r-(i&(i+1))+1);
  return res;
}

ll Fenwick::sum(ll l, ll r){
  if(l > r) return 0LL;
  return sum(r) - sum(l-1);
}


ll n;
ll cd[1000100];
Fenwick *ft;

int main(){
		while(1){
			//cout << " NOVO CASO \n\n\n\n\n";
			
			scanf(" %lld ", &n);
			if(n == 0) break;
			ll s = 0LL;
			REP(i, n){
				scanf(" %lld ", &cd[i]);
				s += cd[i];
			}
			if(s+1 < n){
				printf("-1\n");
				continue;
			}
			
			sort(cd, cd+n);
			reverse(cd, cd+n);
			
			ll t = 0LL;
			ll dec[1000100]; CLEAR0(dec);
			ll base = 0LL;
			ll av = 1LL, p = 0;
			ll cp = 1;
			while(cp < n){
				base -= dec[t];
				//cout << " T " << t << " AV " << av << " BASE " << base << endl;
				while(p < n && av){
					if(cd[p] > 0LL){
						dec[t + cd[t]]++;
						base++;
						av--;
					}
					p++;
				}
					
				t++;
				av += base;
				cp += base;
			}
				
				//cout << "vetor: "; REP(i, n) cout << ft->sum(i, i) << " ";
				//cout << endl;
			printf("%lld\n", t+1);
			
		}
}

