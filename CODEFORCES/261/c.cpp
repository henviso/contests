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
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
#define EPS 1e-11
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

ll n, k, d;
ll ans[1100][1100];
ll row[1100];
ll s = 0LL;

void bt(ll col){
	if(col == d){
		REP(i, d){
			ans[i][s] = row[i];
		}
		s++;
		return;
	}
	REPP(i, 1LL, k+1LL){
		row[col] = i;
		bt(col+1LL);
		if(s >= n) return;
	}
}

int main(){
	bool pos = true;
	
	cin >> n >> k >> d;
	if(n <= k) REP(i, d) REP(j, n) ans[i][j] = j+1;
	else{
		ll aux = k, D = d-1;
		while(D > 0 && n > aux){
			D--;
			aux *= k;
		}
		if(n > aux){
			pos = false;
			cout << "-1\n";
		}
		else bt(0LL);
	}
	if(pos){
		REP(i, d){
			cout << ans[i][0];
			REPP(j, 1LL, n) cout << " " << ans[i][j];
			cout << endl; 
		}
	}
}
