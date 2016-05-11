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
#define MOD 1000000007LL
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

#define MAXS 2
#define MAXN 200100
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXS][MAXN];
char str[MAXS][MAXN];
int t[MAXS], n;

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
	REP(i, n){
		p[i][0] = 0ULL;
		REP(j, t[i]){
			p[i][j+1] = p[i][j]*B + str[i][j];
		}
	}
}

void print(int e, int a, int b){
	for(int i = a; i<=b; i++){
		printf("%c", str[e][i]);
	}
	printf("\n");
}

hash calc_dhash(int e, int a, int b) {
	if (a > b) return 0;
	return p[e][b+1] - p[e][a] * power[b - a + 1];
}

bool equivalent(int a, int b, int c, int d){
	if(b-a != d-c) return false;
	if(calc_dhash(0, a, b) == calc_dhash(1, c, d)){
		return true;
	}
	if((b-a+1)%2 == 0){
		int half = (b-a+1)/2;
		return ((equivalent(a, a+half-1, c, c+half-1) & equivalent(a+half, b, c+half, d)) 
		| (equivalent(a, a+half-1, c+half, d) & equivalent(a+half, b, c, c+half-1)));
	}
	return false;
}

int main(){
	scanf(" %s %s ", &str[0][0], &str[1][0]);
	n = 2;
	t[0] = strlen(&str[0][0]);	
	t[1] = strlen(&str[1][0]);
	precalc();
	if(equivalent(0, t[0]-1, 0, t[1]-1)) printf("YES\n");
	else printf("NO\n");
	
}






