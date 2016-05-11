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
int n, l, ID;

string s[400];
string txor[400][400];

vi g[22600][400];

vi match;
bitset<500> vis;

tr1::unordered_map<hash, ii > m;

#define B 33ULL
#define C 5381ULL

ull power[300];
hash p[300];

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, 300) power[i] = power[i-1]*B;
}

hash getHash(string &x){
	hash ans = 0ULL;
	REP(j, x.length()) ans = ans*B + x[j];
	return ans;
}

string xOr(string &a, string &b){
	string ans(l, '0');
	REP(i, l){
		int d = (a[i]-'0')^(b[i]-'0');
		ans[i] += d;
	}
	return ans;
}

int Aug(int L){
	if(vis[L]) return 0;
	vis[L] = true;
	REP(j, (g[ID][L]).size()){
		int r = g[ID][L][j];
		if(match[r] == -1 || Aug(match[r])){
			match[r] = L;
			return 1;
		}
	}
	return 0;
}

int main(){
	cin >> t;
	REPP(ca, 1, t+1){
		cin >> n >> l;
		REP(i, n) cin >> s[i];
		REPP(i, n, 2*n) cin >> s[i];
		
		int ans = INF;
		m.clear();
		
		int p = 0;
		REP(i, n) REPP(j, n, 2*n){
			string z = xOr(s[i], s[j]);
			txor[i][j] = txor[j][i] = z;
			hash h = getHash(z);
			int id;
			int cnt = 0;
			REP(_i, z.length()) cnt += (z[_i] == '1');
			
			if(m.count(h) == 0){
				m[h] = ii(p, cnt);
				id = p++;
				REP(j, 2*n) g[id][j].clear();
			}
			else id = m[h].first;
			g[id][i].push_back(j);
		}
		
		for(tr1::unordered_map<hash, ii >::iterator it = m.begin(); it != m.end(); it++){
			int cnt = (it->second).second;
			ID = (it->second).first;
			if(cnt >= ans) continue;
			
			int MCBM = 0;
			match.assign(2*n, -1);
			REP(L, n){
				vis.reset();
				MCBM += Aug(L);
			}
			//cout << " MCBM " << MCBM << endl;
			if(MCBM == n){
				//cout << " RESPOSTA VEIO DA PALAVRA " << x << endl;
				ans = min(cnt, ans);
			}
		}
		if(ans == INF) cout << "Case #" << ca << ": NOT POSSIBLE\n";	
		else cout << "Case #" << ca << ": " << ans << endl;
	}
}
