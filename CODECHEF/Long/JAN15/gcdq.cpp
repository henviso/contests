
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

int t, n, q, a[1000000];
int l[1000000];	
int r[1000000];

int gcd(int a, int b) {
  if(a<0) a = -a;
  if(b<0) b = -b;

  if(b == 0)
    return a;
  else
    return gcd(b, a%b);
}

int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d %d ", &n, &q);
		l[0] = r[n+1] = a[0] = a[n+1] = 0;
		REPP(i, 1, n+1){
			scanf(" %d ", &a[i]);
			l[i] = gcd(l[i-1], a[i]);
		}
		for(int i = n; i>=1; i--) r[i] = gcd(r[i+1], a[i]);
		int L, R;
		REP(i, q){
			scanf(" %d %d ", &L, &R);
			printf("%d\n", gcd(l[L-1], r[R+1]));  
		}
	}
}
