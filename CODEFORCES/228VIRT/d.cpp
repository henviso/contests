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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
//scanf(" %d ", &t);

int out[510][1100];
int in[510][1100];
int gin[510], gout[510];
int mat[510][510];
int n, m;

int main(){
	CLEAR0(gin);
	CLEAR0(gout);
	CLEAR0(mat);
	scanf(" %d %d ", &n, &m);
	int u, v;
	REP(i, m){
		scanf(" %d %d ", &u, &v);
		out[u][gout[u]++] = v;
		in[v][gin[v]++] = u;
		mat[u][v] = 1;
	}
	int ans = INF;
	REPP(c, 1, n+1){
		int tans = 0;
		int deg = (mat[c][c]) ? (gin[c]+gout[c]-1) : gin[c]+gout[c];
		tans += (2*(n-1) + 1 - deg);
		//cout << " CENTRO " << c << " PRECISA DE " << tans << endl;
		int rem = 0;
		REPP(w, 1, n+1){
			if(w == c) continue;
			int outd = (mat[w][c]) ? gout[w]-1 : gout[w];
			int ind = (mat[c][w]) ? gin[w]-1 : gin[w];
			rem += abs(ind-1)+abs(outd-1);
			//cout << " PRA AJUSTAR " << w << " EH "  << tans << endl;
		}
		tans += rem/2;
		ans = min(tans, ans);
	}
	printf("%d\n", ans);
	//cout << " NR PRIMOS " << primes.size() << " " << primes[primes.size()-1] << endl;
}
