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
int hac[1100][1100];
int pd[1100][1100];

int act_hac(int r, int c, int d){
	if(hac[r][c] > hac[d][c] && hac[r][c]-hac[d][c] == r-d) return hac[r][c] - hac[d][c];
	return hac[r][c];
}

int largestArea(int r, int d){  
    int area[1100]; 	
    int st[10000];
    int top = 0, t;
          
    REPP(i, 1, m+1){  
	    while(top){  
			if(act_hac(r, i, d) <= act_hac(r, st[top-1], d)) top--;
			else break;
		}
		if(top == 0) t = 0;  
		else t = st[top-1];
		area[i] = i-t-1;
		st[top++] = i;
		//cout << " L " << i << " EH " << area[i] << endl;
    }  
	top = 0;
	for(int i = m; i>=1; i--){
	    while(top){  
			if(act_hac(r, i, d) <= act_hac(r, st[top-1], d)) top--;
			else break;
		}
		if(top == 0) t = m+1;  
		else t = st[top-1];
		//cout << " TOP EH " << top << " T EH " << t << endl;
		area[i] += t - i - 1;  
		st[top++] = i;
		//cout << " R " << i << " EH " << t - i - 1 << endl;
    }    
      
    int ans = 0;  
    //Calculating Area[i] and find max Area  
    REPP(i, 1, m+1){
		//cout << "h[ " << i << " ] Eh " << act_hac(r, i, d) << endl;
		//cout << " R " << r << " D " << d << " hac[r][c] " << hac[r][i] << " hac[d][c] " << hac[d][i] << " RES " << hac[r][i] - hac[d][i] << endl;
		area[i] = act_hac(r, i, d) * (area[i] + 1);
		//cout << " AREA " << i << " EH " << area[i] << endl;
		ans = max(ans, area[i]);
	}
	//cout << " LARGEST AREA " << r << " " << d << " EH " << ans << endl;
    return ans;  
}  
      
void precmp(){
	CLEAR(pd, -1);
	CLEAR0(hac); 
	REPP(i, 1, n+1)
	REPP(j, 1, m+1){
		if(a[i][j] == 0) hac[i][j] = hac[i-1][j] + 1;
	}
}  

int solve(int r1, int r2){
	if(pd[r1][r2] == -1) REPP(i, r1, r2+1) pd[r1][r2] = max(pd[r1][r2], largestArea(i, r1-1));         
	return pd[r1][r2];
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
	int q, l, h;
	scanf(" %d ", &q);
	REP(i, q){
		scanf(" %d %d ", &l, &h);
		printf("%d\n", solve(l, h));
	}
}
