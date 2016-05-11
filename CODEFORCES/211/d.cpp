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

int n, m;
ll a;
ll b[100100], sb[100100];
ll p[100100], sp[100100];

ll can(int k){
	if(k > n) return -1LL;
	ll mon = 0LL;
	ll ans = 0LL;
	REP(i, k){
		//cout << p[k-i] << " " << b[n-i] << endl;
		mon += max(p[k-i] - b[n-i], 0LL);
		ans += p[k-i];
	}
	if(mon <= a) return ans;
	return -1LL;
}

int main(){
	cin >> n >> m >> a;
	REPP(i, 1, n+1) cin >> b[i];
	REPP(i, 1, m+1) cin >> p[i];
	sort(b+1, b+n+1);
	sort(p+1, p+m+1);
	//sb[0] = sp[0] = 0LL;
	//REPP(i, 1, n) sb[i] += sb[i-1]+b[i];
	//REPP(i, 1, m) sp[i] += sp[i-1]+p[i];
	int hi = min(m,n)+1, lo = 0, ansa = 0, ansb = 0, mid;
	while(hi-lo > 1){
		int mid = (hi+lo)/2;
		ll aux = can(mid); 
		if(aux >= 0LL){ ansa = mid; ansb = max(aux - a, 0LL); lo = mid; }
		else hi = mid;
	}
	cout << ansa << " " << ansb << endl;
}

