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
typedef vector<int> vi;
typedef vector<int>::iterator vit;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = a; i>a-n; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 2000000000
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
#define PI 3.14159265359
typedef unsigned long long ull;

int nb[10010], v[10010];
ull e, r, n;

int main(){
	int nc;
	scanf(" %d ", &nc);
	REP(ca, nc){
		scanf(" %llu %llu %llu ", &e, &r, &n);
		REP(i, n){
			nb[i] = INF;
			scanf(" %d ", &v[i]); 
		}
		vector< pair<int, int> > k; 
		k.pb(mp(v[n-1], n-1)); 
		nb[n-1] = INF;
		vector< pair<int, int> >::iterator p; 
		REPD(i, n-1){
			p = lower_bound(ALL(k), mp(v[i], i));
			if(p == k.end()) nb[i] = INF;
			else{
				cout << "IND ATUAL " << i << " IND PROX " << p->second << endl;
				nb[i] = p->second - i;
			}
			k.insert(p, mp(v[i],i));
		}
		ull en = e, ans = 0;
		cout << "Case " << ca+1 << " e " << e << " r " << r << endl;
		cout << endl;
		REP(i, n) cout << nb[i] << " "; cout << endl;
		REP(i, n){
			ull sp = 0;
			if(nb[i] == INF){
				sp = en;
				cout << " SP " << i << " EH " << sp << endl;
			}
			else{
				ull aux = nb[i]*r + en;
				if(aux > e){
					sp = min(aux - e, en);
					cout << " SP " << i << " EH " << sp << endl;
				}
			}
			ans += sp * v[i];
			en -= sp;
			en = min(en+r, e);
		}
		printf("Case #%d: %llu\n", ca+1, ans);
	}
}
