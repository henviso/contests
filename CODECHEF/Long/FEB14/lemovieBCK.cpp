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


ll pd[210][210][210]; //quantas permutações diferentes de tam i com excitacao j eu consigo montar sem usar os maiores com ult exc k
int s[210];
int a[210];
int cnt[201];

ll inv[210];
ll f[210];
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

ll arr(int n, int p){
	if(n == p) return f[n];
	ll ans = (f[n] * inv[n-p])%MOD;
	return ans;
}

int main(){
	f[0] = f[1] = 1;
	for(ll i = 2; i<201; i++) f[i] = (f[i-1]*i)%MOD;
	REP(i, 201){
		inv[i] = invMult((ll) i, MOD);
	}
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
		
		vi v;
		REPP(i, 1, n+1) if(v.empty() || v[v.size()-1] != a[i]) v.pb(a[i]);
		int N = v.size();
		
		
		//pd[I PRIMEIROS][SEQ TAM T][LCS K];
		CLEAR0(pd);
		pd[0][0][0] = 1;
		REPP(i, 1, N+1){
			int tot = sum(1, v[i-1]);
			//cout << " TOTAL " << tot << endl;
			REP(t, tot+1){
				REP(k, i+1){
					if(i<N) pd[i][t][k] = ((pd[i][t][k] + pd[i-1][t][k])%MOD)%MOD;
					int qnt = cnt[v[i-1]];
					REPP(q, 1, qnt+1){
						//cout << " ARR " << qnt << " TOMADOS " << q << " A " << q << " " << arr(qnt, q) << endl;
						if(t-q >= 0){
							pd[i][t][k] = (pd[i][t][k] + (pd[i-1][t-q][k-1] * arr(qnt, q))%MOD)%MOD;
							//pd[i][t][k] = (pd[i][t][k] + (pd[i-1][t-q][k-1] * arr(qnt, q))%MOD)%MOD;
						}
						//cout << " i " << i << " t " << t << " k " << k << " Q " << q << " pd[i-1][t-q][k-1] " << pd[i-1][t-q][k-1] << endl;
					}
				}
			}
		}
		
		cout << " V:"; REP(i, v.size()) cout << " " << v[i];
		cout << endl;
		REP(i, N+1){
			cout << endl << endl << " I " << i << endl;
			REP(t, 20){
				REP(k, 20) cout << pd[i][t][k] << " ";
				cout << endl;
			}
		}
		
		
		ll ans = 0LL;
		REP(k, K+1){
			REPP(t, 1, n+1){
				ll aux = (pd[N][t][k] * f[n-t])%MOD;
				ans = (ans+aux)%MOD;
			}
		}
		
		cout << ans << endl;
		/*
		/325327
		/123456
		/111888888
		
		//dp[k][t][l]
		
		dp[1][1][v[N-1]] = sum(v[N-1], v[N-1]);
		REPP(k, 2, 201){
			REPP(t, k-1, 201){
				REPP(l, 1, 201){
						if(p[k-1][t][l]){
							REPP(1, nl, l){
								REPP(q, 1, cnt[nl]+1){
									dp[k][t+q][nl] += (f[i] * dp[k][t+q][nl])%MOD; 
									dp[k][t+q][nl] = dp[k][t+q][nl]%MOD;
								}
							}
						} 
					}
					REPP( 
				ll dSum = 0, uSum[222];
				uSum[201] = 0LL;
				for(int l = 200; l>=1; l--) uSum[l] = (uSum[l+1]+((cnt[l]*p[i-1][k][l+1])%MOD))%MOD;
				REPP(l, 1, 201){
					p[i][k][l] = uSum[l+1];
					p[i][k][l] = (p[i][k][l]+(dSum[l]+cnt[l])%MOD)%MOD;
					dSum = (dSum+p[i-1][k-1][l])%MOD;
				}
			}
		}
		ll ans = 0LL;
		REP(k, K+1)
		REPP(l, 1, 200){
			ans = (ans+p[n][k][l])%MOD;
		}
		cout << ans << endl;
		*/
	}
}

