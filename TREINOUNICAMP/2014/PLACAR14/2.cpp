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

string a, b, c, d;

class point{
	public:
	
	int x, y, w, z;
	
	point(){
		x = y = w = z = 0;
	}
	point(int _x, int _y, int _w, int _z){
		x = _x;
		y = _y;
		w = _w;
		z = _z;
	}
};

int pd[51][51][51][51];
int sum[51][51][51][51];
int A[300][100], B[300][100], C[300][100], D[300][100];
point ps[5];

int inter(int msk){
	int x, y, w, z;
	x = y = w = z = INF;
	if(CHECK(msk, 0)){
		x = min(ps[0].x, x);
		y = min(ps[0].y, y);
		w = min(ps[0].w, w);
		z = min(ps[0].z, z);
	}
	if(CHECK(msk, 1)){
		x = min(ps[1].x, x);
		y = min(ps[1].y, y);
		w = min(ps[1].w, w);
		z = min(ps[1].z, z);
	}
	if(CHECK(msk, 2)){
		x = min(ps[2].x, x);
		y = min(ps[2].y, y);
		w = min(ps[2].w, w);
		z = min(ps[2].z, z);
	}
	if(CHECK(msk, 3)){
		x = min(ps[3].x, x);
		y = min(ps[3].y, y);
		w = min(ps[3].w, w);
		z = min(ps[3].z, z);
	}
	if(x < 0 || y < 0 || w < 0 || z < 0) return 0;
	return sum[x][y][w][z];
}
						
int inter1(){
	if(ps[0].x < 0 || ps[0].y < 0 || ps[0].w < 0 || ps[0].z < 0) return 0;
	return sum[ps[0].x][ps[0].y][ps[0].w][ps[0].z];
}

int inter2(){
	int x = min(ps[0].x, ps[1].x); 
	int y = min(ps[0].y, ps[1].y); 
	int w = min(ps[0].w, ps[1].w); 
	int z = min(ps[0].z, ps[1].z);
	if(x < 0 || y < 0 || w < 0 || z < 0) return 0;
	return sum[x][y][w][z];
}

int inter3(){
	int x = min(min(ps[0].x, ps[1].x), ps[2].x); 
	int y = min(min(ps[0].y, ps[1].y), ps[2].y); 
	int w = min(min(ps[0].w, ps[1].w), ps[2].w); 
	int z = min(min(ps[0].z, ps[1].z), ps[2].z);
	if(x < 0 || y < 0 || w < 0 || z < 0) return 0;
	return sum[x][y][w][z];
}

int inter4(){
	int x = min(min(ps[0].x, ps[1].x), min(ps[2].x, ps[3].x)); 
	int y = min(min(ps[0].y, ps[1].y), min(ps[2].y, ps[3].y)); 
	int w = min(min(ps[0].w, ps[1].w), min(ps[2].w, ps[3].w)); 
	int z = min(min(ps[0].z, ps[1].z), min(ps[2].z, ps[3].z));
	if(x < 0 || y < 0 || w < 0 || z < 0) return 0;
	return sum[x][y][w][z];
}

bool validate(int I, int J, int K, int L){
	if(I < 0 || J < 0 || K < 0 || L < 0) return false;
	return true;
}

