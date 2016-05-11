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

int n;
vector< ii > a;

int main(){
	cin >> n;
	int cnt[2100]; CLEAR0(cnt);
	int eq = 0;
	a.resize(n);
	REP(i, n){
		a[i].second = i+1;
		cin >> a[i].first;
		cnt[a[i].first]++;
		if(cnt[a[i].first] > 1) eq++;
	}
	sort(a.rbegin(), a.rend());
	if(eq <= 1) cout << "NO\n";
	else{
		cout << "YES\n";
		cout << a[n-1].second;
		REPD(i, n-1) cout << " " << a[i].second; 
		cout << endl;
		REP(i, n) REPP(j, i+1, n) if(a[i].first == a[j].first){ swap(a[i], a[j]); break; }
		cout << a[n-1].second;
		REPD(i, n-1) cout << " " << a[i].second; 
		cout << endl;
		int aux = 0;
		REP(i, n) REPP(j, i+1, n){
			if(a[i].first == a[j].first){
				aux++;
				if(aux == 1){
					swap(a[i], a[j]);
					break;
				}
			}
		}
		cout << a[n-1].second;
		REPD(i, n-1) cout << " " << a[i].second; 
		cout << endl;
	}

}
