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
#define MOD 1000000007LL
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

ll x, y, d;
ll F[111111];
ll B[100010][110];

//inv modular de a mod b = m eh o x
void extendedEuclid(int a, int b){
	if(b == 0){ x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a%b);
	ll x1 = y;
	ll y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

ll invMult(ll a, ll m){
	extendedEuclid(a, m);
	x = x%m;
	if(x < 0) x += m;
	return x;
}
	
ll bin(ll n, ll p){
	if(B[n][p] != -1LL) return B[n][p];
	if(p > n) return 0LL;
	ll ans = (F[n] * invMult((F[p] * F[n-p])%MOD, MOD))%MOD; 
	if(ans < 0LL) ans += MOD;
	return ans;
}

int n, m;

ll A[111111];
vi L[111111];
vector< ii > R[111111];

int main(){
	int l, r, k; 
	F[0] = F[1] = 1LL;
	REPP(i, 2, 111111) F[i] = (F[i-1]*i)%MOD;
	REP(i, 100001)
	REP(j, 101) B[i][j] = -1LL;
	
	cin >> n >> m;
	REPP(i, 1, n+1) cin >> A[i];
	REP(i, m){
		cin >> l >> r >> k;
		R[r].pb(ii(l, k));
		L[l-1].pb(k);
	}
	ll S[111]; CLEAR0(S);
	REP(i, n+1){
		
		/*cout << " S :";
		REP(zz, 10) cout << " " << S[zz];
		cout << endl;
		*/
		//cout << " A[" << i << "] " << A[i] << " SIZE " << L[i].size() << endl;
		A[i] = (A[i]+S[0])%MOD; 
		//cout << " A[i] " << A[i] << " S " << S[0] << endl;
		
		REP(j, L[i].size()) S[L[i][j]] = (S[L[i][j]]+1)%MOD;
		
		//remove
		REP(j, R[i].size()){
			int li = R[i][j].first, ki = R[i][j].second;
			REP(z, ki+1){
				S[z] = (S[z] - bin(i-li+ki-z, ki-z))%MOD;
				if(S[z] < 0LL) S[z] += MOD;
			}
		}
		
		ll sum = 0LL;
		REPD(j, 101){
			sum = (sum+S[j])%MOD;
			S[j] = sum;
		}
	}
	printf("%Ld\n", A[1]);
	REPP(i, 2, n+1) printf(" %Ld", A[i]);
	cout << endl;
}





