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
typedef vector< ll > vll;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(ll i = 0LL; i<n; i++)
#define REPP(i,a,n) for(ll i = a; i<n; i++)
#define REPD(i,n) for(ll i = n-1; i>-1LL; i--)
#define REPDP(i,a,n) for(ll i = n-1; i>=a; i--)
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
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
int xl, yl;
int xd, yd;

int t[2000][4];
char name[2000][200];
bitset<2000> vis;

int isInside(int id, double X, double Y){
	return ((t[id][0] <= X && X <= t[id][2]) && (t[id][1] <= Y && Y <= t[id][3]));
}



int main(){
	while(1){
		scanf(" %d ", &n);
		if(n == 0) break;
		
		scanf(" %d %d ", &xl, &yl);
		scanf(" %d %d ", &xd, &yd);
		double XL = xl;
		double YL = yl;
		double MX = 1000.0 + EPS;
		double MN = -1000.0 - EPS;
		REP(i, n) scanf(" %s %d %d %d %d " , &name[i][0], &t[0][0], &t[0][1], &t[0][2], &t[0][3]);
		vi ans;
		while( (YL <= MX && YL >= MN)  && (XL <= MX && XL >= MN) ){
			REP(i, n) if(!vis[i] && isInside(i, XL, YL)){
				vis[i] = true;
				ans.pb(i);
			}
			YL += 0.001 * yd;
			XL += 0.001 * xd;
			cout << XL << " " << YL << endl; 
		}
		if(ans.size() > 0) cout << name[ans[0]];
		REPP(i, 1, ans.size()) cout << " " << name[ans[i]];
		cout << endl;
	}
}

