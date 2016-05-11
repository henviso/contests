#include <iostream>
#include <cstdio>
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
#include <cstring>
#include <unistd.h>
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
#define EPS 1e-9
#define MOD 1000000007LL
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

int n;
int l[100100];
int d[100100];
int ac[100100];

vi fq, fc;

priority_queue< ii , vector<ii>, greater<ii> > q();
vector< ii > v;

void ft_create(vi &t, int n){ t.assign(n+1, 0); }

int ft_rsq(const vi &t, int b){
	int sum = 0; for(; b; b -= CHECKFIRST(b)) sum += t[b];
	return sum;
}

int ft_rsq(const vi &t, int a, int b){
	return ft_rsq(t, b) - (a == 1? 0 : ft_rsq(t, a-1)); 
}

void ft_adjust(vi &t, int k, int v){
	for(; k  <= (int)t.size(); k += CHECKFIRST(k)) t[k] += v;
}



int main(){
	scanf(" %d ", &n);
	REPP(i, 1, n+1) scanf(" %d ", &l[i]);
	REPP(i, 1, n+1) scanf(" %d ", &d[i]);
	REPP(i, 1, n+1) v.push_back(ii(l[i], d[i]));
	sort(v.begin(), v.end());
	
	int tot = 0, act = 0;
	ft_create(fq, 100100); ft_create(fc, 100100);
	int ANS = INF; ac[n] = 0;
	for(int i = n-1; i>=0; i--) ac[i] = ac[i+1] + v[i].second;
	REP(i, n){
		int j = i; while(j < n && v[j].first == v[i].first) j++;
		act = j-i; 
		tot += act;
		int rem = max(0, tot - (2*act - 1));
		int hi = 100002, lo = 0, mid, ans = 0;
		while(hi-lo>1){
			mid = (hi+lo)/2;
			if(ft_rsq(fq, 1, mid) >= rem){ ans = mid; hi = mid; }
			else lo = mid;
		}
		int x = ft_rsq(fq, 1, ans) - rem;
		int res = ft_rsq(fc, 1, ans) - x*(ans-1) + ac[j];
		ANS = min(ANS, res);
		REPP(k, i, j){
			int leng = v[k].first;
			int cost = v[k].second;
			ft_adjust(fq, cost+1, 1);
			ft_adjust(fc, cost+1, cost);
		}
		i = j-1;
	}
	printf("%d\n", ANS);
}
