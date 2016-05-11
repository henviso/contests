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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n;
int gp, gc, gf;
int p[100], c[100], f[100];

int main(){
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		scanf(" %d %d %d", &gp, &gc, &gf);
		scanf(" %d ", &n);
		REP(i, n) scanf(" %d %d %d", &p[i], &c[i], &f[i]);
		bool pos = false;
		int x = (1 << n);
		REP(msk, x){
			int qp, qc, qf;	qp = qc = qf = 0;
			REP(k, n) if(msk&(1<<k)){
				qp += p[k]; 
				qc += c[k]; 
				qf += f[k]; 
			}
			if(qp == gp && qc == gc && qf == gf){ pos = true; break; }
		}
		cout << "Case #" << ca << ": ";
		if(pos) cout << "yes\n";
		else cout << "no\n";	
	}
}
