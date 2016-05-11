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
#include <iomanip>
#include <utility>   
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector< ii > vii;
typedef vector< ll > vll;
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
#define EPS 10e-16

int t, n, k;
double p;
double pd[9000];
double pt[3100][3100];
double ba[3100][3100];

double binAc(int N, int K){
	if(K > N) return 0.0;
	if(fabs(-1 - ba[N][K]) < EPS) ba[N][K] = pt[N+1][K+1] * pow(p, K) * pow(1.0-p, N-K) + binAc(N, K+1);
	return ba[N][K];
}

double expect(int x){
	if(fabs(-1 - pd[x]) < EPS){
		if(x < k) pd[x] = 0.0;
		else{
			REPP(i, k, x+1){
				double np = binAc(i, k);
				double res = np + expect(x-i);
				//if(np < EPS) break;
				//cout << " NP " << np << endl;
				//cout << np << " " << lp << " " << p << endl;
				if(fabs(res-pd[x]) > EPS && res > pd[x]) pd[x] = res;
				//cout << i << " PD " << pd[x] << endl;
				
				//cout << np-lp << " " << goldenValue << endl;
				//if(fabs(goldenValue-(np-lp)) < EPS || (np-lp) < goldenValue) break;
				//if(np-lp < goldenValue) break;
			}
		}
		//cout << "EXPECT " << x << pd[x] << endl;
	}
	return pd[x];
}

int main(){
	REP(i, 3100) REP(j, 3100){
		pt[i][j] = 0.0;
	}
	pt[0][0] = 1.0;
	REPP(i, 1, 3100)
	REPP(j, 1, i+1) pt[i][j] = pt[i-1][j] + pt[i-1][j-1];
	
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> n >> k >> p;
		
		REP(i, 3100) REP(j, 3100){
			pd[i] = -1.0;
			ba[i][j] = -1.0;
		}
		pd[0] = 0.0;
		
		double ans = expect(n);
		if(ans > 3000.0) ans = 0.0;
		printf("Case #%d: %.10lf\n", tc, ans);
	}
}

