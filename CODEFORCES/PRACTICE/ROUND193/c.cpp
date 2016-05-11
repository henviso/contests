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
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//scanf(" %d ", &t);

ll a[200100], b[200100];
int n, p, k;
int m;

bool cmp(pair<ll, int> a, pair<ll, int> b){
	if(a.first != b.first) return a.first > b.first;
	return a.first < b.first; 
}

int main(){
	cin >> n >> p >> k;
	REPP(i, 1, n+1) cin >> a[i] >> b[i];
	
	m = p-k;
	
	vector< pair<ll, int> > dir;
	REPP(i, 1, n+1) dir.pb(mp(b[i], i));
	sort(ALL(dir), cmp);
	
	vector< pair<ll, int> > chair;
	REP(i, n){
		chair.pb(mp(a[dir[i].second], i));
		//cout << " PAR " << a[dir[i].second] << " E " << i << endl;
	}
	sort(ALL(chair), cmp);
	
	bitset<200000> c; c.reset();
	int chosen = 0, ans[200000];
	
	//cout << "CHAIR SIZE " << chair.size() << endl;
	
	REP(i, chair.size()){
		int ind = chair[i].second;
		//cout << " I EH " << i << " CHAIR[i] " << chair[i].first << " " << chair[i].second << endl;
		if(ind < n-m){ //VAI SER ESC
			ans[chosen] = dir[ind].second;
			c[ans[chosen++]] = true;
			//cout << " TAREFA ESCOLHIDA " << ans[chosen-1] << endl;
		}
		if(chosen == k){
			if(i+1 == chair.size() || chair[i+1].first < chair[i].first) break;
			
			//cout << " EH CONTINOU AKI " << endl;
			
			int v = chair[i].first;
			int esc = 0; 
			while(chosen >= 0 && a[ans[chosen]] == v){
				c[ans[chosen]] = false;
				chosen--;
				esc++;
				i--;
			}
			i++;
			int j = i+1; while(j<chair.size() && chair[j].first == v) j++;
			REPP(z, i, j){
				chair[z].first = dir[chair[z].second].first;
				chair[z].second = dir[chair[z].second].second;
			}
			sort(chair.begin()+i, chair.begin()+j);
			while(chosen < k){
				ans[chosen] = chair[i].second;
				c[chair[i].second] = true;
				chosen++; i++;
			}
			break;
		}
	}
	ll lima = a[ans[chosen-1]];
	ll limb = 2000000000;
	REP(i, chosen) limb = min(limb, b[ans[i]]);
	
	REP(i, dir.size()){
		if(chosen == p) break;
		int ind = dir[i].second;
		//cout << " IND EH " << ind << endl;
		if(c[ind]){
			//cout << "ESCOLHIDO " << endl;
			continue;
		}
		
		if(b[ind] >= limb){
			if(b[ind] == limb && a[ind] >= lima){
				ans[chosen++] = ind;
				c[ind] = true;
				continue;
			}
			//cout << " DESC DE DIR EH " << b[ind] << " LIMA EH " << lima << " LIMB EH " << limb << endl;
			//cout << " A " << a[ind] << " B " << b[ind] << endl;
			continue;
		}
		ans[chosen++] = ind;
		c[ind] = true;
		//cout << " P EH " << p << endl;
	}
	
	REP(i, dir.size()){
		if(chosen == p) break;
		int ind = dir[i].second;
		//cout << " IND EH " << ind << endl;
		if(c[ind]){
			//cout << "ESCOLHIDO " << endl;
			continue;
		}
		if(b[ind] > limb){
			//cout << " DESC DE DIR EH " << b[ind] << " LIMA EH " << lima << " LIMB EH " << limb << endl;
			//cout << " A " << a[ind] << " B " << b[ind] << endl;
			continue;
		}
		ans[chosen++] = ind;
		c[ind] = true;
		//cout << " P EH " << p << endl;
	}
	//cout << "CHOSEN EH " << chosen << endl;
	cout << ans[0];
	REPP(i, 1, chosen){
		cout << " " << ans[i];
	}
	cout << endl;
}
