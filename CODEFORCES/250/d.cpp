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

int n, m;
char s[500][500];
int a[500][500];

int sh[500][500];
int sv[500][500];
int sdp[500][500];
int sds[500][500];

int main(){
	scanf(" %d %d ", &n, &m);
	REP(i, n) scanf(" %s ", &s[i][0]);
	
	CLEAR0(sh);
	CLEAR0(sv);
	CLEAR0(sdp);
	CLEAR0(sds);
	REPP(i, 1, n+1){
		REPP(j, 1, m+1){
			a[i][j] = (s[i-1][j-1] == '1');
			sh[i][j] = a[i][j] + sh[i][j-1];
			sv[i][j] = a[i][j] + sv[i-1][j];
			sdp[i][j] = a[i][j] + sdp[i-1][j-1];
			//cout << " sh[" << i << "][" << j << "] " << sh[i][j] << endl;
				
		}
		for(int j = m; j>0; j--) sds[i][j] = a[i][j] + sds[i-1][j+1];
	}
	
	ll ans = 0LL;
	
	int mk = min(n, m);
	REPP(k, 1, mk){
		REPP(i, 1, n+1){
			REPP(j, 1, m+1-k){
				int Sh = sh[i][j+k]-sh[i][j-1];
				
				//cout << " COUT " << i << " " << j << " e " << i << " " << j+k << " SH " << Sh << endl;
				//cout << i << " " << j << " " << k << endl;
				if(Sh > 0) continue;
				
				int Sv, Sd;
				if(i-k > 0){
					Sv = sv[i][j]-sv[i-k-1][j];
					Sd = sdp[i][j+k] - sdp[i-k-1][j-1];
					//cout << "Sv " << Sv << " " << Sd << endl;
					if(Sv || Sd);
					else{
						//cout << "TRIANGULO EQ A EM(" << i << "," << j << ") e (" << i << "," << j+k << ")" << endl;
						ans++;
					}
					
					Sv = sv[i][j+k] - sv[i-k-1][j+k];
					Sd = sds[i][j] - sds[i-k-1][j+k+1];
					//cout << "Sv " << Sv << " " << Sd << endl;
					if(Sv || Sd);
					else{
						//cout << "TRIANGULO EQ B EM(" << i << "," << j << ") e (" << i << "," << j+k << ")" << endl;
						ans++;
					}
				}
				if(i+k <= n){
					Sv = sv[i+k][j] - sv[i-1][j];
					Sd = sds[i+k][j] - sds[i-1][j+k+1];
					//cout << "Sv " << Sv << " " << Sd << endl;
					if(Sv || Sd);
					else{
						//cout << "TRIANGULO EQ C EM(" << i << "," << j << ") e (" << i << "," << j+k << ")" << endl;
						ans++;
					}
					
					Sv = sv[i+k][j+k]-sv[i-1][j+k];
					Sd = sdp[i+k][j+k] - sdp[i-1][j-1];
					if(Sv || Sd);
					else{
						//cout << "TRIANGULO EQ D EM(" << i << "," << j << ") e (" << i << "," << j+k << ")" << endl;
						ans++;
					}
				}
			}
		}
	}
	
	for(int k = 2; k<m; k += 2){ //isosceles com base horizontal
		REPP(i, 1, n+1){
			REPP(j, 1, m+1-k){
				//cout << i << " " << j << endl;
				
				int Sh = sh[i][j+k]-sh[i][j-1], Sp, Ss;
				if(Sh > 0) continue;
		
				if(i-k/2 > 0){
					Sp = sdp[i][j+k] - sdp[i-k/2-1][j+k/2-1];
					Ss = sds[i][j] - sds[i-k/2-1][j+k/2+1];
					if(Sp || Ss);
					else{
						//cout << "TRIANGULO DIVIDIDO CIMA EM (" << i << "," << j << ") e (" << i << "," << j+k << ")" << endl;
						ans++;
					}
				}
				
				if(i+k/2 <= n){
					Sp = sdp[i+k/2][j+k/2] - sdp[i-1][j-1];
					Ss = sds[i+k/2][j+k/2] - sds[i-1][j+k+1];
					if(Sp || Ss);
					else{
						ans++;
						//cout << "TRIANGULO DIVIDIDO BAIXO EM (" << i << "," << j << ") e (" << i << "," << j+k << ")" << endl;
					}
				}
			}
		}
	}
					
	for(int k = 2; k<n; k += 2){  //isosceles com base vertical
		REPP(i, 1, n+1-k){
			REPP(j, 1, m+1){
				//cout << i << " " << j << endl;
				int Sv = sv[i+k][j] - sv[i-1][j], Sp, Ss;
				if(Sv > 0) continue;
				
				if(j+k/2 <= m){
					Sp = sdp[i+k/2][j+k/2] - sdp[i-1][j-1];
					Ss = sds[i+k][j] - sds[i+k/2-1][j+k/2+1];
					if(Sp || Ss);
					else{
						ans++;
						//cout << "TRIANGULO DIVIDIDO PRA DIREITA EM (" << i << "," << j << ") e (" << i+k << "," << j << ")" << endl;
					}
				}
				
				if(j-k/2 > 0){	
					Ss = sds[i+k/2][j-k/2] - sds[i-1][j+1];
					Sp = sdp[i+k][j] - sdp[i+k/2-1][j-k/2-1];
					if(Sp || Ss);
					else{
						ans++;
						//cout << "TRIANGULO DIVIDIDO PRA ESQUERDA EM (" << i << "," << j << ") e (" << i+k << "," << j << ")" << endl;
					}
				}
			}
		}
	}
	cout << ans << endl;
	
			
}

