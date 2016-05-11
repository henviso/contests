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

string a, b;
int cnt[300];
int cnt2[300];

int main(){
	CLEAR0(cnt);
	CLEAR0(cnt2);
    cin >> a >> b;
	int y = 0, w = 0;
	REP(i, a.length()) cnt[a[i]]++;
	REP(i, b.length()) cnt2[b[i]]++;
	REP(i, 300){
		if(cnt[i] > 0){
			int x = min(cnt[i], cnt2[i]);
			cnt[i] -= x;
			cnt2[i] -= x;
			y += x;
		}
	}
	REP(i, 300){
		if(isalpha(i)){
			if(islower(i)){
				int j = toupper(i);
				int x = min(cnt[i], cnt2[j]);
				cnt[i] -= x;
				cnt2[j] -= x;
				w += x;
			}
			else{
				int j = tolower(i);
				int x = min(cnt[i], cnt2[j]);
				cnt[i] -= x;
				cnt2[j] -= x;
				w += x;
			}
		}
	}
	cout << y << " " << w << endl;
}
