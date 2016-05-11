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
#define EPS 1e-9
//__builtin_popcount(m)
//scanf(" %d ", &t);
//L[i]=L[i/2]+1;

int n;
int a[1000000];
int r[1000000];
int l[1000000];


int main(){
	cin >> n;
	int bst = -INF;
	REPP(i, 1, n+1){
		cin >> a[i];
		bst = max(bst, a[i]);
	}
	l[0] = -INF;
	r[n+1] = -INF;
	for(int i = n; i>=0; i--) r[i] = max(r[i+1], a[i]);
	REPP(i, 1, n+1) l[i] = max(l[i-1], a[i]);
	int start = 1, act = 0, mn = INF;
	REPP(i, 1, n+1){
		if(act+a[i] < 0){
			act = 0;
			start = i+1;
		}
		else{
			act += a[i];
			mn = min(mn, a[i]);
			int w = act;
			int trade = max(r[i+1], l[start-1]);
			if(trade > -INF){
				if(mn < 0) act += mn + trade; 
				else if(trade > mn) act += trade-mn;
			}
			bst = max(bst, w);
		}
	}
	cout << bst << endl;	
}
