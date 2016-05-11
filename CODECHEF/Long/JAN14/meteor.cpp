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

int n, m;
int a[1100][1100];
int pd[1100][1100];
ii hac[1100][1100];
int hArea[1100][1100];
int hBase[1100][1100];

void largestArea(int r){  
    int st[10000];
    int top = 0, t;
    
    REPP(i, 1, m+1){  
	    while(top){  
			if(hac[r][i].first <= hac[r][st[top-1]].first) top--;
			else break;
		}
		if(top == 0) t = 0;  
		else t = st[top-1];
		hac[r][i].second = i-t-1;
		st[top++] = i;
		//cout << " L " << i << " EH " << hac[r][i].second << endl;
    }  
	top = 0;
	for(int i = m; i>=1; i--){
	    while(top){  
			if(hac[r][i].first <= hac[r][st[top-1]].first) top--;
			else break;
		}
		if(top == 0) t = m+1;  
		else t = st[top-1];
		//cout << " TOP EH " << top << " T EH " << t << endl;
		hac[r][i].second += t - i;  
		st[top++] = i;
		//cout << " R " << i << " EH " << hac[r][i].second << endl;
    }  
    sort(&hac[r][1], &hac[r][1]+m);
    REPP(j, 1, m+1) hArea[r][j] = max(hArea[r][j-1], hac[r][j].first*hac[r][j].second);
    for(int j = m; j>=1; j--){
		hBase[r][j] = max(hBase[r][j+1], hac[r][j].second);
		//cout << "j = " << j << " max(" << hBase[r][j+1] << ", " << hac[r][j].second << ")\n";
	}
	//cout << " LARGEST AREA " << r << " " << d << " EH " << ans << endl;
    return;  
}

int largestArea(int r, int mH){  
    ii x(mH, -INF);
    int p = (lower_bound(&hac[r][1], &hac[r][1]+m, x) - (&hac[r][1]))+1;
    return max(hArea[r][p-1], mH*hBase[r][p]); 
}  
      
void precmp(){
	CLEAR(pd, -1);
	CLEAR0(hac); 
	REPP(i, 1, n+1)
	REPP(j, 1, m+1){
		if(a[i][j] == 0) hac[i][j].first = hac[i-1][j].first + 1;
	}
}  

void solve(){
	CLEAR0(pd);
	CLEAR0(hArea);
	CLEAR0(hBase);
	REPP(i, 1, n+1) largestArea(i);
	REP(k, n){
		for(int i = 1; i+k<=n; i++){
			pd[i][i+k] = max(pd[i+1][i+k], pd[i][i+k-1]);
			pd[i][i+k] = max(pd[i][i+k], largestArea(i+k, k+1));
		}
	}
}

int main() {
	CLEAR0(a);
	int k;
	scanf(" %d %d %d ", &n, &m, &k);
	int x, y;
	REP(i, k){
		scanf(" %d %d ", &x, &y);
		a[x][y] = 1;
	}
	precmp();
	solve();
	int q, l, h;
	scanf(" %d ", &q);
	REP(i, q){
		scanf(" %d %d ", &l, &h);
		printf("%d\n", pd[l][h]);
	}
}
