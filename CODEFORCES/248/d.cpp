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

int hv[1111][1111];
int hh[1111][1111];


int n, m, q;

void precmp(){
	int lim;  
	
	
	REP(i, n){
		stack<int> st;
		REP(j, m){  
			while(!st.empty()){  
				if(hv[i][j] <= hv[i][st.top()]) st.pop();  
				else break;
			}
			if(st.empty()) lim = -1;  
			else lim = st.top();  
			l[i][j] = j - lim - 1;  
			st.push(j);  
		}
		while(!st.empty()) st.pop();
		REPD(j, m){  
			while(!st.empty()){  
				if(hv[i][j] <= hv[i][st.top()]) st.pop();  
				else break;
			}
			if(st.empty()) lim = m;  
			else lim = st.top();  
			r[i][j] = lim - j - 1;  
			st.push(j);  
		}
	}
	
	REP(j, m){
		stack<int> st;
		REP(i, n){  
			while(!st.empty()){  
				if(hh[i][j] <= hh[st.top()][j]) st.pop();  
				else break;
			}
			if(st.empty()) lim = -1;  
			else lim = st.top();  
			u[i][j] = i - lim - 1;  
			st.push(i);  
		}
		while(!st.empty()) st.pop();
		REPD(i, n){  
			while(!st.empty()){  
				if(hh[i][j] <= hh[st.top()][j]){
					st.pop();  
				}	
				else break;
			}
			if(st.empty()) lim = n;  
			else lim = st.top();  
			d[i][j] = lim - i - 1;  
			st.push(i);  
		}
	}
}

int main(){
	cin >> n >> m >> q;
	CLEAR0(hv);
	CLEAR0(hh);
	REP(i, n){
		REP(j, m){
			cin >> a[i][j];
			if(a[i][j] == 1){
				hv[i][j] = hh[i][j] = 1;
				if(i-1 >= 0) hv[i][j] += hv[i-1][j];
				if(j-1 >= 0) hh[i][j] += hh[i][j-1];
			}	
		}	
	}	
	precmp();
	int x, R, C;
	REP(i, q){
		cin >> x >> R >> C;
		R--; C--;
		if(x == 2){
			int ans = 0;
			for(int i = R; i<n && hv[i][C] >= i-R+1; i++){
				ans = max(ans, hv[i][C] * (l[i][C]+1));
				//cout << " HV " << i << " " << C << " EH " << hv[i][C] << " L EH " << l[i][C] << endl;
				ans = max(ans, hv[i][C] * (r[i][C]+1));
				//cout << " HV " << i << " " << C << " EH " << hv[i][C] << " R EH " << r[i][C] << endl;
			}
			for(int j = C; j<m && hh[R][j] >= j-C+1; j++){
				ans = max(ans, hh[R][j] * (u[R][j]+1));
				//cout << " HH " << R << " " << j << " EH " << hh[R][j] << " U EH " << u[R][j] << endl;
				ans = max(ans, hh[R][j] * (d[R][j]+1));
				//cout << " HH " << R << " " << j << " EH " << hh[R][j] << " D EH " << d[R][j] << endl;
			}
			cout << ans << endl;
		}
		else{
			if(a[R][C] == 1){
				for(int i = R; i<n && hv[i][C] >= i-R+1; i++) hv[i][C] = i-R;
				for(int j = C; j<m && hh[R][j] >= j-C+1; j++) hh[R][j] = j-C;
			}
			else{
				
			}
			a[R][C] = 1 - a[R][C];
		}
	}
			
	
}

