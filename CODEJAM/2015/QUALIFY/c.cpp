#include <iostream>
#include <cstdio>
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
#include <iomanip>
#include <cstring>
#include <unistd.h>
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
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t, n, l, x;
string s;
int pd[11000];
int a[10][10];
int r[10][10];
int b[11000];
int h[300];

void preSet(){
	h['1'] = 1; h['i'] = 2; h['j'] = 3; h['k'] = 4; //h['-1'] = 5; h['-i'] = 6; h['-j'] = 7; h['-k'] = 8;
	
	a[1][1] = 1; a[1][2] = 2; a[1][3] = 3; a[1][4] = 4; a[1][5] = 5; a[1][6] = 6; a[1][7] = 7; a[1][8] = 8;
	a[2][1] = 2; a[2][2] = 5; a[2][3] = 4; a[2][4] = 7; a[2][5] = 6; a[2][6] = 1; a[2][7] = 8; a[2][8] = 3;
	a[3][1] = 3; a[3][2] = 8; a[3][3] = 5; a[3][4] = 2; a[3][5] = 7; a[3][6] = 4; a[3][7] = 1; a[3][8] = 6;
	a[4][1] = 4; a[4][2] = 3; a[4][3] = 6; a[4][4] = 5; a[4][5] = 8; a[4][6] = 7; a[4][7] = 2; a[4][8] = 1;	
	a[5][1] = 5; a[5][2] = 6; a[5][3] = 7; a[5][4] = 8; a[5][5] = 1; a[5][6] = 2; a[5][7] = 3; a[5][8] = 4;
	a[6][1] = 6; a[6][2] = 1; a[6][3] = 8; a[6][4] = 3; a[6][5] = 2; a[6][6] = 5; a[6][7] = 4; a[6][8] = 7;	
	a[7][1] = 7; a[7][2] = 4; a[7][3] = 1; a[7][4] = 6; a[7][5] = 3; a[7][6] = 8; a[7][7] = 5; a[7][8] = 2;
	a[8][1] = 8; a[8][2] = 7; a[8][3] = 2; a[8][4] = 1; a[8][5] = 4; a[8][6] = 3; a[8][7] = 6; a[8][8] = 5; 
	
	r[1][1] = 1; r[1][2] = 2; r[1][3] = 3; r[1][4] = 4; r[1][5] = 5; r[1][6] = 6; r[1][7] = 7; r[1][8] = 8;
	r[2][1] = 6; r[2][2] = 1; r[2][3] = 8; r[2][4] = 3; r[2][5] = 2; r[2][6] = 5; r[2][7] = 4; r[2][8] = 7;	
	r[3][1] = 7; r[3][2] = 4; r[3][3] = 1; r[3][4] = 6; r[3][5] = 3; r[3][6] = 8; r[3][7] = 5; r[3][8] = 2;
	r[4][1] = 8; r[4][2] = 7; r[4][3] = 2; r[4][4] = 1; r[4][5] = 4; r[4][6] = 3; r[4][7] = 6; r[4][8] = 5;
	r[5][1] = 5; r[5][2] = 6; r[5][3] = 7; r[5][4] = 8; r[5][5] = 1; r[5][6] = 2; r[5][7] = 3; r[5][8] = 4;
	r[6][1] = 2; r[6][2] = 5; r[6][3] = 4; r[6][4] = 7; r[6][5] = 6; r[6][6] = 1; r[6][7] = 8; r[6][8] = 3;
	r[7][1] = 3; r[7][2] = 8; r[7][3] = 5; r[7][4] = 2; r[7][5] = 7; r[7][6] = 4; r[7][7] = 1; r[7][8] = 6;
	r[8][1] = 4; r[8][2] = 3; r[8][3] = 6; r[8][4] = 5; r[8][5] = 8; r[8][6] = 7; r[8][7] = 2; r[8][8] = 1;
}

int val(int L, int R){
	if(L == 0) return pd[R];
	int X = pd[L-1], Y = pd[R];
	return r[X][Y];
}

int main(){
	preSet();
	cin >> t; 
	REPP(tc, 1, t+1){
		bool pos = false;
		cin >> l >> x >> s;
		string aux = s;
		REP(i, x-1) s += aux;
		l *= x;
		REP(i, l){
			b[i] = h[s[i]];
			//cout << "B[" << i << "]: " << b[i] << endl;
		}
		REP(i, l){
			pd[i] = (i>0)? a[pd[i-1]][b[i]] : b[i];
			//cout << "PD[" << i << "]: " << pd[i] << endl;
		}
		
		//if(s.length() < 100) cout << " S " << s << endl;
		
		vi A, B;
		REP(i, l){
			//cout << " VAL  ATE " << i << " " << val(0, i) << endl;
			if(val(0, i) == 2) A.push_back(i);
			else if(val(i, l-1) == 4) B.push_back(i);
		}
		REP(i, A.size()){
			int j = lower_bound(B.begin(), B.end(), A[i]+2)-B.begin(); 
			while(j < B.size()){
				if(val(A[i]+1, B[j]-1) == 3){ pos = true; break; }
				j++;
			}
			if(pos) break;
		}
		if(pos) cout << "Case #" << tc << ": YES\n";
		else cout << "Case #" << tc << ": NO\n";
	}
}
