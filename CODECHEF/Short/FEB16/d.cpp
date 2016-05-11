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

int n;
map<int, vi> g;
int a[1111111];

int main(){
	scanf(" %d ", &n);
	int x;
	REP(i, n){
		scanf(" %d ", &x);
		a[i] = x;
		g[x].push_back(i);
	}
	ll ANS = 0LL;
	for( map<int, vi>::iterator it = g.begin(); it != g.end(); it++){
		x = it->first;
		vi v = it->second;
		
		REP(i, v.size()){
			int hi = v.size(), lo = i, mid, ans = i;
			while(hi-lo > 1){
				mid = (hi+lo)/2;
				int c = mid-i+1;
				int d = v[mid]-v[i]+1;
				if((d/2) < c){
					ans = mid;
					lo = mid;
				}
				else hi = mid;
			}
			ANS += (ll) (ans - i + 1);
		}
		
		int hit = 0, miss = 0;
		REP(i, v.size()){
			if(i) miss += v[i]-v[i-1]-1;
			hit++;
			int d = hit-(miss+1);
			ANS += (ll) min(v[0], max(0, d));  
		}
		hit = 0, miss = 0;
		for(int i = v.size()-1; i>=0; i--){
			if(i < v.size()-1) miss += v[i+1]-v[i]-1;
			hit++;
			int d = hit-(miss+1);
			ANS += (ll) min(n -1 - v[v.size()-1], max(0, d));
		}
	}
	cout << ANS << endl;
}

