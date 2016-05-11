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

int n, m, t;

int main() {
    scanf(" %d ", &t);
    while(t--){
        scanf(" %d %d ", &n, &m);
        int base = m/n, x = base, y;
        if(m > 0 && (m%n == 0)) x--; 
        m = m%n;
        if(m == 0) y = n/2 + 1;
		else{
			int r = m/2; 
			//cout << " R " << r << endl;
			if((base*n)%2){ //começa por tras
				if(m%2) y = n-r;
				else y = r;
			}
			else{ //começa pela frente
				if(m%2) y = r+1;
				else y = n-r+1;
				//cout << " Y " << y << endl;
			}
		}
        printf("%d %d\n", y, x);
    }
    return 0;
}
