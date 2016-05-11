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

int t, n;
int bff[1111];
bitset<1111> vis;
vi cyc;
int bstPathTo[1111], bstPathFrom[1111];

bool cycle(int x){
	int s = x;
	vis.reset();
	vis[s] = true;
	cyc.clear();
	cyc.push_back(s);
	while(!vis[(x = bff[x])]){
		cyc.push_back(x);
		vis[x] = true;
	}
	if(x == s) return true;
	return false;
}

void pathFrom(int x){
	int s = x;
	vis.reset();
	vis[s] = true;
	int t = 1;
	while(!vis[(x = bff[x])] && bstPathTo[x] == -1){
		t++;
		vis[x] = true;
	}
	if(bstPathTo[x] >= 0) bstPathTo[x] = max(bstPathTo[x], t);	
	return;
}

int main(){
	cin >> t;
	for(int tc = 1; tc<=t; tc++){
		cin >> n;
		int ans = 0;
		REPP(i, 1, n+1){
			bstPathTo[i] = -1;
			cin >> bff[i];
		}
		REPP(i, 1, n+1){
			if(cycle(i)){
				ans = max(ans, (int) cyc.size());
				if(cyc.size() == 2) REP(j, cyc.size()) bstPathTo[cyc[j]] = 0;
				else REP(j, cyc.size()) bstPathTo[cyc[j]] = -cyc.size();
			}
		}
		//cout << " FIZ CICLOS\n";
		REPP(i, 1, n+1)	if(bstPathTo[i] == -1) pathFrom(i);
		int tans = 0;
		REPP(i, 1, n+1){
			if(bstPathTo[i] >= 0) tans += bstPathTo[i]+1;
		}
		ans = max(ans, tans);
		cout << "Case #" << tc << ": " << ans << endl;
	}
}