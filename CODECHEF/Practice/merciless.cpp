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
#define EPS 1e-7
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

vi g[100100];
int a[100100];
int cc[100100], h[100100];
int pos[100100];
int p;

int info[400100], prop[400100];

vi ft, ans;

void ft_create(vi &t, int n){ t.assign(n+1, 0); }

int ft_rsq(const vi &t, int b){
	int sum = 0; for(; b; b -= CHECKFIRST(b)) sum += t[b];
	return sum;
}

int ft_rsq(const vi &t, int a, int b){
	return ft_rsq(t, b) - (a == 1? 0 : ft_rsq(t, a-1)); 
}

void ft_adjust(vi &t, int k, int v){
	for(; k  <= (int)t.size(); k += CHECKFIRST(k)) t[k] += v;
}

void dfs(int v){
	cc[v] = 1;
	pos[v] = p;
	//cout << " POS " << v << " " << pos[v] << " HEALTHY " << h[v] << endl;
	a[p] = h[v];
	p++;
	REP(i, g[v].size()){
		dfs(g[v][i]);
		cc[v] += cc[g[v][i]];
	}
	//cout << "pos " << v << " " << pos[v] << endl;
}

void build(int at, int idl, int idr){
	if(idl == idr){
		//cout << " A " << idl << " AT " << at << " EH " << a[idl] << endl;
		prop[at] = 0;
		info[at] = a[idl];
		return;
	}

	int mid = (idl + idr)/2;
	build(at*2, idl, mid);
	build(at*2 + 1, mid + 1, idr);

	info[at] = min(info[at*2], info[at*2 + 1]);
	prop[at] = 0;
}

int query(int at, int idl, int idr, int L, int H, int up){
	//cout << " QUERY EM " << idl << "," << idr << " DE " << L << " A " << H << " COM " << up << endl;
	if(H < idl || L > idr) return 0;
	if(L <= idl && idr <= H && info[at] + up > 0){
		prop[at] += up;
		info[at] += up;
		return 0;
	}
	
	if(idl == idr){
		//cout << " CHEGUEI NO NO " << at << " INFO EH " << info[at] << " ATUALIZANDO PRA INF\n";
		info[at] = INF;
		ft_adjust(ans, idl, 1);
		return 1;
	}
	
	int mid = (idl + idr)/2;
	
	//cout << "INFO DIR " << info[at*2+1] << " INFO ESQ " << info[at*2] << endl;
	
	info[at*2] += prop[at];
	prop[at*2] += prop[at];
	info[at*2+1] += prop[at];
	prop[at*2+1] += prop[at];
	prop[at] = 0;
	
	int aux = query(at*2, idl, mid, L, H, up) + query(at*2 + 1, mid + 1, idr, L, H, up);
	info[at] = min(info[at*2], info[at*2 + 1]);
	return aux;
}

int main(){
	int n;
	scanf(" %d ", &n);

	int f;
	h[0] = INF;
	REPP(i, 1, n+1){
		scanf(" %d %d ", &h[i], &f);
		g[f].pb(i);
	}
	p = 0;
	dfs(0);
	
	build(1, 0, n);
	ft_create(ft, n+10);
	ft_create(ans, n+10);
	
	int k, op;
	int w, x;
	scanf(" %d ", &k);
	REP(i,k){
		scanf(" %d ", &op);
		if(op == 1){
			scanf(" %d %d ", &w, &x);
			int l = pos[w]+1;
			int r = pos[w]+cc[w]-1;
			
			//cout << " VERT " << w << " L " << l << " R " << r << endl;
			if(r >= l){
				x = -x;
				while(query(1, 0, n, l, r, x)){
					x = 0;
					//cout << " NOVA QUERY\n";
				}
			}
		}
		else if(op == 2){
			scanf(" %d ", &w);
			x = 0;
			int l = pos[w]+1;
			int r = pos[w]+cc[w]-1;
			if(r >= l){
				while(query(1, 0, n, l, r, x));
			}
			printf("%d\n", cc[w] - 1 - ft_rsq(ans, l, r));
		}
	}
	//cout << "INF " << INF << endl;
}
