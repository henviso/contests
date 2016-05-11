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
#include <deque>

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
#define INF 1000000000000000000LL
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

int n, k, p[200100], e[200100];
vi g[200100];

int main(){
	cin >> n >> k;
	if(k != n+1){
		vii r(n);
		REP(i, n){
			cin >> p[i] >> e[i];
			r[i] = ii(p[i], i);
			g[e[i]].pb(p[i]);
		}
		//r[n] = ii(0, n);
		sort(r.rbegin(), r.rend());	
		int qnt = r[k-1].first;
		int hi = k-1, lo = k-1;
		while(hi >= 0 && r[hi].first <= qnt+1) hi--; hi++;
		while(lo < n && r[lo].first >= qnt-1) lo++;
		int haveToWin = lo-(k-1);
		
		//cout << " QNT " << qnt << endl;
		
		ll ans = INF;
		int po = 0;
		ll ef = 0;
		
		int cnt[200100]; CLEAR0(cnt);
		int trampled = 0, need = (n+1)-k;
		REP(i, 200100){
			if(trampled >= need) break;
			for(int j = 0; j<g[i].size(); j++){
				cnt[g[i][j]]++;
				po++;
				trampled += cnt[po];
				if(g[i][j] < po) trampled++;
				ef += (ll) i;
				if(trampled >= need) break;
			}	
		}
		if(trampled >= need) ans = min(ans, ef);
		//cout << " EF 1  EH " << ef << endl;
		
		//cout << " HAVE TO WIN " << haveToWin << endl;
		po = 0; ef = 0;
		REP(i, 200100){
			if(haveToWin <= 0) break;
			for(int j = 0; j<g[i].size(); j++){
				if(g[i][j] >= qnt-1 && g[i][j] <= qnt){
					
					//cout << " VENCENDO DE PONT " << g[i][j] << " EF " << i << endl;
					g[i].erase(g[i].begin()+j);
					j--;
					haveToWin--;
					po++;
					ef += (ll) i;
					
				}
				if(haveToWin <= 0) break;
			}
		}
		REP(i, 200100){
			if(po >= qnt) break;
			for(int j = 0; j<g[i].size(); j++){
				po++;
				ef += (ll) i;
				if(po >= qnt) break;
			}
		}
		//cout << " EF 2  EH " << ef << endl;
		if(haveToWin <= 0 && po >= qnt) ans = min(ans, ef);
		
		if(ans == INF) cout << "-1\n";
		else cout << ans << endl;
	}
	else cout << "0\n";
}
