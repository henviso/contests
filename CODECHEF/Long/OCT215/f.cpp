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
#include <iomanip>
#include <utility>    
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
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)

int t;
long long n, k;
long long a[1000000];
long long b[1000000];
long long f[1000000];

void ft_create(vi &t, int n){ t.assign(n+1, 0); }

ll ft_rsq(const vi &t, int b){
	int sum = 0; for(; b; b -= CHECKFIRST(b)) sum += t[b];
	return (ll) sum;
}

ll ft_rsq(const vi &t, int a, int b){
	if(b < a) return 0LL;
	return (ll) ft_rsq(t, b) - (a == 1? 0 : ft_rsq(t, a-1)); 
}

void ft_adjust(vi &t, int k, int v){
	for(; k  <= (int)t.size(); k += CHECKFIRST(k)) t[k] += v;
}

int main(){
	f[0] = f[1] = 1LL;
	for(ll i = 2LL; i<=n; i++) f[i] = (i * f[i-1])%MOD;
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(int i = 1; i<=n; i++) cin >> a[i];
		for(int i = 1; i<=n; i++) cin >> b[i];
		if(n == k){
			bool pos = true;
			int j;
			for(j = 1;j<=n; j++) if(a[j] == b[1]) break;
			for(int l = 0; l<n; l++) if(a[((j-1+l)%n) + 1] != b[l+1]){ pos = false; break; }
			if(pos) cout << b[1] << endl;
			else cout << -1 << endl;	
		}
		else{
			long long ans = 0LL;
			long long aux = 1LL;
			vi ft;
			ft_create(ft, n+10);
			for(int j = 1; j<=n; j++) ft_adjust(ft, j, 1);
			for(int j = 1; j<=n; j++){
				ans += (ft_rsq(ft, 1, b[j]-1) * f[n - j])%MOD;
				ft_adjust(ft, b[j], -1);
			}
			cout << ans+1 << endl;
		}
	}
	
	
	
	
}
