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
//ios::sync_with_stdio(false);

string a, b;

int LCPA[5100], LCPB[5100];
int lcpa[5100][5100];
int lcpb[5100][5100];
int lcp[5100][5100];

int main(){
	cin >> a >> b;
	CLEAR0(lcpa);
	CLEAR0(lcpb);
	CLEAR0(LCPA);
	CLEAR0(LCPB);
	for(int l = a.length()-2; l>=0; l--){
		for(int r = a.length()-1; r>l; r--){
			lcpa[l][r] = (a[l] == a[r])? 1 + lcpa[l+1][r+1] : 0;
			LCPA[l] = max(lcpa[l][r], LCPA[l]);
			LCPA[r] = max(lcpa[l][r], LCPA[r]);
		}
	}
	for(int l = b.length()-2; l>=0; l--){
		for(int r = b.length()-1; r>l; r--){
			lcpb[l][r] = (b[l] == b[r])?  1 + lcpb[l+1][r+1] : 0;
			
			LCPB[l] = max(lcpb[l][r], LCPB[l]);
			LCPB[r] = max(lcpb[l][r], LCPB[r]);
		}
	}
	for(int l = a.length()-1; l>=0; l--){
		for(int r = b.length()-1; r>=0; r--) lcp[l][r] = (a[l] == b[r])? 1 + lcp[l+1][r+1] : 0;
	}
	int ans = INF; 
	REP(i, a.length()){
		REP(j, b.length()){
			int tam = max(LCPA[i], LCPB[j])+1;
			//cout << " i " << i << " j " << j << " TAM " << tam << endl;
			if(i+tam-1 < a.length() && j+tam-1 < b.length() && lcp[i][j] >= tam) ans = min(tam, ans);
		}
	}
	if(ans == INF) cout << "-1\n";
	else cout << ans << endl;
}
