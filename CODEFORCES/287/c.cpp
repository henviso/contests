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

ll h, n;
ll ans = 0;
bool ESQ = true;

pair< ll, ll > rg;

ll leafs(){
	return (1LL << h);
}

bool inRange(ll x, pair<ll, ll> p){
	return ((x >= p.first) && (x <= p.second)); 
}

pair< ll, ll > side(bool esq){
	ll mid = (rg.second-rg.first+1LL)/2LL;
	if(esq) return make_pair(rg.first, rg.second-mid);
	return make_pair(rg.first+mid, rg.second);
}

bool inSide(bool esq){
	return inRange(n, side(esq));
}

void move(bool esq){
	rg = side(esq);
	h--;
}

int main(){
	cin >> h >> n;
	rg = make_pair(1LL, (1LL << h));
	while(h){
		if(inSide(ESQ)){
			ans++;
		}
		else{
			ESQ = !ESQ;
			ans += leafs();
		}
		move(ESQ);
		ESQ = !ESQ;
	}
	cout << ans << endl;
}
