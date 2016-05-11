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
typedef pair<ll,ll> pll;
typedef vector< ii > vii;
typedef vector< ll > vll;
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

ll t, l, n, m, d;
priority_queue<pll, vector<pll>, greater<pll> > wq;
priority_queue<ll, vll, greater<ll> > dq;
queue<ll> q;

int main(){
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> l >> n >> m >> d;
		
		ll x, z, r, ans = 0LL;
		pll y;
		
		while(!q.empty()) q.pop();
		while(!wq.empty()) wq.pop();
		while(!dq.empty()) dq.pop();
		REP(i, n){
			cin >> x;
			wq.push(pll(x, x));
		}
		REP(i, l){
			y = wq.top(); wq.pop();
			r = y.first; q.push(r);
			ans = max(ans, r);
			y.first = r + y.second;
			wq.push(y);
		}
		if(m >= q.size()){
			ans += d;
		}
		else{
			REP(i, m) dq.push(0LL);
			while(!q.empty()){
				x = q.front(); q.pop();
				z = dq.top(); dq.pop();
				r = max(x, z) + d;
				ans = max(r, ans);
				dq.push(r);
			}
		} 
		
		cout << "Case #" << tc << ": " << ans << endl;
	}
}

