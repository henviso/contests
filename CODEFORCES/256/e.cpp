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

ll X, k;
vector<ll> ans;
map< ll, vector<ll> > divs;

vector<ll> divisors(ll N){
	vector<ll> d;
	for(ll i = 1; i*i <= N; i++){
		if(N%i == 0LL){
			d.push_back(i);
			if(i*i != N) d.push_back(N/i);
		}
	}
	return d;
}

void precalc(){
	vector<ll> d = divisors(X);
	REP(i, d.size()){
		vector<ll> D = divisors(d[i]);
		sort(D.begin(), D.end());
		divs[d[i]] = D;
	} 
}

void dfs(ll x, ll depth){
	if(ans.size() == 100000) return;
	if(depth == 0){
		ans.push_back(x);
		return;
	}
	vector<ll> d = divs[x];
	REP(i, d.size()){
		if(ans.size() == 100000) return;
		if(d[i] == 1LL) ans.push_back(1LL);
		else dfs(d[i], depth-1);
	}
}

int main(){
    cin >> X >> k;
    precalc();
    dfs(X, k);
    cout << ans[0];
    REPP(i, 1, ans.size()) cout << " " << ans[i];
    cout << endl;
    
}
