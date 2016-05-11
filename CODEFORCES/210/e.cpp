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
#define MOD 1000000007LL

ll n, k;
ll pd[2100][2100];
string s;

ll solve(ll x, ll q, ll h){
	//cout << " SOLVE " << x << " " << q << " " << h << endl;
	
	if(q < 0LL){
		//cout << "RETORNANDO " << 0 << endl;
		return 0LL;
	}
	if(x == n){
		if(q == 0LL){
			//cout << "RETORNANDO " << 1 << endl;
			return 1LL;
		}
		//cout << " RETORNANDO " << 0 << endl;
		return 0LL;
	}
	
	//if(pd[x][q] == -1LL){
		ll ans = 0LL;
		//pd[x][q] = 0LL;
		//pd[x][q] 
		ans += ((ll) ('z' - s[x])) * solve(x+1, q-((1+h)*(n-x)), 0) + solve(x+1, q, h+1) + ((ll) (s[x] - 'a')) * solve(x+1, q, 0);
		ans = ans%MOD;
		//cout << " RETORNANDO " << ans << endl;
	//} 
	return ans;
}

int main(){
	cin >> n >> k;
	cin >> s;
	
	CLEAR0(pd);
	REP(q, 2001) pd[n%2][0][q] = 1LL;
	for(int i = n-1; i>=0; i--){
		
	}
		
	
		REP(j, k+1) pd[2][i][j] = -1LL;
	}
	cout << solve(0LL, k, 0LL) << endl;
	
}
