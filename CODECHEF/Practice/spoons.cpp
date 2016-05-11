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
#define INF 10000000000000000LL
#define EPS 1e-7
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

ull a[32] = { 2ULL, 6ULL, 20ULL, 70ULL, 252ULL, 924ULL, 3432ULL, 12870ULL, 48620ULL, 184756ULL, 705432ULL,
		  2704156ULL, 10400600ULL, 40116600ULL,155117520ULL,601080390ULL,2333606220ULL,9075135300ULL,35345263800ULL
		  ,137846528820ULL,538257874440ULL,2104098963720ULL,8233430727600ULL,32247603683100ULL,126410606437752ULL
		  ,495918532948104ULL,1946939425648112ULL,7648690600760440ULL,30067266499541040ULL,118264581564861424ULL
		  ,465428353255261088ULL,1832624140942590534ULL };

vector<ull> v;

void pc(){
	REP(i, 32){
		v.pb(a[i]/2);
		v.pb(a[i]);
	}
	//REP(i, v.size()) cout << v[i] << endl;
}

ull cities(ull n){
	ull pos = (lower_bound(ALL(v), n) - v.begin())+1ULL;
	return pos;
}

int main(){
	pc();
	int t;
	cin >> t;
	while(t--){
		ull n;
		scanf(" %llu", &n);
		printf("%llu\n", cities(n));
	}
}
