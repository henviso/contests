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
int p[100100];
bitset<100100> vis;
vi cycle[100100];
int nc = 0;

int main(){
	vis.reset(); nc = 0;
	bool star = false;
	bool dstar = false;
	bool oddcycle = false;
	cin >> n;
	REPP(i, 1, n+1) cin >> p[i];
	REPP(i, 1, n+1){
		int x = p[i];
		if(!vis[x]){
			do{
				cycle[nc].push_back(x); vis[x] = true;
				x = p[x];
			} while(x != p[i]);
			if(cycle[nc].size() == 1) star = true;
			else if(cycle[nc].size() == 2) dstar = true;
			else if((cycle[nc].size()%2) == 1) oddcycle = true;
			nc++;
		}
	}
	if(star){
		REP(i, nc){
			if(cycle[i].size() == 1){
				cout << "YES\n";
				int x = cycle[i][0];
				REPP(j, 1, n+1) if(j != x) cout << x << " " << j << endl;
				break;
			}
		}
	}
	else if(dstar){ //todos os ciclos tem tam == 2
		if(oddcycle) cout << "NO\n";
		else{
			cout << "YES\n";
			REP(i, nc){
				if(cycle[i].size() == 2){
					cout << cycle[i][0] << " " << cycle[i][1] << endl;
					REP(j, nc) if(j != i){
						REP(k, cycle[j].size()) cout << cycle[i][(k%2)] << " " << cycle[j][k] << endl;
					}
					break;
				}
			}
		}
	}
	else cout << "NO\n";
	
	/*REP(i, nc){
		cout << i << ":"; REP(j, cycle[i].size()) cout << " " << cycle[i][j];
		cout << endl;
	}*/
}
