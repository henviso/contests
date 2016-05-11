
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

int t, n;
vi l[2010];
vi r[2010];

int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d ", &n);
		int a, b;
		REP(i, 2001){ l[i].clear(); r[i].clear(); }
		REP(i, n){
			scanf(" %d %d ", &a, &b);
			l[a].push_back(i);
			r[b].push_back(i);
		}
		bitset<100100> bb; bb.reset();
		int ans = 0;
		vi k;
		REP(i, 2001){
			REP(j, l[i].size()){
				int c = l[i][j];
				k.push_back(c);
			}
			bool exp = false;
			REP(j, r[i].size()){
				int c = r[i][j];
				if(!bb[c]){ exp = true; break; }
			}
			if(exp){
				REP(j, k.size()) bb[k[j]] = true;
				ans++;
				k.clear();
			}
		}
		printf("%d\n", ans);
	}
}
