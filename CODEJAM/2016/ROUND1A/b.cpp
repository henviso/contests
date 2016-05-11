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
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-40
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
//L[i]=L[i/2]+1;

int t, n;
int cnt[3000][100];
vector< vi > a;
int idx[100];
ll used;
bool found = false;
vi ans;

bool myfunction (vi i, vi j) { 
	return (i[0] < j[0]); 
}

bool valid(ll used){
	int missing = -1;
	REP(j, n){
		int r = -1;
		REP(i, 2*n-1) if(a[i][0] == a[idx[0]][j] && (used&(1LL << i)) == 0) r = i;
		if(r > -1){
			//cout << " A COLUNA " << j << " EH " << r << endl;
			REPP(i, 1, n) if(a[idx[i]][j] != a[r][i]){ 
				//cout << " FALSOOOO\n";
				return false;
			}
		}
		else{
			if(missing == -1){ 
				missing = j; 
				//cout << " MISSING EH " << missing << endl; 
			}
			else return false;
		}	
	}
	REP(i, n) ans.push_back(a[idx[i]][missing]);
	return true;
}

void bt(ll used, int row, int lst, int c){
	if(c == n){
		if(valid(used)){
			found = true;
			//cout << " DEU COM USED " << used <<  endl;
		}
		//else cout << " NAO EH VALIDO O USED " << used << endl;
		return;
	}
	if(row == 2*n-1) return;
	
	if(a[row][0] > lst){
		idx[c] = row; 
		bt(used | (1LL << row), row+1, a[row][0], c+1);
		if(found) return;
	}
	bt(used, row+1, lst, c);
}


int main(){
	cin >> t;
	for(int tc = 1; tc<=t; tc++){
		cin >> n;
		CLEAR0(cnt);
		a.clear();
		REP(i, 2*n-1){
			vi x; int y;
			REP(j, n){ cin >> y; x.push_back(y); } 
			a.push_back(x);
		}
		sort(a.begin(), a.end(), myfunction);
		/*
		REP(i, 2*n-1){
			REP(j, n) cout << a[i][j] << " ";
			cout << endl;
		}*/
		CLEAR0(idx);
		ans.clear();
		found = false;
		bt(0LL, 0, -1, 0);
		cout << "Case #" << tc << ":";
		REP(i, ans.size()) cout << " " << ans[i];
		cout << endl;
		
	}
}
