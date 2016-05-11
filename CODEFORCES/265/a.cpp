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

int n, p;
string s;

int main(){
	cin >> n >> p;
	cin >> s;
	int i;
	for(i = n-1; i>=0; i--){
		int k;
		for(k = (s[i] - 'a')+1; k < p; k++){
			char c = 'a'+k;
			if(i - 1 >= 0 && c == s[i-1]) continue;
			if(i - 2 >= 0 && c == s[i-2]) continue;
			s[i] = c;
			i++;
			break;
		}
		if(k < p) break;
	}
	if(i == -1){
		cout << "NO\n";
	}
	else{
		while(i < n){
			int k;
			for(k = 0; k<p; k++){
				char c = 'a'+k;
				if(i - 1 >= 0 && c == s[i-1]) continue;
				if(i - 2 >= 0 && c == s[i-2]) continue;
				s[i] = c;
				break;
			}
			if(k == p) break;
			i++;
		}
		if(i == n) cout << s << endl;
		else cout << "NO\n";
	}
	
}
