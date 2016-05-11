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
//__builtin_popcount(m)
//scanf(" %d ", &t);

typedef long long unsigned hash;

#define MAXS 3
#define MAXN 300100
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXS][MAXN];
char str[MAXS][MAXN];
int t[MAXS], n;

void cmp(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
}

void precalc(){
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

int main(){
	int tc;
	scanf(" %d ", &tc);
	cmp();
	while(tc--){
		scanf(" %s ", &str[0][0]);
		strcpy(&str[1][0], "101");
		strcpy(&str[2][0], "010");
		n = 3;
		t[0] = strlen(&str[0][0]);
		t[1] = strlen(&str[1][0]);
		t[2] = strlen(&str[2][0]);
		precalc();
		hash a = calc_dhash(1, 0, t[1]-1);
		hash b = calc_dhash(2, 0, t[2]-1);
		
		bool good = false;
		REP(i, t[0]-2){
			hash c = calc_dhash(0, i, i+2);
			if(c == a || c == b){
				good = true; 
				break;
			}
		}
		if(good) printf("Good\n");
		else printf("Bad\n");
	}	
}
