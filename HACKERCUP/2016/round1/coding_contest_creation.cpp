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

int t, n;
int d[200000];

int main(){
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> n;
		REP(i, n) cin >> d[i];
		d[n] = -1;
		int ans = 0;
		int left = 3;
		REP(i, n){
			if(left <= 0){
				left = 3;
				continue;
			}
			
			int D = d[i+1]-d[i];
			if(D <= 0){
				ans += left;
				left = 3;
			}
			else if(D <= 10) left--;
			else{
				int x = (D/10) - ((D%10) == 0);
				if(x <= (left-1)){
					ans += x;
					left -= (x + 1);
				}
				else{
					ans += left;
					left = 3;
				}
			}
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}

