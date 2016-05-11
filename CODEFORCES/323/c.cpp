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
#define EPS 1e-10
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

int n;
map<int, int> cnt;

int gcd(int a, int b) {
  if(a<0) a = -a;
  if(b<0) b = -b;
  if(b == 0)
    return a;
  else
    return gcd(b, a%b);
}

int main(){
	scanf(" %d ", &n);
	int x;
	REP(i, n*n){
		scanf(" %d ", &x);
		cnt[x]++;
	}
	vector< int > ans;
	for(map<int, int>::reverse_iterator it = cnt.rbegin(); it != cnt.rend(); it++){
		x = it->first;
		bool pos = true;
		while(it->second > 0 && ans.size() < n && pos){
			map<int, int> minus;
			for(int j = 0; j<ans.size(); j++){
				//cout << " GCD " << x << " e " << ans[j] << " " << gcd(ans[j], x);
				minus[gcd(ans[j], x)]++;
			}
			//cout << " TEMOS " << it->second << " X E PRECISAMOS DE " << (minus.count(x) == 0) << " ou " << minus[x] << " COMO DIVISORES";
			pos = (minus.count(x) == 0 || it->second > minus[x])? true : false;
			//cout << " POS " << pos << endl;
			for(map<int, int>::iterator jt = minus.begin(); pos && jt != minus.end(); jt++){
				//cout << " AVALIANDO O DIVISOR " << jt->first << " Q APARECE " << jt->second << " VEZES\n";
				if(cnt.count(jt->first) == 0 || cnt[jt->first] < 2*jt->second){
					//cout << " PAROU EM " << jt->first << endl;
					pos = false;
				}
			}
			if(pos){
				//cout << " POS PARA " << x << endl;
				for(map<int, int>::iterator jt = minus.begin(); jt != minus.end(); jt++) cnt[jt->first] -= 2*jt->second;
				cnt[x]--;
				ans.push_back(x);
			}
		}
	}
	printf("%d", ans[ans.size()-1]);
	REPP(i, 1, ans.size()) cout << " " << ans[ans.size()-(i+1)];
	cout << endl;
}
