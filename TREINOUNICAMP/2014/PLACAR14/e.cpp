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

int bits[100];
int charToInt[300];
	
ll pd[52][52][52][52];
ll sum[52][52][52][52];
ll A[300][100], B[300][100], C[300][100], D[300][100];
point ps[5];

ll inter(int msk){
	int x, y, w, z;
	x = y = w = z = INF;
	if(CHECK(msk, 0)){
		if(ps[0].x < x) x = ps[0].x;
		if(ps[0].y < y) y = ps[0].y;
		if(ps[0].w < w) w = ps[0].w;
		if(ps[0].z < z) z = ps[0].z;
	}
	if(CHECK(msk, 1)){
		if(ps[0].x < x) x = ps[1].x;
		if(ps[1].y < y) y = ps[1].y;
		if(ps[1].w < w) w = ps[1].w;
		if(ps[1].z < z) z = ps[1].z;
	}
	if(CHECK(msk, 2)){
		if(ps[2].x < x) x = ps[2].x;
		if(ps[2].y < y) y = ps[2].y;
		if(ps[2].w < w) w = ps[2].w;
		if(ps[2].z < z) z = ps[2].z;
	}
	if(CHECK(msk, 3)){
		if(ps[3].x < x) x = ps[3].x;
		if(ps[3].y < y) y = ps[3].y;
		if(ps[3].w < w) w = ps[3].w;
		if(ps[3].z < z) z = ps[3].z;
	}
	if(x < 0 || y < 0 || w < 0 || z < 0) return 0LL;
	return sum[x][y][w][z];
}

int main(){
	int lim = (1 << 4);
	REP(i, 26) charToInt[((int) 'a'+i)] = i;
	REPP(K, 1, lim) bits[K] = __builtin_popcount(K);
	
	cin >> a >> b >> c >> d;
	a = "AB"+a;
	b = "CD"+b;
	c = "EF"+c;
	d = "GH"+d;
	int n = a.length(), m = b.length();
	int o = c.length(), p = d.length();
	
	int cnt = 0;
	bitset<300> vis; vis.reset();
	CLEAR0(A); CLEAR0(B); CLEAR0(C); CLEAR0(D);
	REPP(i, 2, a.length()){
		int cr = a[i]-'a';
		if(!vis[cr]){ vis[cr] = true; cnt++; }
		REP(k, 26){
			if(k == cr) A[k][i] = i;
			else A[k][i] = A[k][i-1];
		}
	}
	REPP(i, 2, b.length()){
		int cr = b[i]-'a';
		if(!vis[cr]){ vis[cr] = true; cnt++; }
		REP(k, 26){
			if(k == cr) B[k][i] = i;
			else B[k][i] = B[k][i-1];
		}
	}
	REPP(i, 2, c.length()){
		int cr = c[i]-'a';
		if(!vis[cr]){ vis[cr] = true; cnt++; }
		REP(k, 26){
			if(k == cr) C[k][i] = i;
			else C[k][i] = C[k][i-1];
		}
	}
	REPP(i, 2, d.length()){
		int cr = d[i]-'a';
		if(!vis[cr]){ vis[cr] = true; cnt++; }
		REP(k, 26){
			if(k == cr) D[k][i] = i;
			else D[k][i] = D[k][i-1];
		}
	}
	if(cnt == 1){
		cout << min(min(n, m), min(o, p))-2 << endl;
	}
	else{
		CLEAR0(pd);
		CLEAR0(sum);
		sum[1][1][1][1] = pd[1][1][1][1] = 1LL;
		
		REPP(i, 1, n){
			REPP(j, 1, m){
				REPP(k, 1, o){
					REPP(l, 1, p){
						//sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
						//sum[i][j][k] = sum[i-1][j][k] + sum[i][j-1][k] + sum[i][j][k-1] - sum[i-1][j-1][k] - sum[i][j-1][k-1] - sum[i-1][j][k-1] + sum[i-1][j-1][k-1];
						
						sum[i][j][k][l] += sum[i-1][j][k][l] + sum[i][j-1][k][l] + sum[i][j][k-1][l] + sum[i][j][k][l-1]
										- sum[i-1][j-1][k][l] - sum[i-1][j][k-1][l] - sum[i-1][j][k][l-1] - sum[i][j-1][k-1][l]
										- sum[i][j-1][k][l-1] - sum[i][j][k-1][l-1] + sum[i-1][j-1][k-1][l] + sum[i-1][j-1][k][l-1]
										+ sum[i-1][j][k-1][l-1] + sum[i][j-1][k-1][l-1] - sum[i-1][j-1][k-1][l-1];
						
						
							
						if(a[i] == b[j] && c[k] == d[l] && d[l] == a[i]){
							
							point p(i-1, j-1, k-1, l-1);
							int cr = charToInt[a[i]];
							ps[0] = p; ps[0].x = A[cr][i-1]-1;
							ps[1] = p; ps[1].y = B[cr][j-1]-1;
							ps[2] = p; ps[2].w = C[cr][k-1]-1;
							ps[3] = p; ps[3].z = D[cr][l-1]-1;
							ll tot = 0;
							int lim = (1 << 4);
							REPP(K, 1, lim){
								ll INTER = inter(K);
								if(bits[K] == 1 || bits[K] == 3) tot += INTER;
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
}

