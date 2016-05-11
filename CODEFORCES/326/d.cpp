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
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-5
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);
//L[i]=L[i/2]+1;

double X1, Y1, X2, Y2;
double vmax, ct;
double v[2], w[2];
double na, nb;

bool canGet(double t){
	double ft = min(t, ct);
	double st = max(t-ct, 0.0);
	double x0 = X1 + ft*v[0] + st*w[0];
	double y0 = Y1 + ft*v[1] + st*w[1];
	double vel = hypot(x0-X2, y0-Y2)/t;
	return (vmax > vel);
}

int main(){
	cin >> X1 >> Y1 >> X2 >> Y2;
	cin >> vmax >> ct;
	cin >> v[0] >> v[1];
	cin >> w[0] >> w[1];
	
	double hi = 10e12, lo = 0.0, mid = hi+1, ans = 0.0, lmid = lo-1;
	while(fabs(lmid-mid) > EPS){
		lmid = mid;
		mid = (hi+lo)/2.0;
		//printf("%.13lf %.13lf %.13lf\n", lo, mid, hi); 
		//cout << hi << " " << mid << " " << lo << " hi-lo ---> " << hi-lo << " lo-hi " << lo-hi << " EPS " << EPS << endl;
		if(canGet(mid)){
			//cout << " BLA " << endl;
			ans = mid;
			hi = mid;
		}
		else{
			//cout << " BLU " << endl;
			lo = mid;
		}
	}
	printf("%.12lf\n", ans);
}
