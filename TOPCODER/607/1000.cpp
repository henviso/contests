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
#define INF 1000000

using namespace std;

class CombinationLockDiv2 {
	public:
	
	int pd[60][10][10];
	
	
	int dist(char a, char b){
		int na = a-'0', nb = b-'0';
		return min(abs(na-nb), 5);
	}
	
	int minimumMoves(string S, string T) {
		int n = S.size();
		REP(i, 10) REP(j, 10) pd[0][i][j] = INF;
		pd[0][0][0] = 0;
		
		REPP(i, 1, n+1){
			int mn = INF;
			REP(j, 10)
			REP(k, 10){
				if(pd[i-1][j][k] != INF){
					int up = (T[i-1] - S[i-1])%10;
					int down = ((S[i-1] + 10) - T[i-1])%10;
					up = max(up-j, 0);
					down -= max(down-j, 0);
					pd[i][j][up]
					mn = min(mn, pd[i][j][k]+up); 
					mn = min(mn, pd[i-1][j][k]+down); 
				}
			}
		}
		
	}
};
