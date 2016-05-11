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
#include <unistd.h>
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
#define MOD 1000003LL
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
#define EPS 10e-20
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, m, x, y;
int a[100100];
int pd[100100][20];

void precmp(){
	CLEAR0(pd);
	REPP(i, 1, n+1) pd[i][0] = a[i];
	for(int j = 1; (1 << j) <= n; j++){
		int k = (1 << (j-1));
		REPP(i, 1, n+1){
			pd[i][j] = max(pd[i][j-1], pd[i+k][j-1]);
			//cout << "PD[" << i << "][" << j << "] : " << pd[i][j] << " ";
		}
	}
}

int rmq(int a, int b){
	if(a > b) swap(a, b);
	int k = floor(log2(b-a+1));
	return max(pd[a][k], pd[b-(1<<k)+1][k]);
}

int main(){
	scanf(" %d ", &n);
	REPP(i, 1, n+1) scanf(" %d ", &a[i]);
	scanf(" %d %d %d ", &m, &x, &y);
	precmp();
	ll ans = rmq(x+1, y+1);
	//cout << x+1 << " " << y+1 << " : " << rmq(x+1, y+1) << endl;
	REPP(i, 1, m){
		x = (x+7)%(n-1);
		y = (y+11)%(n);
		ans += rmq(x+1, y+1);
		//cout << x+1 << " " << y+1 << " : " << rmq(x+1, y+1) << endl;
	}
	printf("%lld\n", ans);
}
