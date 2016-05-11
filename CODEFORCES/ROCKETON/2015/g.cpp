#include <iostream>
#include <cstdio>
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
#include <iomanip>
#include <cstring>
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
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-11
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, k;
int a[35];
double p[35][35][210];
double P;

double solve(){
	REP(i, n)
	REP(j, i+1)
	REP(l, k+1) p[i][j][l] = 0.0;
	REP(j, n){
		REP(i, n) 
		if(a[i]>a[j]) p[i][j][0] = 1.0;
		else p[i][j][0] = 0.0;
	}
	REP(z, k){
		REP(j, n)
		REP(i, j+1){
			int mid = (j+i)/2;
			REP(J, n){
				int y = J;
				if(y >= i && y <= j) y = ((j-i+1)%2) ? 2*mid-y : 2*mid-y+1;
				REP(I, n){
					int x = I;
					if(x >= i && x <= j) x = ((j-i+1)%2) ? 2*mid-x : 2*mid-x+1;
					p[I][J][z+1] += P*p[x][y][z];
				}
			}
		}
	}
	double ans = 0.0;
	REP(j, n)
	REP(i, j){
		//cout << i << " " << j << " p: " << p[i][j][k] << endl;
		ans += p[i][j][k];
	}
	return ans;
}

int main(){
	cin >> n >> k;
	REP(i, n) cin >> a[i];
	P = 2.0/(n*(n+1));
	printf("%.15lf\n", solve());
}
