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


ll pd[210][210][210][2]; //quantas permutações diferentes de tam i com excitacao j eu consigo montar sem usar os maiores com ult exc k
int s[210];
int a[210];
int cnt[201];

ll inv[210];
ll f[210];
ll arr[210][210];
int n, K, t;

#define MOD 1000000007LL

int sum(int a, int b){
	if(a > b) 0;
	return s[b]-s[a-1];
}

ll x, y, d;

//inv modular de a mod b = m é o x
void extendedEuclid(int a, int b){
	if(b == 0){ x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a%b);
	int x1 = y;
	int y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

ll invMult(ll a, ll m){
	extendedEuclid(a, m);
	if(x < 0) x += m;
	return x;
}

ll Arr(int n, int p){
	if(n == 0 || p == 0) return 1LL;
	if(n == p) return f[n];
	ll ans = (f[n] * invMult(f[n-p], MOD))%MOD;
	return ans;
}

void adMod(ll *a, ll x){
	*a += x;
	*a = *a%MOD;
}


int main(){
	f[0] = f[1] = 1;
	for(ll i = 2; i<201; i++) f[i] = (f[i-1]*i)%MOD;
	REP(i, 201) REP(j, i+1) arr[i][j] = Arr(i, j);
	
	scanf(" %d ", &t);
	while(t--){		
		scanf(" %d %d ", &n, &K);
		CLEAR0(s);
		CLEAR0(cnt);
		REPP(i, 1, n+1){
			scanf(" %d ", &a[i]);
			cnt[a[i]]++;
		}
		s[0] = 0;
		REPP(i, 1, 202) s[i] += s[i-1]+cnt[i];
		
		sort(a+1, a+n+1);
		a[0] = 0;
		
		
		CLEAR0(pd);
		pd[0][0][0][0] = 1;
		REPP(i, 1, n+1){
			bool eq = (a[i] == a[i-1]);
			REP(t, i){
				REP(k, i){
					adMod(&pd[i][t][k][0], pd[i-1][t][k][0]);
					if(eq) adMod(&pd[i][t][k][1], pd[i-1][t][k][1]);
					else adMod(&pd[i][t][k][0], pd[i-1][t][k][1]);
					int pad = (i-1-t);
					REP(p, pad+1){
						if(!eq) adMod(&pd[i][t+1+p][k+1][1], (((pd[i-1][t][k][0]+pd[i-1][t][k][1])%MOD) * arr[pad][p])%MOD);
						else{
							adMod(&pd[i][t+1+p][k+1][1], ((pd[i-1][t][k][0] * arr[pad][p])%MOD));
							adMod(&pd[i][t+1+p][k][1], ((pd[i-1][t][k][1] * arr[pad][p])%MOD));
						}
					}
				}
			}
		}
		
		ll ans = 0LL;
		REP(k, K+1){
			ans = (ans+pd[n][n][k][1])%MOD;
		}
		cout << ans << endl;
	}
}

