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

int n, m;
int p[5000];
int b[5000];


int main(){
    cin >> n;
    REPP(i, 1, n+1){
		cin >> p[i];
		b[i] = p[i];
	}
	cin >> m;
    int swaps = 0;
    REPP(i, 1, n+1){
		if(b[i] == i) continue;
		REPP(j, i+1, n+1){
			if(b[j] == i){
				swap(b[i], b[j]);
				swaps++;
				break;
			}
		}
	}
	
	//cout << " SWAPS " << swaps << " " << m << endl;
	
	vi ans;
	for(int i = 1; i<n+1 && swaps > m; i++){
		while(p[i] != i && swaps > m){
			int nxt = p[i], mn = INF;
			while(nxt != i){
				mn = min(nxt, mn);
				nxt = p[nxt];
			}
			if(mn != INF){
				swap(p[i], p[mn]);
				ans.push_back(min(i, mn));
				ans.push_back(max(i, mn));
				swaps--;
			}
		}
	}
	bitset<3010> vis;
	for(int i = 1; i<n+1 && swaps < m; i++){
		int lst = i, act = p[i];
		do{
			vis[act] = true;
			lst = act;
			act = p[act];
		} while(lst != i);
		for(int k = 1; k<n+1 && swaps<m; k++){
			if(!vis[k]){
				int lst2 = k, act2 = p[k];
				do{
					vis[act2] = true;
					lst2 = act2;
					act2 = p[act2];
				} while(lst2 != k);
				p[lst] = k;
				p[lst2] = i;
				swaps++;
				ans.push_back(min(k, i));
				ans.push_back(max(k, i));
				swap(lst, lst2);
			}
		}
	}
	
	cout << ans.size()/2;
	if(ans.size() > 0){
		cout << endl << ans[0];
		REPP(i, 1, ans.size()) cout << " " << ans[i];
	} 
}
