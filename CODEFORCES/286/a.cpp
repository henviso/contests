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

#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
ll d;
int a[30100];
int b[30100][1000];

ll sum(ll a, ll b){ //soma de a ate b inclusive
	ll ans = ((b*(b-1LL)) - ((a-2LL)*(a-1LL))) /2LL;
	return ans;
}

int main(){
	cin >> n >> d;
	int x;
	CLEAR0(a);
	REP(i, n){
		cin >> x;
		a[x]++;
	}
	
	
	ll lo = d-1LL, hi = d+1LL;
	while(lo > 0LL && sum(lo, d) <= 30000LL) lo--;
	lo++;
	while(hi <= 30000LL && sum(d, hi) <= 30000LL) hi++;
	hi--;
	//cout << " HI " << hi << endl; 
	//cout << " LO " << lo << endl;
	
	CLEAR0(b);
	int ans = b[d][d-lo] = a[d]+1;
	for(ll i = d; i<30001LL; i++){
		for(ll J = lo; J<hi+1LL; J++){
			ll j = J-lo;
			if(b[i][j] == 0) continue;
			for(ll k = -1; k<2LL; k++){
				if(j+k >= 0LL && J+k > 0 && i+J+k < 30001LL){
					b[i+J+k][j+k] = max(b[i+J+k][j+k], b[i][j]+a[i+J+k]);
					ans = max(ans, b[i+J+k][j+k]);
				}
			}
		}
	}
	cout << ans-1 << endl;
	
	
}
