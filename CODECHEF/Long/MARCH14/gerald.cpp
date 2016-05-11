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
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
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
//__builtin_popcount(m)
//scanf(" %d ", &t);
//ios::sync_with_stdio(false);

vi pset;
vi psize;
vi strength;
int nSets;

void initSet(int N){
	strength.assign(N, 0);
	pset.assign(N, 0);
	psize.assign(N, 1);
	nSets = N;
	for(int i = 0; i<N; i++) pset[i] = i;
}
 
int findSet(int i){
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
 
bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}
 
int unionSet(int i, int j){
	if(isSameSet(i,j)) return psize[findSet(j)];
	nSets--;
	if(psize[findSet(j)] < psize[findSet(i)]) return unionSet(j, i);
	psize[findSet(j)] += psize[findSet(i)];
	pset[findSet(i)] = findSet(j);
	return psize[findSet(j)];
}

ii edges[200100];
ii query[200100];
int n, m, q;

bool cmp(ii a, ii b){
	if(a.second != b.second) return (a.second > b.second);
	return (a.first < b.first);
} 

int main(){
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> q;
		bool(*fn_pt)(ii,ii) = cmp;
		std::set<ii,bool(*)(ii,ii)> queries (fn_pt);
		
		REP(i, m){
			cin >> edges[i].first >> edges[i].second;
			edges[i].first--;
			edges[i].second--;
		}			
		int l, r;
		REP(i, q){
			cin >> query[i].first >> query[i].second;
			query[i].first--;
			query[i].second--;
			queries.insert(query[i]);
		}
		
		bool finish = false;
		while(!finish){
			initSet(n);
			
			
		}
	}
}
