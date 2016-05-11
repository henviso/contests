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

ll c[1000100];
ll r[1000100];
ll l[1000100];

int n, m;

int main(){
	cin >> n >> m;
	REP(i, n) cin >> c[i];
	CLEAR0(r);
	CLEAR0(l);
	int s = n/2;
	int lft = (n%2)? n/2 : n/2 - 1;
	int rgt = n/2;
	
	ll ans = 0LL;
	int lstps = lft/m + (lft%m > 0);
	int rstps = rgt/m + (rgt%m > 0);
	
	cout << "lstps " << lstps << endl;
	
	REPP(i, 1, lstps+1){
		if(lft%m && (lft/m == 0 || i == lstps-1)){
			ans += abs(c[s-((i-1)*m + lft%m)]-c[s]);
			cout << " " << c[s-((i-1)*m + lft%m)] << endl;;
		}
		else{
			if(i == lstps){
				cout << " " << c[0] << endl;
				ans += abs(c[0]-c[s]);
			}
			else{
				cout << " " << c[s-i*m] << endl;
				ans += abs(c[s-i*m]-c[s]);
			}
		}
		//cout << " ANS " << ans << endl;
	}
	REPP(i, 1, rstps+1){
		if(i == rstps-1 && (rgt/m == 0 || i == rstps-1)){
			cout << " " << c[s+((i-1)*m + rgt%m)] << endl;
			ans += abs(c[s+((i-1)*m + rgt%m)] - c[s]);
		}
		else{
			if(i == rstps){
				cout << " " << c[n-1] << endl;
				ans += abs(c[n-1]-c[s]);
			}
			else{
				cout << " " << c[s+i*m] << endl;
				ans += abs(c[s+i*m]-c[s]);
			}
		}
	}
	ans *= 2LL;
	cout << ans << endl;
}

