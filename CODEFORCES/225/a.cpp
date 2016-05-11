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

int n, m, x, y;

vector< ii > voc, voc2;
set< ii > rows[1000000]; 
set< ii > cols[1000000]; 
map< ii, int > h;

map< int, int > rowMap;
map< int, int > colMap;

int ind;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int k = 8, ind = 1;

void processVertex(ii v, bool volc){
	if(h.count(v) == 0){
		h[v] = ind;
		int R = rowMap[v.second];
		int C = colMap[v.first];
		if(volc){
			rows[R].insert(ii(C, -ind));
			cols[C].insert(ii(R, -ind));
		}
		else{
			rows[R].insert(ii(C, ind));
			cols[C].insert(ii(R, ind));
		}
		ind++;
	}
}

void processVolcano(ii x){
	processVertex(x);
	REP(j, k) processVertex(ii(p.first + dx[k], p.second + dy[k]));
}

void makeGraph(){
	for(map< int, int >::iterator it = rowMap.begin(); it != rowMap.end(); it++){
		
	}
}


int main(){
	scanf(" %d %d ", &n, &m);
	REP(i, m){
		scanf("%d %d ", &x, &y);
		voc.push_back(ii(x, y));
		voc2.push_back(ii(y, x));
	}
	vector< ii > voc2 = a;
	sort(voc.begin(), voc.end());
	sort(voc2.begin(), voc2.end());
	int R = 0;
	int C = 0;
	REP(i, m){
		int c = voc[i].first, r = voc2[i].first);
		if(rowMap.count(r) == 0) rowMap[r] = R++;
		if(colMap.count(c)  == 0) colMap[c] = C++;
	}
	REP(i, m) processVolcano(voc[i]);
	makeGraph();
}
