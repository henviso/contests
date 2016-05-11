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

ll laws[200100];
ll s[200100];
ll bf[200100];

int n, k;

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
	if(a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

ll sum(int a, int b){
	if(b < a) return 0LL;
	return s[b] - s[a-1];
}

int main(){
	cin >> n >> k;
	laws[0] = 0LL;
	REPP(i, 1, n+1){
		cin >> laws[i];
		s[i] = s[i-1] + laws[i];
	}
	CLEAR0(bf);
	
	ll best = -1;
	for(int i = n; i>0; i--){
		if(i+k-1 > n) continue;
		ll tseg = sum(i, i+k-1);
		//cout << " i " << i << " tseg " << tseg << endl;
		if(tseg >= best){
			bf[i] = i;
			best = tseg;
		}
		else bf[i] = bf[i+1];
	}
	
	int a, b;
	best = -1;
	REPP(i, 1, n+1){
		//cout << " i " << i << " bf " << bf[i+k] << endl; 
		if(i+k-1 > n || bf[i+k] == 0) continue;
		ll tseg = sum(i, i+k-1) + sum(bf[i+k], bf[i+k]+k-1);
		if(tseg > best){
			a = i;
			b = bf[i+k];
			best = tseg;
		}
	}
	cout << a << " " << b << endl;
}
