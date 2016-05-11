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
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n, m;
int l[100010], r[100010], q[100010];
int bt[30][100010];
int a[100010];
int ans[100010];

int lg[120000];
int t[120000][17];

void processMin(int M[120000][17], int A[120000], int N){
	int i, j;
	for (i = 0; i < N; i++)
		  M[i][0] = i;
	for (j = 1; 1 << j <= N; j++)
		  for (i = 0; i + (1 << j) - 1 < N; i++)
			  if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
				  M[i][j] = M[i][j - 1];
			  else
				  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}

int rmqMin(int i, int j){
	int k = lg[j - i + 1];
	return min(a[t[i][k]], a[t[j-(1 << k)+1][k]]);
}

int main(){
	cin >> n >> m;
	
	REPP(i, 1, 100001){
		int r = 0, x = i;
		while(x >>= 1) ++r;	
		lg[i] = r;
	}

	CLEAR0(ans);
	bool pos = true;
	REP(i, m){
		cin >> l[i] >> r[i] >> q[i]; l[i]--; r[i]--;
		REP(j, 30) if(q[i]&(1<<j)){
			bt[j][l[i]]++;
			bt[j][r[i]+1]--;
		}
	}
	
	REP(j, 30){
		int x = 0;
		int msk = (1<<j);
		REP(i, n){
			x += bt[j][i];
			a[i] = x;
		}
		REP(i, n){
			if(a[i] > 0){
				ans[i] |= msk;
			}
		}
		processMin(t, a, n);
		REP(i, m){
			if(q[i]&msk);
			else{
				if(rmqMin(l[i], r[i]) > 0){
					pos = false;
					break;
				}
			}
		}
		if(!pos) break;
	}
	if(!pos) cout << "NO\n";
	else{
		cout << "YES\n";
		cout << ans[0];
		REPP(i, 1, n) cout << " " << ans[i];
		cout << endl;
	}
}
