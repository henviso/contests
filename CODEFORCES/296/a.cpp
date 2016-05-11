#include <iostream>
#include <cstdio>
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
#include <cstring>
#include <unistd.h>
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
#define EPS 1e-9
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

int w, h, n, x;
char c;
map<int, int> hor, ver;
set<int> H, V;

int main(){
	scanf(" %d %d %d ", &w, &h, &n);
	H.insert(0); H.insert(h);
	V.insert(0); V.insert(w);
	hor[h] = 1;
	ver[w] = 1;
	REP(i, n){
		scanf(" %c %d ", &c, &x);
		if(c == 'V'){
			set<int>::iterator it = V.insert(x).first;
			set<int>::iterator pv = it, nx = it; pv--; nx++;
			int k = *nx - *pv; 
			if(--ver[k] == 0) ver.erase(k);
			ver[*nx-x]++;
			ver[x-*pv]++;
			V.insert(x);
		}
		else{
			set<int>::iterator it = H.insert(x).first; 
			set<int>::iterator pv = it, nx = it; pv--; nx++;
			int k = *nx - *pv; 
			if(--hor[k] == 0) hor.erase(k);
			hor[*nx-x]++;
			hor[x-*pv]++;
			H.insert(x);
		}
		
		ll ans = (ll (ver.rbegin()->first)) * (ll (hor.rbegin()->first));
		printf("%lld\n", ans);
	}
}
