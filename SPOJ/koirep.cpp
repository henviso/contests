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

int t, n, m;	
ii v[1000010];
ii r[1000010];

int main(){
	while(scanf(" %d %d ", &n, &m) != EOF){
		int p = 0, x;
		REP(i, n){
			REP(j, m){
				scanf(" %d ", &x);
				v[p++] = mp(x, i);
			}
		}
		//cout << " P EH " << p << endl;
		sort(v, v+p);
	
		//cout << " NP EH " << np << endl;
		int ans = INF;
		int tm[1100]; CLEAR0(tm);
		
		int i = 0, j = 0;
		int qnt = 0;
		
		//cout << " V EH "; REP(i, p) cout << v[i].first << "," << v[i].second << endl;
		
		while(i+j < p){
			
			//cout << "I " << i << " J " << j << endl;
			//cout << "team "; REP(z, n) cout << tm[z] << " ";
			//cout << endl;	
			
			if(qnt == n){
				//cout << "TIME OK\n";
				//cout << " MENOR " << v[i].first << " MAIOR " << v[i+j-1].first << endl;
				
				ans = min(ans, abs(v[i+j-1].first - v[i].first));	
				
				tm[v[i].second]--;
				if(tm[v[i].second] == 0) qnt--;
				i++;
				j--;
				continue;
			}
			
			while(i != i+j && v[i].second == v[i+j].second){
				tm[v[i].second]--;
				if(tm[v[i].second] == 0) qnt--;
				i++;
				j--;
			}
			if(tm[v[i+j].second] == 0) qnt++;
			tm[v[i+j].second]++;
			//cout << " ADICIONANDO TIME " << v[i+j].second << " FICOU " << tm[v[i+j].second] << endl;
			
			j++;
			
		}		
		cout << ans << endl;
	}
}	
