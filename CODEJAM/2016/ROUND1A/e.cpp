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
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-40
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);
//L[i]=L[i/2]+1;

int v[1111111];
int c[1111111];
int minc[20][1111111];
int maxv[20][1111111];
int L[1111111];
double f[1111111];
int n, k;

void solve(){
	REP(i, n){
		minc[0][i] = c[i];
		maxv[0][i] = v[i];
	}
	for(int j = 1; (1 << j) <= n; j++){
		for(int i = 0; i + (1 << j) -1 < n; i++){
			minc[j][i] = min(minc[j-1][i], minc[j-1][i + (1 << (j-1))]);
			maxv[j][i] = max(maxv[j-1][i], maxv[j-1][i + (1 << (j-1))]);
		}
	}
}

int calc_min(int l, int r){
	int s = r-l+1;
	return min(minc[L[s]][l], minc[L[s]][r-(1 << L[s])+1]); 
}

int calc_max(int l, int r){
	int s = r-l+1;
	return max(maxv[L[s]][l], maxv[L[s]][r-(1 << L[s])+1]); 
}

int main(){
	scanf(" %d %d ", &n, &k);
	REP(i, n) scanf(" %d ", &v[i]);
	REP(i, n) scanf(" %d ", &c[i]);
	L[1] = 0;
	REPP(i, 2, n+1) L[i] = L[i/2] + 1;
	solve();
	
	vi ve;
	REP(i, n){
		int hi = n-i, lo = -1, mid, ans = -1;
		while(hi-lo>1){
			mid = (hi+lo)/2;
			if(calc_min(i, i+mid) >= 100 * calc_max(i, i+mid)){
				ans = mid;
				lo = mid;
			}
			else hi = mid;
		}
		int x = min(calc_min(i, i), 100 * calc_max(i, i));
		if(ans != -1) x = max(x, min(calc_min(i, i+ans), 100 * calc_max(i, i+ans)));
		if(i+ans+1 < n) x = max(x, min(calc_min(i, i+ans+1), 100 * calc_max(i, i+ans+1)));
		ve.push_back(x);
	}
	sort(ve.begin(), ve.end());
	double expec = 0.0;
	double chance = ((double) k) / n;
		
	REP(i, n-k+1){
		if((n-i) * 10e7 * chance < EPS) break;
		expec += chance * ve[i];
		chance *= ((double) (n-k-i))/(n-1-i);  
	}
	printf("%.10lf\n", expec);
	
}
