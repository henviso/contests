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

char str[100100];
int t, q;
int ac[3][100100];

int qnt(char c, int l, int r){
	int i = (c-'x');
	return (ac[i][r] - ac[i][l-1]);
}

int main(){
	cin.getline(str, 100100);
	t = strlen(str);
	scanf(" %d ", &q);
	
	ac[0][0] = ac[1][0] = ac[2][0] = 0;
	REP(j, t){
		REP(i, 3) ac[i][j+1] = ac[i][j];
		ac[(str[j]-'x')][j+1]++;
	}
	REP(i, q){
		int l, r;
		scanf(" %d %d ", &l, &r);
		int tam = (r-l)+1;
		bool ans = true;
		if(tam >= 3){
			int f = tam/3;
			int eq = tam%3;
			int x = qnt('x', l, r);
			int y = qnt('y', l, r);
			int z = qnt('z', l, r);
			if(x < f || y < f || z < f) ans = false; 
			if(x == f+1) eq--;
			if(y == f+1) eq--;
			if(z == f+1) eq--;
			if(eq != 0) ans = false;
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
}