int main(){
	cin >> a >> b >> c >> d;
	a = "$"+a;
	b = "$"+b;
	c = "$"+c;
	d = "$"+d;
	int n = a.length(), m = b.length();
	int o = c.length(), p = d.length();
	
	CLEAR0(A); CLEAR0(B); CLEAR0(C); CLEAR0(D);
	REPP(i, 1, a.length()){
		int cr = a[i]-'a';
		REP(k, 26){
			if(k == cr) A[k][i] = i;
			else A[k][i] = A[k][i-1];
		}
	}
	REPP(i, 1, b.length()){
		int cr = b[i]-'a';
		REP(k, 26){
			if(k == cr) B[k][i] = i;
			else B[k][i] = B[k][i-1];
		}
	}
	REPP(i, 1, c.length()){
		int cr = c[i]-'a';
		REP(k, 26){
			if(k == cr) C[k][i] = i;
			else C[k][i] = C[k][i-1];
		}
	}
	REPP(i, 1, d.length()){
		int cr = d[i]-'a';
		REP(k, 26){
			if(k == cr) D[k][i] = i;
			else D[k][i] = D[k][i-1];
		}
	}
	CLEAR0(pd);
	CLEAR0(sum);
	sum[0][0][0][0] = pd[0][0][0][0] = 1;
	
	REP(i, n){
		REP(j, m){
			REP(k, o){
				REP(l, p){
					//sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
					//sum[i][j][k] = sum[i-1][j][k] + sum[i][j-1][k] + sum[i][j][k-1] - sum[i-1][j-1][k] - sum[i][j-1][k-1] - sum[i-1][j][k-1] + sum[i-1][j-1][k-1];
				
					if(validate(i-1,j,k,l)) sum[i][j][k][l] += sum[i-1][j][k][l];
					if(validate(i,j-1,k,l)) sum[i][j][k][l] += sum[i][j-1][k][l];
					if(validate(i,j,k-1,l)) sum[i][j][k][l] += + sum[i][j][k-1][l];
					if(validate(i,j,k,l-1)) sum[i][j][k][l] += + sum[i][j][k][l-1];
					if(validate(i-1,j-1,k,l)) sum[i][j][k][l] -= sum[i-1][j-1][k][l];
					if(validate(i-1,j,k-1,l)) sum[i][j][k][l] -= sum[i-1][j][k-1][l];
					if(validate(i-1,j,k,l-1)) sum[i][j][k][l] -= sum[i-1][j][k][l-1];
					if(validate(i,j-1,k-1,l)) sum[i][j][k][l] -= sum[i][j-1][k-1][l];
					if(validate(i,j-1,k,l-1)) sum[i][j][k][l] -= sum[i][j-1][k][l-1];
					if(validate(i,j,k-1,l-1)) sum[i][j][k][l] -= sum[i][j][k-1][l-1];
					if(validate(i-1,j-1,k-1,l)) sum[i][j][k][l] += sum[i-1][j-1][k-1][l];
					if(validate(i-1,j-1,k,l-1)) sum[i][j][k][l] += sum[i-1][j-1][k][l-1];
					if(validate(i-1,j,k-1,l-1)) sum[i][j][k][l] += sum[i-1][j][k-1][l-1];
					if(validate(i,j-1,k-1,l-1)) sum[i][j][k][l] += sum[i][j-1][k-1][l-1];
					if(validate(i-1,j-1,k-1,l-1)) sum[i][j][k][l] -= sum[i-1][j-1][k-1][l-1];	
						
					if(a[i] == b[j] && b[j] == c[k] && c[k] == d[l] && d[l] == a[i]){
						
						point p(i-1, j-1, k-1, l-1);
						int cr = a[i] - 'a';
						ps[0] = p; ps[0].x = A[cr][i-1]-1;
						ps[1] = p; ps[1].y = B[cr][j-1]-1;
						ps[2] = p; ps[2].w = C[cr][k-1]-1;
						ps[3] = p; ps[3].z = D[cr][l-1]-1;
						int tot = 0;
						int lim = (1 << 4);
						REPP(K, 1, lim){
							int INTER = inter(K);
							if(__builtin_popcount(K)%2) tot += INTER;
							else tot -= INTER;
						}
						pd[i][j][k][l] = sum[i-1][j-1][k-1][l-1] - tot;
						sum[i][j][k][l] += pd[i][j][k][l];
						//cout << "PD " << i << " " << j << " " << k << " " << l << " : " << pd[i][j][k][l] << endl;
						//cout << "TOT " << i << " " << j << " " << k << " " << l << " : " << tot << endl;
					}
					//cout << "SUM " << i << " " << j << " " << k << " " << l << " : " << sum[i][j][k][l] << endl;
					
				}
			}
		}
	}
	cout << sum[n-1][m-1][o-1][p-1]-1 << endl;
	
	
}
