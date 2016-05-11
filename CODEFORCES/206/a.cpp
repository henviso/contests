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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-11
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//scanf(" %d ", &t);

int n;
string c[1000];
int h[300];

bool can(int mask){
	REP(i, n){
		int co = h[c[i][0]], va = h[c[i][1]];
		if(mask&(1 << co)){
			if(mask&(1 << va)) continue;
			else{
				bitset<10> vis; vis.reset();
				int cnt = 0;
				REP(j, n){
					int cx = h[c[j][0]], vx = h[c[j][1]];
					if(cx == co && !vis[vx]){
						vis[vx] = true;
						if(mask&(1 << vx));
						else cnt++;
					}
				}
				if(cnt > 1) return false;
			}
		}
		else{
			if(mask&(1 << va)){
				bitset<10> vis; vis.reset();
				int cnt = 0;
				REP(j, n){
					int cx = h[c[j][0]], vx = h[c[j][1]];
					if(vx == va && !vis[cx]){
						vis[cx] = true;
						if(mask&(1 << cx));
						else cnt++;
					}
				}
				if(cnt > 1) return false;
			}
			else{
				REP(j, n){
					if(c[j] == c[i]) continue;
					int cx = h[c[j][0]], vx = h[c[j][1]];
					if(mask&(1 << cx) || mask&(1 << vx)) continue;
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
    cin >> n;
    h['R'] = 0;
    h['G'] = 1;
    h['B'] = 2;
    h['Y'] = 3;
    h['W'] = 4;
    h['1'] = 5;
    h['2'] = 6;
    h['3'] = 7;
    h['4'] = 8;
    h['5'] = 9;
    REP(i, n) cin >> c[i];
    int m = (1 << 10);
	int ans = INF;
    REP(i, m){
		if(can(i)){
			ans = min(ans, __builtin_popcount(i));
			//if(__builtin_popcount(i) == ans) cout << "I " << i << endl;
		}
	}
	cout << ans << endl; 
}
