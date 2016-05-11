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

int t, n, k;
char a[100][100];
int dr[] = {0, 1, 1, 1};
int dc[] = {1, 0, 1, -1};

int main(){
	while(cin >> t){
		while(t--){
			cin >> n >> k;
			REP(i, n)
			REP(j, n) cin >> a[i][j];
			bool pos = false;
			REP(i, n)
			REP(j, n){
				REP(l, 4){
					int r = i, c = j, x = 0, cnt = 0;
					while(min(r, c) >= 0 && r < n && c < n && cnt < k && a[r][c] != 'O'){
						cnt++;
						if(a[r][c] == 'X') x++;
						r += dr[l]; c += dc[l];
					}
					if((cnt) == k && x == (k-1)) pos = true;
				}
			}
			if(pos) cout << "YES\n";
			else cout <<"NO\n";
		}
		
	}
}

