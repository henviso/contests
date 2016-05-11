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

int n;
string s[50];

int pd[40][1048580];
ii fst[40];

int solve(int move, int msk){
    int &ans = pd[move][msk];
    if(move == 2*(n-1)){
        return 0;
    }
    if(ans == -INF){
		//cout << "MOVE " << move << " MSK " << msk << endl;
		
		int nm[30]; CLEAR0(nm);
		int fr = fst[move+1].first; 
		int fc = fst[move+1].second;
		int r = fr, c = fc;
		int p = 0;
		//cout << " FR " << fr << " FC " << fc << endl;
		while(r >= 0 && c < n){
			int l = s[r][c] - 'a';
			//cout << "r " << r << " C " << c << endl;
			if(c-1 >= 0){
				int d = fst[move].first-r; 
				//cout << "verificando se " << d << " ESTA SETADO EM MSK\n";
				if(msk&(1<<d)) nm[l] |= (1 << p);
			}
			if(r-1 >= 0){
				int d = fst[move].first-(r-1);
				//cout << "verificando se " << d << " ESTA SETADO EM MSK\n";
				if(msk&(1<<d)) nm[l] |= (1 << p);
			}	
			r--;
			c++;
			p++;
		}
		REP(i, 26){
			//cout << " LETRA " << (char) ('a'+i) << " EH " << nm[i] << endl;; 
			if(nm[i]){
				int a = -solve(move+1, nm[i]);
				if(i == 0) a += (move%2)? 1 : -1;
				if(i == 1) a += (move%2)? -1 : 1;
				ans = max(a, ans);
			}
		}
    }
    return ans;
}



int main(){
    cin >> n;
    
    REP(i, n) cin >> s[i];
	REP(i, n) fst[i] = ii(i, 0);
	REP(j, n-1) fst[n+j] = ii(n-1, j+1);
	
	int t = 0;
    REP(i, 2*n - 1){
		int l = (1 << (t+1));
		REP(k, l) pd[i][k] = -INF;
		if(i < n-1) t++;
		else t--;
	}
    
    int ans = -solve(0, 1);
    if(s[0][0] == 'a') ans++;
    if(s[0][0] == 'b') ans--;
    
    //cout << " ANS " << ans << endl;
    
    if(ans > 0) cout << "FIRST\n";
    else if(ans < 0) cout << "SECOND\n";
    else cout << "DRAW\n";
}
