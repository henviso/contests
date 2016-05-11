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
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
ll ac[1000000];
ll a[1000000];

int main(){
	cin >> n;
	ac[0] = 0LL;
	REPP(i, 1, n+1){
		cin >> a[i];
		ac[i] = a[i] + ac[i-1];
	}
	ll ans = 0LL;
	for(int i = 2; i<n; i++){
		ll s = ac[i-1];
		ll s2 = ac[n]-ac[i-1];
		ll hi = n+1, lo = i-1, mid, ans = -1LL;
		while(hi-lo > 1){
			mid = (hi+lo)/2LL;
			ll x = ac[mid]-ac[i-1];
			if(x > s) hi = mid;
			else if(x < s) lo = mid;
			else{
				ans = mid;
				break;
			}
		}
		if(ans != -1LL){
			int cnt = 1;
			int k = ans+1;
			while(k <= n && a[k] == 0){ cnt++; k++; }
			k = ans-1;
			while(k > i-1 && a[k] == 0){ cnt++; k--; }
			ans += cnt;
		}
	}
	cout << ans << endl;
}
