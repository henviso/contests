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

int n;

char a[8][8];
string s[100];

int bfs(int k){
	map<int, int> dist; dist[s] = 0; // distance from source s to s is 0 (default)
	queue<int> q; q.push(s);
	// start from source
	while (!q.empty()) {
	int u = q.front(); q.pop();
	// queue: layer by layer!
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
	ii v = AdjList[u][j];
	// for each neighbors of u
	if (!dist.count(v.first)) {
	// dist.find(v.first) == dist.end() also OK
	dist[v.first] = dist[u] + 1;
	// v unvisited + reachable
	q.push(v.first);
	// enqueue v for next step
	} } }
	
}

int main(){
	while(true){
		cin >> n;
		if(n == 0) break;
		CLEAR0(a);
		REP(i, n){
			cin >> s[i];
			a[(s[2]-'1')][(s[1]-'a')] = s[0];
		}
		string S;
		cin >> S;
		a[(s[1]-'1')][(s[0]-'a')] = '#';
		int ans = INF;
		REP(i, n) ans = min(ans, bfs(i));
		cout << ans << endl;
	}
}
