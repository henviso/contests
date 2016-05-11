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

typedef long long unsigned hash;

#define MAXN 1000100
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXN];
char str[MAXN];
int a[MAXN];
int n, m, t;
bitset<MAXN] match;
bitset<MAXN] free;

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
	p[0] = 0ULL;
	REP(j, t){
		p[j+1] = p[j]*B + str[j];
	}
}

hash calc_dhash(int a, int b) {
	if (a > b) return 0;
	return p[b+1] - p[a] * power[b - a + 1];
}


int main(){
	cin >> n >> m >> str;
	t = strlen(str);
	REP(i, m) cin >> a[i];
	REP(i, n) if(calc_dhash(i, n-1) == calc_dhash(0, n-1-i)) match[i] = true;
	free.set();
	REP(i, m){
		
	}
}

