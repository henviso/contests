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
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)
#define pb push_back
#define pf push_front
#define sz size()
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
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

int n, m;
int M[2100][2100];

vi A, B, C, D, E;

vi g[2100];
int col[2100];
bool pos, filtered;
bitset<2100> vis;

void biCol(int s, int c){
	//cout << " S " << s << " C " << c << endl;
	if(col[s] == -1){
		col[s] = c;
		REP(k, g[s].size()){
			int v = g[s][k];
			biCol(v, 1-c);
		}
	}
	else{
		if(col[s] != c){
			//cout << "PROBLEMA NA COLORACAO\n";
			pos = false;
		}
		return;
	}
}

void filterBetweenSets(vi &a, vi &b, vi &c){
	REP(i, a.size())
	REPP(j, i+1, a.size()){
		if(!M[a[i]][a[j]]){		
			//cout << "NAO ARESTA " << a[i] << " " << a[j] << endl;
			REP(k, b.size()){
				//cout << " VERTICE K " << b[k] << " VIS " << vis[b[k]] << endl;
				if(!M[a[i]][b[k]] && !M[a[j]][b[k]]){
					//cout << "RETIROU \n";
					vis[b[k]] = true;
					c.push_back(b[k]);
					b.erase(b.begin() + k);
					k--;
				}
			}
		}
	}
}

void filterWith(vi &a, vi &b, vi &c){
	REP(i, b.size()){
		REP(j, a.size()){	
			int u = b[i], v = a[j];
			if(!M[u][v]){
				vis[v] = true;
				c.push_back(v);
				a.erase(a.begin()+j);
				j--;
				filtered = true;
			}
		}
	}
}

bool isClique(vi &v){
	REP(i, v.size()) REPP(j, i+1, v.size()) if(!M[v[i]][v[j]]) return false;
	return true;
}

void print(vi &X, vi &Y){
	if(!X.empty()){
		printf("%d", X[0]);
		REPP(i, 1, X.size()) printf(" %d", X[i]);
		printf("\n");
	}
	//printf("line\n");
	if(!Y.empty()){
		printf("%d", Y[0]);
		REPP(i, 1, Y.size()) printf(" %d", Y[i]);
		printf("\n");
	}
}

vi uniao(vi &a, vi &b){
	vi ans;
	REP(i, a.size()) ans.push_back(a[i]);
	REP(i, b.size()) ans.push_back(b[i]);
	return ans;
}

vi uniao(vi &a, vi &b, vi &c){
	vi ans;
	REP(i, a.size()) ans.push_back(a[i]);
	REP(i, b.size()) ans.push_back(b[i]);
	REP(i, c.size()) ans.push_back(c[i]);
	return ans;
}

int main(){
	
	while(scanf(" %d %d ", &n, &m) != EOF){
		CLEAR0(M);
		A.clear();
		B.clear();
		C.clear();
		D.clear();
		E.clear();
		
		int u, v;
		REP(i, m){
			scanf(" %d %d ", &u, &v);
			M[u][v] = M[v][u] = 1;
		}
		A.push_back(1);
		B.push_back(2);
		REPP(i, 3, n+1){
			if(M[i][1]) A.push_back(i);
			else if(M[i][2]) B.push_back(i);
			else{
				C.push_back(i);
			}
		}
		if(isClique(A) && isClique(B)){
			if(isClique(C)) print(A, B);
			else printf("impossible\n");
		}
		else{ 
			//alfa(G) > 2 -> G must be perfect -> G \ {1, 2} is biCol
			//print(A, B);
			//print(C, C);
			CLEAR(col, -1);
			REPP(i, 1, n+1) g[i].clear();
			pos = true;
			vis.reset(); vis[1] = vis[2] = true;
		
			A.erase(A.begin());
			B.erase(B.begin());
			D.push_back(1);
			E.push_back(2);
			
			vi auxA = A, auxB = B;
			
			//cout << " B filtrando com auxA colocando em E\n";
			//print(B, auxA);
			//print(E, E);
			filterBetweenSets(auxA, B, E);
			//cout << "filtrado\n";
			//print(B, E);
			
			//cout << " A filtrando com auxB colocando em D\n";
			//print(A, auxB);
			//print(D, D);
			filterBetweenSets(auxB, A, D);
			//cout << "filtrado\n";
			//print(A, D);
			
			do{
				filtered = false;
				filterWith(A, D, C);
				filterWith(B, E, C);
				filterWith(A, C, D);
				filterWith(B, C, E);
				if(!isClique(D) || !isClique(E) || !isClique(C)){
					pos = false;
					break;
				}
			}while(filtered);
			
			//cout << " A E B ANTES DE FILTRAR\n";
			//print(A, B);
			//cout << " FILTRANDO COM C\n";
			//print(C,C);
			//cout << " A E B filtrado\n";
			
			//print(A, B);
			//cout << " C " << endl;
			//print(C, C);
			
			//cout << " D e E\n";
			//print(D, E);
			
			REP(i, C.size()) vis[C[i]] = true;
			REPP(i, 3, n+1)
			REPP(j, i+1, n+1){
				if(!vis[i] && !vis[j] && !M[i][j]){
					//cout << " COLOCANDO ARESTAS ENTRE " << i << " E " << j << endl;
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
			
			//cout << " D e E sem coloridos\n";
			//print(D, E);
			//print(C, C);
			
			REPP(i, 1, n+1) if(!vis[i] && col[i] == -1) biCol(i, 0);
			
			//REPP(i, 1, n+1) cout << i << " COR " << col[i] << endl;
			
			vi brancoA, pretoA;
			REP(i, A.size()){
				if(col[A[i]] == 0) brancoA.push_back(A[i]);
				else if(col[A[i]] == 1) pretoA.push_back(A[i]);
			}
			
			vi brancoB, pretoB;
			REP(i, B.size()){
				if(col[B[i]] == 0) brancoB.push_back(B[i]);
				else if(col[B[i]] == 1) pretoB.push_back(B[i]);
			}
			
			vi arya = uniao(D, brancoA);
			vi sansa = uniao(E, brancoB);
			vi dayne = uniao(C, pretoA, pretoB);
			
			if(isClique(arya) && isClique(sansa) && isClique(dayne)){
				sort(arya.begin(), arya.end());
				sort(sansa.begin(), sansa.end());
				print(arya, sansa);   
			}
			else{
				arya = uniao(D, pretoA);
				sansa = uniao(E, pretoB);
				dayne = uniao(C, brancoA, brancoB);
				if(isClique(arya) && isClique(sansa) && isClique(dayne)){
					sort(arya.begin(), arya.end());
					sort(sansa.begin(), sansa.end());
					print(arya, sansa);   
				}
				else printf("impossible\n");
			}	
		}
	}
}
