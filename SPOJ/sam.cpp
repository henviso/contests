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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, k, p, t;
int a[500100];
int b[100100];
int nxt[500100];
bitset<100100> av;
priority_queue< ii > q;
queue<int> rem;
		
int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d %d %d ", &n, &k, &p);
		av.reset();
		while(!q.empty()) q.pop();
		while(!rem.empty()) rem.pop();
		REP(i, n+1) b[i] = INF;
		REP(i, p) scanf(" %d ", &a[i]); 
		REPD(i, p){
			nxt[i] = b[a[i]];
			b[a[i]] = i;  
		}
		int cars = 0;
		int ans = 0;
		REP(i, p){
			int c = a[i];
			if(!av[c]){
				if(cars == k){
					int r = 0;
					while(!q.empty() && !av[q.top().second]) q.pop();
					r = q.top().second; q.pop(); 
					av[r] = false;
				}
				else cars++;
				q.push(ii(nxt[i], a[i]));
				av[c] = true;
				ans++;
			}
			else q.push(ii(nxt[i], a[i]));
		}
		cout << ans << endl;
	}
}
