#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>

#define ALL(x) (x).begin(),x.end()
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)

#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
#define MOD 100000007LL
 
using namespace std;

class WinterAndSnowmen {
	public:
	
	int n, m;
	
	long long dp[2048][2048];
	
	int getNumber(int N, int M) {
		n = N; m = M;
		CLEAR0(dp);
		int mn = max(n, m);
		
		int ind[2048];
		int p = 1, lim = (1 << mn);
		REP(i, 12){ ind[p] = i+1; p *= 2; }
		
		dp[0][0] = 1LL;
		
		REPP(i, 1, mn+1){
			int f = 12 - ind[CHECKFIRST(i)]; 
			REPP(j, 1, lim){
				int d = ind[CHECKFIRST(j)];
				if(f < d){
					if(i <= n) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
					if(i <= m) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
				}
				else if(f >= d){
					int rem = (i >> (d-1));
					int x = (j << 1);
					int y = ((j << 1) | 1);
					if(i <= n && (x^rem) < y){
						int nj  = j << (ind[CHECKFIRST((x^rem)^y)]-1);
						dp[i][nj] = (dp[i][nj] + dp[i-1][j])%MOD;
					}
					if(i <= m && x < (y^rem)){
						int nj  = j << (ind[CHECKFIRST((x^rem)^y)]-1);
						dp[i][nj] = (dp[i][nj] + dp[i-1][j])%MOD;
					} 
				}
			}
		}
		long long ans = 0;
		REP(i, 2001) REPP(j, i+1, 2001) ans = (ans+dp[i][j])%1000000007LL; 
		return ans;
	}
};


int main(){
	
	
	
}

// Powered by FileEdit
