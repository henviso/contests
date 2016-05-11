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

int t, n;
ii p[10000];

int dist(int a, int b){
	int dx = (p[a].first - p[b].first);
	int dy = (p[a].second - p[b].second);
	return dx * dx + dy * dy; 
}

int main(){
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> n;
		REP(i, n) cin >> p[i].first >> p[i].second;
		ll ans = 0LL;
		REP(i, n){
			map<int, int> freq;
			REP(j, n){
				if(j == i) continue;
				int d = dist(i, j);
				freq[d]++;
			}
			for(map<int, int>::iterator it = freq.begin(); it!=freq.end(); it++) ans += (ll) ((it->second * (it->second-1))/2);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}

