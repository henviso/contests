
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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n, k;
ll a[100100];

int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d %d ", &n, &k);
		REP(i, k) scanf(" %lld ", &a[i]);
		a[k++] = ((ll) n+1);
		sort(a, a+k);
		ll S = 0;
		ll lst = 0;
		ll ans = 0LL;
		int i;
		for(i = 0; i<k; i++){
			if(lst != a[i]-1LL){
				ll k = a[i]-1LL-lst;
				ll s = (k*(k+1LL))/2LL;
				S += s + k*lst;
			}
			if(a[i] > S){
				ans = a[i];
				break;
			}
			lst = a[i];
		}
		if(i == k) ans = S+1;
		if(ans%2LL) printf("Chef\n");
		else printf("Mom\n");
	}
}
