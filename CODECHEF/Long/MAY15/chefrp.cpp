#include <iostream>
#include <cstdio>
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
#include <cstring>
#include <unistd.h>
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
#define MOD 1000000007LL
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
//__builtin_popcount(m)
//scanf(" %d ", &t);

map<int, int> cnt;
ll p2[100100];
ll n, t;

int main(){
	p2[0] = 1LL;
	REPP(i, 1, 100001) p2[i] = (p2[i-1]*2LL)%MOD;
    scanf(" %lld ", &t);
    while(t--){
		cnt.clear();
		scanf(" %lld ", &n);
		int x;
		REP(i, n){ scanf(" %d ", &x); cnt[x]++; }
		ll ans = 0LL;
		ll f = n;
		for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
			ll a = p2[it->second];
			ans = (ans - (p2[f] - p2[f-it->second]))%MOD;
			f -= it->second;
		}
		f = n;
		for(map<int, int>::reverse_iterator it = cnt.rbegin(); it != cnt.rend(); it++){
			ll a = p2[it->second];
			ans = (ans + (p2[f] - p2[f-it->second]))%MOD;
			f -= it->second;
		}
		printf("%lld\n", ans);
	}
}
