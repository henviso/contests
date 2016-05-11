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
#include <climits>
#include <cfloat>
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

int t, n, m, N;
int x1, a1, b1, c1, r1;
int x2, a2, b2, c2, r2;
int brd[2][1000100];

ll solve(){
	ll ans = n*m;
	set<int> s[2];
	map< int, int > f[2];
	REP(j, n) cout << brd[0][j] << " "; cout << endl;
	REP(j, m) cout << brd[1][j] << " ";
	cout << endl;
	REP(j, N){
		bool minus = false;
		cout << " J EH" << j << endl;
		if(j < n){
			int x = brd[0][j];
			if(!s[0].count(x)){
				if(f[0].count(x)){  //ERA UM  ELEMENTO QUE ESTAVA FALTANDO
					int p = f[0][x];
					f[0].erase(x);
					if(f[0].empty()){
						ans -= p;
						ans += (n-j);
						cout << " SUB " << p << " E SOM " << (n-j) << endl;
					}
				}
				s[0].insert(x);
				if(!s[1].count(x)){
					f[1][x] = j;
					cout << " COLOCANDO O " << x << " NO FALTA DO 1 NA POS " << j << endl;
				}
				if(!f[1].empty()){
					ans -= m;
					minus = true;
					cout << " TIRANDO " << m << endl;
				}
			}
		}
		//cout << " I EH " << j << " S1 EL " << x << " ANS EH " << ans << endl;
		if(j<m){
			int z = brd[1][j];
			cout << "TIREI EL " << z << endl;
			if(!s[1].count(z)){
				if(f[1].count(z)){  //ERA UM  ELEMENTO QUE ESTAVA FALTANDO
					int p = f[1][z];
					f[1].erase(z);
					if(f[1].empty()){
						ans -= p;
						cout << " SUB " << p << " E SOM " << (m-j) << endl;
						ans += (m-j);
					}
				}
				s[1].insert(z);
				if(!s[0].count(z)) f[0][z] = j;
				if(!f[0].empty()){
					ans -= (minus)? n-1 : n;
					int zxc = (minus)? n-1 : n;
					cout << " TIRANDO " << zxc << endl;
				}
			}
		}
		//cout << " I EH " << j << " S2 EL " << z << " ANS EH " << ans << endl;
	}
	return ans;
}

int main(){
	scanf(" %d ", &t);
	REP(ca, t){
		scanf(" %d %d ", &n, &m);
		scanf(" %d %d %d %d %d ", &x1, &a1, &b1, &c1, &r1);
		scanf(" %d %d %d %d %d ", &x2, &a2, &b2, &c2, &r2);
		brd[0][1] = x1;
		brd[0][2] = x2;
		N = max(m,n);
		REPP(j, 1, N){
			if(j<n) brd[0][j] = (a1 * brd[0][(j-1) % n] + b1 * brd[1][(j-1) % m] + c1) % r1;
			if(j<m) brd[1][j] = (a2 * brd[0][(j-1) % n] + b2 * brd[1][(j-1) % m] + c2) % r2;
		}
		cout << "Case#" << ca+1 << ": " <<solve() << endl;
	}
}

