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

#define UNVISITED -1
#define VISITED 1
#define EXPLORED 2
#define MOD 1000000007LL

int n, m;
ll a[1100][1100];
ll malecome[1100][1100];
ll malego[1100][1100];
ll femcome[1100][1100];
ll femgo[1100][1100];

int main(){
    cin >> n >> m;
    REPP(i, 1, n+1) REPP(j, 1, m+1) cin >> a[i][j];
    
    CLEAR0(malego); CLEAR0(femgo);
    CLEAR0(malecome); CLEAR0(femcome);
    
    for(int i = n; i>0; i--){
        for(int j = m; j>0; j--) malego[i][j] = a[i][j] + max(malego[i+1][j], malego[i][j+1]);
        for(int j = 1; j<=m; j++) femcome[i][j] = a[i][j] + max(femcome[i+1][j], femcome[i][j-1]);
    }
    for(int i = 1; i<=n; i++){
        for(int j = m; j>0; j--) femgo[i][j] = a[i][j] + max(femgo[i-1][j], femgo[i][j+1]);
        for(int j = 1; j<=m; j++) malecome[i][j] = a[i][j] + max(malecome[i-1][j], malecome[i][j-1]);
    }
    
    ll ans = 0LL;
    for(int i = 2; i<n; i++)
    for(int j = 2; j<m; j++){
		//cout << femcome[i][j-1] << " + " <<  malecome[i-1][j] << " e " << femgo[i][j+1] << " + " << malego[i+1][j] << endl;
		//cout << femcome[i+1][j] << " + " << malecome[i][j-1] << " e " << femgo[i-1][j] << " + " << malego[i][j+1] << endl;
		ll cst = max(femcome[i][j-1] + malecome[i-1][j] +  femgo[i][j+1] + malego[i+1][j], 
					 femcome[i+1][j] + malecome[i][j-1] + femgo[i-1][j] + malego[i][j+1]);
		//cout << i << " " << j << " " << cst << endl << endl << endl;
		ans = max(ans, cst);
    }
    cout << ans << endl;
    
}
