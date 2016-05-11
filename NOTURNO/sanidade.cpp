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

map< ull, ull > nxt;
map< ull, ull > prev;
ull ptr1, ptr2, a, p, n; 
vector< ull > path1;
vector< ull > path2;

ull val[256];
set<ull> vis;
	
char A[50], P[50], N[50];

ull convert(char *x){
	int t = strlen(x);
	ull p = 1ULL;
	ull ans = 0ULL;
	REP(i, t){
		ans += val[x[t-1-i]] * p;
		p *= 16ULL;
	}
	return ans;
}

int main(){
	REP(i, 10) val['0'+i] = ((ull) i);
	REP(i, 7) val['a'+i] = 10ULL + ((ull) i);
	int id = 0;
	while(scanf(" %s %s %s ", &A[0], &P[0], &N[0]) != EOF){
		a = convert(&A[0]); 
		p = convert(&P[0]);
		n = convert(&N[0]);
		prev[a] = p;  nxt[a] = n;
		if(id == 0) ptr1 = a;
		else if(id == 1) ptr2 = a;
		id++;
	}
	
	vis.clear();
	path1.push_back(ptr1);
	vis.insert(ptr1);
	a = path1[path1.size()-1];
	n = nxt[a];
	while(n != 0){
		path1.push_back(n);
		if(vis.count(n) || n == ptr2) break;
		vis.insert(n);
		a = path1[path1.size()-1];
		n = nxt[a];
	}
	
	vis.clear();
	path2.push_back(ptr2);
	vis.insert(ptr2);
	a = path2[path2.size()-1];
	n = prev[a];
	while(n != 0ULL){
		path2.push_back(n);
		if(vis.count(n) || n == ptr1) break;
		vis.insert(n);
		a = path2[path2.size()-1];
		n = prev[a];
	}
	
	bool sane = true;
	if(path1.size() != path2.size()){
		sane = false;
	}
	else{
		int t = path1.size();
		REP(i, t){
			if(path1[i] != path2[t-1-i]) sane = false;
		}
	}
	
	if(sane) printf("sana\n");
	else printf("insana\n");
}

