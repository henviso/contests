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

int a[1111][1111];

int u[1111][1111];
int l[1111][1111];
int r[1111][1111];
int d[1111][1111];

int n, m, q;

int maxArea(int *v, int t, int x){
	stack<int> st;
	int lim;
	int L[1111];
	int R[1111];
	int ans = 0;
	
	REP(i, t){  
		while(!st.empty()){  
			if(v[i] <= v[st.top()]) st.pop();  
			else break;
		}
		if(st.empty()) lim = -1;  
		else lim = st.top();  
		L[i] = i - lim - 1;  
		st.push(i);  
	}
	while(!st.empty()) st.pop();
	REPD(i, t){  
		while(!st.empty()){  
			if(v[i] <= v[st.top()]) st.pop();  
			else break;
		}
		if(st.empty()) lim = t;  
		else lim = st.top();  
		R[i] = lim - i - 1;  
		if(i-L[i] <= x && x <= i+R[i]) ans = max(ans, v[i]*(R[i]+L[i]+1));
		st.push(i);  
	}
	return ans;
}

int maxArea(int R, int C){
	int lim;  
	int ans = 0;
	
	int x[1111], y[1111];
	
	for(int j = 0; j<m; j++) x[j] = u[R][j];
	ans = max(ans, maxArea(x, m, C));
	
	for(int j = 0; j<m; j++) x[j] = d[R][j];
	ans = max(ans, maxArea(x, m, C));
	
	for(int i = 0; i<n; i++) x[i] = l[i][C];
	ans = max(ans, maxArea(x, n, R));
	
	for(int i = 0; i<n; i++) x[i] = r[i][C];
	ans = max(ans, maxArea(x, n, R));
	
	return ans;
}

int main(){
	cin >> n >> m >> q;
	REP(i, n){
		REP(j, m){
			cin >> a[i][j];
			if(a[i][j] == 1){
				u[i][j] = l[i][j] = 1;
				if(i-1 >= 0) u[i][j] += u[i-1][j];
				if(j-1 >= 0) l[i][j] += l[i][j-1];
			}	
		}	
	}
	REPD(i, n){
		REPD(j, m){
			if(a[i][j] == 1){
				d[i][j] = r[i][j] = 1;
				if(i+1 < n) d[i][j] += d[i+1][j];
				if(j+1 < m) r[i][j] += r[i][j+1];
			}	
		}
	}
	int x, R, C;
	REP(i, q){
		cin >> x >> R >> C;
		R--; C--;
		if(x == 2) cout << maxArea(R, C) << endl;	
		else{
			a[R][C] = 1 - a[R][C];
			for(int j = C; j<m; j++){
				l[R][j] = a[R][j];
				if(a[R][j] && j-1 >= 0) l[R][j] += l[R][j-1];
			}
			for(int j = C; j>=0; j--){
				r[R][j] = a[R][j];
				if(a[R][j] && j+1 < m) r[R][j] += r[R][j+1];
			}
			for(int i = R; i<n; i++){
				u[i][C] = a[i][C];
				if(a[i][C] && i-1 >= 0) u[i][C] += u[i-1][C];
			}
			for(int i = R; i>=0; i--){
				d[i][C] = a[i][C];
				if(a[i][C] && i+1 < n) d[i][C] += d[i+1][C];
			}
		}
	}
}

