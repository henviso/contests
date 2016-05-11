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

int t, n;
double p;
char a[50][50][50];
char b[50][50][50];
char sa[125000];
char sb[125000];
int s[50][50][50];
int cube[100];
int si[100];

int sum(int r1, int c1, int d1, int r2, int c2, int d2){
	return (s[r2][c2][d2] - s[r1-1][c2][d2] - s[r2][c1-1][d2] + s[r1-1][c1-1][d2] + s[r2][c1-1][d1-1] - s[r2][c2][d1-1]  + s[r1-1][c2][d1-1] - s[r1-1][c1-1][d1-1]);
}

int getCnt(int l){
	int ans = 0;
	for(int i = 1; i+l <= n; i++){
		for(int j = 1; j+l <= n; j++){
			for(int k = 1; k+l <= n; k++){
				int soma = sum(i, j, k, i+l, j+l, k+l);
				
				//cout << " SIM EM " << i << " " << j << " " << k << " DE TAM " << l+1 << " EH " << si << " SOMA EH " << soma << endl;
				if(soma >= si[l+1]){
					ans++;
				}
			}
		}
	}
	return ans;
}

int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d %lf ", &n, &p); p/=100;
		cin.getline(sa, 125000);
		cin.getline(sb, 125000);
		int pos = 0;
		REPP(i, 1, n+1) REPP(j, 1, n+1) REPP(k, 1, n+1){
			a[i][j][k] = sa[pos++];
		}
		pos = 0;
		REPP(i, 1, n+1) REPP(j, 1, n+1) REPP(k, 1, n+1){
			b[i][j][k] = sb[pos++];
		}
		
		REP(i, 50){
			cube[i] = i*i*i;
			si[i] = (int) (ceil(((double) cube[i])*p));
		}
		
		CLEAR0(s);
		bool oneEq = (p < EPS);
		REPP(i, 1, n+1) REPP(j, 1, n+1) REPP(k, 1, n+1){
			s[i][j][k] = (a[i][j][k] == b[i][j][k]) + s[i-1][j][k] + s[i][j-1][k] + s[i][j][k-1] - s[i-1][j-1][k] - s[i][j-1][k-1] - s[i-1][j][k-1] + s[i-1][j-1][k-1];
			//cout << "s[" << i << "][" << j << "][" << k << "]: " << s[i][j][k] << endl;
			oneEq |= (a[i][j][k] == b[i][j][k]);
		}
		
		int ans = 0;
		int tam = -1;
		if(oneEq){
			for(int i = n-1; i>=0; i--){
				ans = getCnt(i);
				if(ans){
					tam = i+1;
					break;
				}
			} 
		}
		
		//cout << " SOMA TOTAL EH " << sum(1, 1, 1, n, n, n) << endl;
		if(tam != -1) printf("%d %d\n", tam, ans);
		else printf("-1\n");
	}

}
