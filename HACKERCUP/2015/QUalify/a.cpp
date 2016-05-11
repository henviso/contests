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

int t;
string n, lo, hi;

int main(){
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		cin >> n;
		lo = hi = n;
		int j;
		REP(i, hi.length()){
			int bst = i;
			for(j = i+1; j<hi.length(); j++){
				if(i == 0 && hi[j] == '0') continue;
				if(hi[j] >= hi[bst]) bst = j;
			}
			if(hi[bst] > hi[i]){
				swap(hi[i], hi[bst]);
				break;
			}
		}
		REP(i, lo.length()){
			int bst = i;
			for(j = i+1; j<lo.length(); j++){
				if(i == 0 && lo[j] == '0') continue;
				if(lo[j] <= lo[bst]) bst = j;
			}
			if(lo[bst] < lo[i]){
				swap(lo[i], lo[bst]);
				break;
			}
		}
		cout << "Case #" << ca << ": " << lo << " " << hi << endl;
	}
}
