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
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
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
//__builtin_popcount(m)
//scanf(" %d ", &t);
typedef unsigned long long hash;


int t;
int n, m;
int g[100][100];
int row[100];

pair<string, int> ord[100];
string zip[100];
bitset<100> vis, visback;

bool found;

void bt(int col){
	//cout << " BT " << col << " : " ;
	//REP(i, col+1) cout << row[i] << " ";
	//cout << endl;
	
	if(found || col == n){
		found = true;
		return;
	}
	int v = row[col];
	
	REPP(i, 1, n+1){
		int u = ord[i].second;  
		//cout << " V " << v << " U EH " << u << endl; 
		if(vis[u]) continue;
		
		vis[u] = true;
		row[col+1] = u;
		
		if(g[v][u] == 1){
			bt(col+1); if(found) return;
		}
		
		int seted[100], p = 1;
		seted[0] = v;
		visback[v] = true;
		
		for(int j = col-1; j > 0; j--){
			int nv = row[j];
			//cout << "J " << j << " NV " << nv << endl;
			
			if(!visback[nv]){
				if(g[nv][u] == 1){
					//cout << " J " << j << " NV QUE DEU EH " << nv << endl;
					bt(col+1); if(found) return;
				}
				else{
					visback[nv] = true;
					seted[p++] = nv;
				}
			}
		}
		REP(j, p){
			int nv = seted[j];
			visback[nv] = false;
		}
		vis[u] = false;
	}
}

int main(){
	cin >> t;
	REPP(ca, 1, t+1){
		int u, v;
		CLEAR0(g);
		
		cin >> n >> m;
		REPP(i, 1, n+1){
			cin >> zip[i];
			ord[i].first = zip[i];
			ord[i].second = i;
			g[0][i] = g[i][0] = true;
		}
			
		REP(i, m){
			cin >> u  >> v;
			g[u][v] = g[v][u] = 1;
		}
		
		sort(ord+1, ord+n+1);
		
		vis.reset();
		visback.reset();
		vis[0] = true; row[0] = 0;
		found = false;
		bt(0);
		
		string ans = "";
		REPP(i, 1, n+1) ans += zip[row[i]];
		
		cout << "Case #" << ca << ": " << ans << endl;
	}
}
