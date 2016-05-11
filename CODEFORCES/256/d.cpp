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
#define EPS 1e-11
//scanf(" %d ", &t);

ll n, m, k;
ll eq, le;

void calc(ll x){
	eq = le = 0;
	for(ll i = 1LL; i<n+1LL; i++){
		ll aux = x/i;
		if(aux > m){
			le += m;
		}
		else{
			if(x%i == 0LL){ le += aux-1LL; eq++; }
			else le += aux;
		}
	}
}

int main(){
    cin >> n >> m >> k;
    ll hi = n*m+1, lo = 0LL, mid, ans = 0LL;
    while(hi-lo > 1LL){
		mid = (hi+lo)/2LL;
		calc(mid);
		
		if(le < k){
			if(le+eq >= k){
				ans = mid;
				break;
			}
			else lo = mid;
		}
		else hi = mid;
	}
	cout << ans << endl;
}
