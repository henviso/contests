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
#define M 1000000007LL

using namespace std;

class SimilarNames2 {
	public:
	int g[60][60];
	int grau[60];
	int n;
	int lim;
	
	long long f[100];
	long long ans;
	long long a[60][60];
	
	void calc_fact(){
		f[0] = f[1] = 1;
		REPP(i, 2, 100) f[i] = (f[i-1]*i)%M;
	}
	
	void dfs(int v, int l){
		cout << " ESTOU NO VERT " << v << endl;
		if(l >= lim){
			ans += f[n-(l+1)];
			ans = ans%M;
			cout << " ANS EH " << ans << endl;
			return;
		}
		REP(j, grau[v]){
			cout << " INDO PARA " << g[v][j] << "\n";
			dfs(g[v][j], l+1);
		}
	}
	
	bool isPrefOf(string a, string b){
		REP(i, a.length()){
			if(a[i] != b[i]) return false;
		}
		return true;
	}
	
	int count(vector <string> names, int L) {
		calc_fact();
		n = names.size();
		lim = max(0, L-1);
		CLEAR0(grau);
		REP(i, n){
			REP(j, n){
				if(isPrefOf(names[i], names[j])){
					g[i][grau[i]++] = j;
				}
			}
		}
		ans = 0;
		REP(i, n) dfs(i, 0);
		int res = ((int) (ans%M));
		return res;
	}
};
