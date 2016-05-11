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
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
int x[100], y[100], r[100];

int main(){
	cin >> n;
	REP(i, n) cin >> x[i] >> y[i] >> r[i];
	int ans = 0;
	REPP(row, 1, 1001)
	REPP(col, 1, 1001){
		int cnt = 0;
		REP(i, n){
			if(((col-x[i])*(col-x[i]) + (row-y[i])*(row-y[i])) <= r[i]*r[i]) cnt++;
			if(cnt >= 2){ ans++;	break; }
			
		}
	}
	cout << ans << endl;
}
