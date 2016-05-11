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
#define EPS 1e-11
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

ii e[300100];
int w[300100];
vector< ii > g[300100], h[300100];
int dp[300100];


bool cmp(int const &a, int const &b){
	return w[a] < w[b];
}

int solve(int k){
    int &ans = dp[k];
    if(ans == -1){
        ans = 0;
        int v = e[k].second;
        int i = lower_bound(h[v].begin(), h[v].end(), ii(w[k], k)) - h[v].begin();
        int j = lower_bound(g[v].begin(), g[v].end(), ii(w[k]+1, -1)) - g[v].begin();
        int l = INF;
        if(i+1 < h[v].size()){
			ans = max(ans, solve(h[v][i+1].second));
			l = h[v][i+1].first + 1;
		}
        
        REPP(J, j, g[v].size()){
            ii a = g[v][J];
            if(a.first >= l) break;
            ans = max(ans, 1 + solve(a.second));
        }  
    }
    return ans;
}


int main(){
	cin >> n >> m;
	REP(i, m){
		dp[i] = -1;
		scanf(" %d %d %d ", &e[i].first, &e[i].second, &w[i]);
		g[e[i].first].push_back(ii(w[i], i));
		h[e[i].second].push_back(ii(w[i], i));
	}
	REPP(i, 1, n+1){
		sort(g[i].begin(), g[i].end());
		sort(h[i].begin(), h[i].end());
	}
	
	int ans = 0;
	REP(i, m){
		ans = max(ans, 1+solve(i));	
	}
	cout << ans << endl;
}
