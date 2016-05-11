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
#define INF 196

using namespace std;

class PalindromeMatrix {
	public:
	
	int pd[50][50];
	int midRow, col, cc, rc, res;
	int N, M;
	vector<string> vs;
	
	int subMatrix(vector <string> s, int row){
		int ans = 0, n = s.size(), m = s[0].length();
		bool vis[n][m]; CLEAR0(vis);
		REP(i, n){
			REP(j, m){
				if(vis[i][j]) continue;
				int cnt[2]; CLEAR0(cnt);
				cnt[(s[i][j]-'0')]++; vis[i][j] = true;
				if(row & (1 << i)){
					if(!vis[i][m-1-j]){	cnt[(s[i][m-j-1]-'0')]++; vis[i][m-1-j] = true; }
					if(col & (1 << (m-j-1))){
						if(!vis[n-i-1][m-j-1]){ cnt[(s[n-i-1][m-j-1]-'0')]++; vis[n-i-1][m-j-1] = true; }
						if(row & (1 << (n-1-i))){
							if(!vis[n-1-i][j]){ cnt[(s[n-i-1][j]-'0')]++; vis[n-i-1][j] = true; }
						}
					}
				}
				if(col & (1 << j)){
					if(!vis[n-i-1][j]){ cnt[(s[n-i-1][j]-'0')]++; vis[n-i-1][j] = true; }
					if(row & (1 << (n-1-i))){
						if(!vis[n-1-i][m-1-j]){ cnt[(s[n-i-1][m-j-1]-'0')]++; vis[n-i-1][m-j-1] = true; }
						if(col & (1 << (m-j-1))){
							if(!vis[i][m-j-1]){ cnt[(s[i][m-j-1]-'0')]++; vis[i][m-j-1] = true; }
						}
					}
				}
				//cout << " I " << i << " J " << j << " 0 EH " << cnt[0] << " 1 EH " << cnt[1] << endl;
				ans += min(cnt[0], cnt[1]);	
			}
		}
		//cout << " STRINGS " << s[0] << " E " << s[1] << " row " << row << " COL " << col << " ANS " << ans << endl;
		return ans;		
	}
	
	int cost(int i, int k){
		vector<string> v;
		v.push_back(vs[i]);
		v.push_back(vs[vs.size() - i - 1]);
		if(k == 0) return subMatrix(v, 0);
		if(k == 1) return min(subMatrix(v, 1), subMatrix(v, 2));
		return subMatrix(v, 3);
	}
	
	int solve(int i, int r){
		int ans = pd[i][r];
		//cout << " CHAMANDO SOLVE " << i << " " << r << "ANS EH " << ans << endl;
		if(ans == -1){
			ans = INF;
			//cout << " I EH " << i << " MIDROW EH " << midRow << endl;
			if(i == midRow){
				if(r == 0) return 0;
				return INF;
			}
			else{
				ans = min(ans, solve(i+1, r)+cost(i, 0));
				if(r-1 >= 0) ans = min(ans, solve(i+1, r-1)+cost(i, 1));
				if(r-2 >= 0) ans = min(ans, solve(i+1, r-2)+cost(i, 2));
			}
			pd[i][r] = ans;
		}
		//cout << "SOLVE " << i << " " << r << " EH " << ans << " RES EH " << res << endl;;
		return ans;
	}
	
	void bt(int c, int f){
		
		if(c == cc){
			REP(i, N/2+1) REP(j, N+1) pd[i][j] = -1;
			res = min(res, solve(0, rc));
			//cout << " COL " << col << " RES EH " << res << endl;
			return;
		}
		REPP(i, f, M){
			if(!(col & (1 << i))){
				col |= (1 << i);
				bt(c+1, i+1);
				col &= ~(1 << i); 
			}
		}
		return;
	}
	
	int minChange(vector <string> A, int rowCount, int columnCount) {
		N = A.size(), M = A[0].length();
		vs = A;
		cc = columnCount; rc = rowCount; midRow = N/2 + N%2;
		res = INF;
		col = 0;
		bt(0, 0);
		
		return res;
	}
};


// Powered by FileEdit


// Powered by FileEdit
