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
#define MOD 1000000009LL
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

set< int > cand;
map< ii, int > cubes;
int m;
ii c[100100];
int p;
ll pot[100100];
ll ans = 0LL;

bool onlyOne(ii &x, ii &y){
	REPP(i, -1, 2){
		ii k(y.first+i, y.second-1);
		if(k == x) continue;
		if(cubes.count(k)) return false;
	}
	return true;
}

bool rem(ii &x){
	REPP(i, -1, 2){
		ii k(x.first+i, x.second+1);
		if(cubes.count(k) && onlyOne(x, k)) return false;
	}
	return true;
}

void remove(int x){
	//cout << " TIRANDO " << x << endl;
	ans = (ans + (x * pot[p--]))%MOD;
	cand.erase(x);
	cubes.erase(c[x]);
	REPP(i, -1, 2){
		ii k(c[x].first+i, c[x].second-1);
		if(cubes.count(k) && rem(k)){
			cand.insert(cubes[k]);
		}
	}
	REPP(i, -2, 3){
		if(i == 0) continue;
		ii k(c[x].first+i, c[x].second);
		if(cubes.count(k) && cand.count(cubes[k])){
			if(!rem(k)) cand.erase(cubes[k]);
		}
	}
}

int main(){
	cin >> m; p = m-1;
	pot[0] = 1LL;
	REPP(i, 1, 100001) pot[i] = (m * pot[i-1])%MOD;
	REP(i, m){
		cin >> c[i].first >> c[i].second;
		cubes[c[i]] = i;
	}
	for(map< ii, int >::iterator it = cubes.begin(); it != cubes.end(); it++){
		ii x = it->first; int k = it->second;
		if(rem(x)) cand.insert(k);
	}
	bool vas = true;
	while(!cand.empty()){
		if(vas) remove(*(cand.rbegin()));
		else remove(*(cand.begin()));
		vas = !vas;
	}
	cout << ans << endl;
}
