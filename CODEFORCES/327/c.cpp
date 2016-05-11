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
#define EPS 1e-10
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

int n;
int a[500100];

int main(){
	cin >> n;
	REP(i, n) cin >> a[i];
	
	int ls = 0;
	int ac = 1;
	int l = 0, r;
	REPP(i, 1, n){
		if(a[i] != a[i-1]){
			ac++;
			ls = max(ac, ls);
		}
		else{
			r = i-1;
			if(ac > 2){
				l++;
				r--;
				while(r >= l){
					a[l] = a[l-1];
					a[r] = a[r+1];
					l++; r--;
				}
			}
			l = i;
			ac = 1;
		}
	}
	if(ac > 2){
		r = n-1;
		l++;
		r--;
		while(r >= l){
			a[l] = a[l-1];
			a[r] = a[r+1];
			l++; r--;
		}
	}
	if(ls > 2){
		if(ls%2) cout << ls/2 << endl;
		else cout << (ls-1)/2 << endl;
	}
	else cout << 0 << endl;
	cout << a[0];
	REPP(i, 1, n) cout << " " << a[i];
	cout << endl; 
	
}
