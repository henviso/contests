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

int n;
int a[1000000];

int solve(int l, int r, int d){
	//cout << " SOLVE " << l << " " << r  << " " << d << endl;
	int ans = 0;
	if(d > 5000) return 0LL;
	REPP(i, l, r+1){
		if(a[i] - d >= 1){ 
			int j = i+1;
			while(j <= r && a[j] - d >= 1) j++;
			ans += min(1 + solve(i, j-1, d+1), j-i);
			i = j-1;
		}
	}
	//cout << " RESP " << l << " " << r  << " " << d << " EH " << ans << endl;
	return ans;
}

int main(){
	cin >> n;
	REP(i, n) cin >> a[i];
	cout << solve(0, n-1, 0) << endl;
}
