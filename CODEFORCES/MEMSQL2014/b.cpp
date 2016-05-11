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
#define EPS 1e-10
//scanf(" %d ", &t);

int n, m, k;

int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

vector< pair<double, double> > v, p, RES;
pair<double, double> a[4000100];
bool used[1010][1010];

double ANS = 0.0;

void act(){
	double ans = 0.0;
	REP(i, 3) ans += hypot(p[i].first - p[i+1].first, p[i].second - p[i+1].second);
	if(fabs(ANS - ans) > EPS && ANS < ans){
		RES = p;
		ANS = ans;
	}
}




int main(){
    
    cin >> n >> m;
	
	
	double dn = n+1, dm = m+1;
	CLEAR0(used);
	REP(j, m+3) used[0][j] = true;
	for(int j = m+2; j>=0; j--) used[n+2][j] = true;
	REP(i, n+3) used[i][0] = true;
	for(int i = n+2; i>=0; i--) used[i][m+2] = true;
	int r = 1, c = 1;
	REP(K, 2){
		REP(z, 4){
			while(!used[r][c] || !used[r+dr[z]][c+dc[z]]){
				if(!used[r][c]){
					//cout << r << " " << c << endl;
					used[r][c] = true;
					if((fabs(r- dn) <= EPS && fabs(c - dm) <= EPS) || (fabs(r- 1.0) <= EPS && fabs(c - 1.0) <= EPS));
					else a[k++] = mp((double) r, (double) c );
				}
				if(!used[r+dr[z]][c+dc[z]]){
					r += dr[z];
					c += dc[z];
				}
			}
		}
	}
	
	ANS = 0.0;
	v.push_back(mp(1.0, 1.0));
	v.push_back(mp(dn, dm));
	REP(i, k)
	REPP(j, i+1, k){
		//cout << " i " << i << " j " << j << endl;
		REP(b, 3){
			REP(c, 4){
				p = v;
				p.insert(p.begin()+b, a[i]);
				p.insert(p.begin()+c, a[j]);
				act();
			}
		}
	}
	REP(i, RES.size()) cout << RES[i].first-1.0 << " "  << RES[i].second-1.0 << endl;
}
