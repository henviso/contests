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
#include <iomanip>
#include <utility>   
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector< ii > vii;
typedef vector< ll > vll;
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

int n, t;
int p2[100];
int ans[100][2];
int lines[100];

typedef vector< vi > matrix;
	 
// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(n, vector<int>(n));
    REP(i, n) REP(j, n) REP(k, n)
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
    return C;
}

int main(){
	cin >> t;
	p2[0] = 1;
	REPP(i, 1, 20) p2[i] = p2[i-1]*2;
	REPP(tc, 1, t+1){
		cin >> n;
		matrix A(n, vector<int>(n));
		int k = 0, aux = 1;
		while(aux < n){ aux *= 2; k++; }
		int lst = (k > 0)? p2[k-1]+1 : 1;
		REP(i, n) ans[i][1] = 1;
		REP(i, n){
			ans[i][0] = lst;
			REP(j, n){
				cin >> A[i][j];
				if(j != i && A[i][j] == 0) ans[i][1] = lst;
			}
		}
		
		int l = n;
		matrix B = A;
		for(int z = k-1; z>=0; z--){
			CLEAR0(lines);
			//cout << "\n\nZ " << z << " L " << l << " \n";
			REP(i, n){
				REP(j, n){
					//cout << B[i][j] << " ";
					lines[i] += (B[i][j] > 0);
				}
				//cout << endl;
			}
			REP(i, n){
				//cout << " LINES " << i << " " << lines[i] << endl;
				if(lines[i] < l) ans[i][0] = (z > 0) ? p2[z-1] + 1 : 1;
			}
			B = mul(B, A); 
			l /= 2;
		}
		//cout << "Case #" << tc << ":\n";
		REP(i, n) cout << ans[i][0] << " " << ans[i][1] << endl;
	}
}

