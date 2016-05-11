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
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
int a[1100][1100];
int b[1100];

int main(){
	scanf(" %d ", &n);
	REP(i, n) REP(j, n) scanf(" %d ", &a[i][j]);
	if(n == 2) cout << "1 1\n";
	else{
		REP(i, n){
			int c = 0, d = 0;
			if(i == 0){		c = i+1; d = i+2; }
			else if(i == n-1){	c = i-1; d = i-2; }
			else{	c = i+1;	d = i-1;}
			b[i] = (a[i][c] - a[c][d] + a[i][d])/2; 
		}
		cout << b[0];
		REPP(i, 1, n) cout << " " << b[i];
		cout << endl;
	}
}
