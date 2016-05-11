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
#define EPS 1e-9
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

int t;

int dr[] = {1,0,0,-1};
int dc[] = {0,-1,1,0};

int main(){
	cin >> t;
	while(t--){
		int m[10][10];
		bool finish = false;
		REP(i, 4)
		REP(j, 4){
			cin >> m[i][j];
			if(m[i][j] == 2048){
				finish = true;
			}
		}
		int pos = 0;
		if(!finish){
			REP(k, 4){
				REP(i, 4){
					REP(j, 4){
						int nr = i+dr[k], nc = j+dc[k];
						if(nr<4 && nr>=0 && nc < 4 && nc>=0){
							if(m[i][j] && (m[nr][nc] == 0 || m[nr][nc] == m[i][j])){
								pos |= (1 << k);
								break;
							}
						}
					}
				}
			}
		}
		string dir[4] = {"DOWN", "LEFT", "RIGHT", "UP"};
		bool space = false;
		REP(k, 4){
			if(pos&(1<<k)){
				if(space) cout << " ";
				cout << dir[k];
				space = true;
			}
		}
		if(pos == 0) cout << "NONE";
		cout << endl;
	}
}

