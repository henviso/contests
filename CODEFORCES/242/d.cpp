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

int n, m, k;
int p, u, d;
int h[500][500];

int AR[500][500];
int AL[500][500];
int AU[500][500];
int AD[500][500];

int cost(int r1, int c1, int r2, int c2){
	if(h[r1][c1] > h[r2][c2]) return d;
	else if(h[r1][c1] < h[r2][c2]) return u;
	else return p;
}

int main(){
	cin >> n >> m >> k;
	cin >> p >> u >> d;
	REPP(i, 1, n+1)
	REPP(j, 1, m+1) cin >> h[i][j];
	
	
	CLEAR0(AR); CLEAR0(AL); CLEAR0(AU); CLEAR0(AD);
	REPP(i, 1, n+1){
		REPP(j, 2, m+1) AR[i][j] = AR[i][j-1] + cost(i, j-1, i, j);
		for(int j = m-1; j>=1; j--) AL[i][j] = AL[i][j+1] + cost(i, j+1, i, j);
	}
	REPP(i, 2, n+1) REPP(j, 1, m+1) AD[i][j] = AD[i-1][j] + cost(i-1, j, i, j);
	for(int i = n-1; i>=1; i--) REPP(j, 1, m+1) AU[i][j] = AU[i+1][j] + cost(i+1, j, i, j);
	
	int ans = INF;
	int p1r, p1c, p2r, p2c;
	
	REPP(r1, 1, n+1){
		REPP(r2, r1+2, n+1){
			set< ii > a;	
			REPP(c, 1, m+1){
				 int blue = AR[r1][c] - AR[r1][1] + AD[r2][c] - AD[r1][c] + AL[r2][1] - AL[r2][c];
				 int red = AR[r1][c] - AR[r1][1] + AL[r2][1] - AL[r2][c];
				 int yellow = AU[r1][c] - AU[r2][c];
				 
				 //cout << " r1 " << r1 << " r2 " << r2 << " c " << c << " blue : " << blue << endl;
				 //cout << " r1 " << r1 << " r2 " << r2 << " c " << c << " yellow : " << yellow << endl;
				 //cout << " r1 " << r1 << " r2 " << r2 << " c " << c << " red : " << red << endl;
				 //cout << " ans " << ans << endl;
				 
				 int t = k-blue;
				 
				 //cout << " T EH " << k << " " << -t << endl;
				 
				 set< ii >::iterator it, it2 = a.lower_bound(mp(t, -INF));
				 it = it2;
				 while(it != a.end() && abs(it->second-c) < 2) it++;
				 if(it != a.end()){
					 //cout << " ACHEI " << it->first << " NA COLUNA " << it->second << " SOMA FICA " << (blue + it->first) << endl;
					 if(ans > abs(k - (blue + it->first))){
						 ans = abs(k - (blue + it->first));
						 p1r = r1;
						 p2r = r2;
						 p1c = it->second;
						 p2c = c;
					 }
				}
				 
				 it = it2;
				 if(it != a.begin()){
					 it--;
					 while(abs(it->second-c) < 2){
						 if(it == a.begin()) break;
						 it--;
					}
					if(it != a.begin()){
						 //cout << " ACHEI " << it->first << " NA COLUNA " << it->second << " SOMA FICA " << (blue + it->first) << endl;
						 if(ans > abs(k - (blue + it->first))){
							 ans = abs(k - (blue + it->first));
							 p1r = r1;
							 p2r = r2;
							 p1c = it->second;
							 p2c = c;
						 }
					}
				}
				
				a.insert(mp(yellow-red, c));
				 
			}
		}
	}	
	
	//cout << " ANS " << ans << endl;
	cout << p1r << " " << p1c << " " << p2r << " " << p2c << endl;	
}



