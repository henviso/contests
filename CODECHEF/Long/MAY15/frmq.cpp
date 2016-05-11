#include <iostream>
#include <cstdio>
#include <vector>

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
int pd[20][100100];
int lg[100100];
int chunk;
ll ans = 0;

void precmp(){
	REPP(i, 1, n+1) pd[0][i] = a[i];
	lg[1] = 0;
	int z = 2, j = 1;
	for(j = 1; (1 << j) <= n; j++){
		while(z < (1 << j)) lg[z++] = j-1;
		int k = (1 << (j-1));
		REPP(i, 1, n+1){
			if(i+k <= n) pd[j][i] = max(pd[j-1][i], pd[j-1][i+k]);
			//cout << "PD[" << i << "][" << j << "] : " << pd[i][j] << " ";
		}
	}
	while(z <= n) lg[z++] = j-1;
}

void rmq(int a, int b){
	if(a > b) swap(a, b);
	chunk = lg[b-a+1];
	ans += max(pd[chunk][a], pd[chunk][b-(1<<chunk)+1]);
}

int main(){
	scanf(" %d ", &n);
	REPP(i, 1, n+1) scanf(" %d ", &a[i]);
	scanf(" %d %d %d ", &m, &x, &y);
	precmp();
	rmq(x+1, y+1);
	//cout << x+1 << " " << y+1 << " : " << rmq(x+1, y+1) << endl;
	
	REPP(i, 1, m){
		x += 7;
		while(x >= n-1) x -= n-1;
		y += 11;
		while(y >= n) y -= n;
		rmq(x+1, y+1);
		//cout << x+1 << " " << y+1 << " : " << rmq(x+1, y+1) << endl;
	}
	printf("%lld\n", ans);
}
