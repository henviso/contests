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
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
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
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)

int n, t;
ull a, b, c;
ull v[10000];
char s[10000];
ull p[10000];
int mult[10000];
ull sum[10000];

ull modMult(ull x, ull y){
	if(y == 0ULL) return 0ULL;
	ull fst = x;
	int f = 63; while(f >= 0 && !LCHECK(y, f)) f--; f--;
	for(int k = f; k>=0; k--){
		x = ((x << 1)%c);
		if(LCHECK(y, k)) x = ((x+fst)%c);
	}
	return x%c;
}

int main() {
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d ",&n);
		REP(i, n) scanf(" %llu ", &v[i]);
		scanf(" %llu %llu %llu ", &a, &b, &c);
		scanf(" %s ", &s[0]);
		
		p[0] = 1ULL;
		REP(i, n+10) p[i+1] = modMult(p[i], b);
		
		mult[0] = sum[0] = 0ULL;
		REP(i, n){
			sum[i+1] = sum[i];
			mult[i+1] = mult[i]+(s[i] == 'M');
			if(s[i] == 'R') REP(j, (n-i)/2) swap(v[i+j], v[n-1-j]);
			else if(s[i] == 'A') sum[i+1] = (sum[i+1] + a)%c;
			else sum[i+1] = modMult(sum[i+1], b);
		}
		printf("%llu", (modMult(v[0], p[mult[1]])+sum[1])%c); 
		REPP(i, 1, n) printf(" %llu", (modMult(v[i], p[mult[i+1]])+sum[i+1])%c); printf("\n");
	}
}
