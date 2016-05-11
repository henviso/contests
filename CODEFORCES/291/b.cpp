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
int c[400], l[400];

int gcd(int a, int b) {
  if(a<0) a = -a;
  if(b<0) b = -b;

  if(b == 0)
    return a;
  else
    return gcd(b, a%b);
}

map<int, int> pd[500];

void solve(){
	pd[0][0] = 0;
	REPP(i, 1, n+1){
		pd[i] = pd[i-1];
		for(map<int, int>::iterator it = pd[i-1].begin(); it!=pd[i-1].end(); it++){
			int g = gcd(it->first, l[i]); 
			int x = it->second + c[i];
			//cout << "COLOCANDO " << l[i] << " EM " << it->first << endl;
			//cout << "FICA " << g << " COM PRECO " << x << endl;
			if(pd[i].count(g)) pd[i][g] = min(pd[i][g], x);
			else pd[i][g] = x;
		}
	}
}

int main(){
	cin >> n;
	REPP(i, 1, n+1) cin >> l[i];
	REPP(i, 1, n+1) cin >> c[i];
	int g = l[0];
	//REPP(i, 1, n+1){
	//	g = gcd(g, l[i]);
	//	vi pf = primeFactors(l[i]);
	//	REP(j, pf.size()) cout << pf[j] << " ";
	//	cout << endl << l[i] << " G " << g << endl << endl << endl;
	//}
	solve();
	if(pd[n].count(1)) cout << pd[n][1] << endl;
	else cout << -1 << endl;
}

