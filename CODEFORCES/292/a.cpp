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
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
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

#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2

int n;
string s;
string ans;

int d[] = {0, 0, 1, 1, 3, 1, 2, 1, 4, 4};
int a[10][5]; 

void precmp(){
	REP(i, 10) REP(j, 5) a[i][j] = 1;
	a[2][0] = 2;
	a[3][0] = a[4][2] = 3;
	a[4][0] = a[4][1] = 2;
	a[5][0] = 5;
	a[6][0] = 5; a[6][1] = 3;
	a[7][0] = 7;
	a[8][0] = a[8][1] = a[8][2] = 2; a[8][3] = 7;
	a[9][0] = 2; a[9][1] = a[9][2] = 3; a[9][3] = 7;
}


void decompose(int x){
	REP(i, d[x]){
		ans.push_back(a[x][i]+'0');
	}
}

int main(){
	cin >> n >> s;
	precmp();
	REP(i, n) decompose(s[i]-'0');
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}
