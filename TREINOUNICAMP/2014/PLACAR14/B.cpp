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

vi A, B, C;
vi D, E, F, G, H;

vi g[2100];
int col[2100];
bool pos;
bitset<2100> vis;

void biCol(int s, int c){
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

void filterEdges(vi &a){
	REP(i, a.size())
	REPP(j, i+1, a.size())
	if(!M[a[i]][a[j]]){
		if(vis[a[i]]){
			if(vis[a[j]]){
				//cout << "DOIS VISITADOS CONFLITANDO " << a[i] << " E " << a[j] << endl;
				pos = false;
			}
			else{
				vis[a[j]] = true;
				C.push_back(a[j]);
				a.erase(a.begin()+j);
				j--;
				continue;
			} 
		}
		else{
			if(vis[a[j]]){
				vis[a[i]] = true;
				C.push_back(a[i]);
				a.erase(a.begin()+i);
				i--;
				break;
			}
		}
	}
}

void filterBetweenSets(vi &a, vi &b, vi &c){
	REP(i, a.size())
	REPP(j, i+1, a.size()){
		if(!M[a[i]][a[j]]){		
			//cout << "NAO ARESTA " << a[i] << " " << a[j] << endl;
			REP(k, b.size()){
				//cout << " K " << b[k] << " VIS " << vis[b[k]] << endl;
				if(!vis[b[k]] && !M[a[i]][b[k]] && !M[a[j]][b[k]]){
					vis[b[k]] = true;
					c.push_back(b[k]);
				}
			}
		}
	}
}

bool isClique(vi &v){
	REP(i, v.size()) REPP(j, i+1, v.size()) if(!M[v[i]][v[j]]) return false;
	return true;
}

void print(vi &X, vi &Y){
	if(!Y.empty()){
		printf("%d", X[0]);
		REPP(i, 1, X.size()) printf(" %d", X[i]);
		printf("\n");
	}
	if(!Y.empty()){
		printf("%d", Y[0]);
		REPP(i, 1, Y.size()) printf(" %d", Y[i]);
		printf("\n");
	}
}

int main(){
	
	while(scanf(" %d %d ", &n, &m) != EOF){
		CLEAR0(M);
		A.clear();
		B.clear();
		C.clear();
		D.clear();
		E.clear();
		CLEAR(col, -1);
		REPP(i, 1, n+1) g[i].clear();
		pos = true;
		vis.reset(); vis[1] = vis[2] = true;
		
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
			//cout << "LALLA\n";
			if(isClique(C)) print(A, B);
			else printf("impossible\n");
		}
		else{ 
			//alfa(G) > 2 -> G must be perfect -> G \ {1, 2} is biCol
			//print(A, B);
			
			
			A.erase(A.begin());
			B.erase(B.begin());
			D.push_back(1);
			E.push_back(2);
			
			REP(i, C.size()){
				REP(j, A.size()) if(!M[C[i]][A[j]]){
					vis[A[j]] = true;
					D.push_back(A[j]);
				}
				REP(j, B.size()) if(!M[C[i]][B[j]]){
					vis[B[j]] = true;
					E.push_back(B[j]);
				}
			}
			
			
			filterBetweenSets(A, B, E);
			filterBetweenSets(B, A, D);
			
			filterEdges(A);
			filterEdges(B);
			
			
			
			//print(A, B);
			//print(D, E);
			//print(C, C);
			//print(A, B);
			//print(C, C);
			
			//while(filterWithVis(A, D, C));
			//while(filterWithVis(B, E, C));
			
			//print(D, C);
			
			REP(i, C.size()) vis[C[i]] = true;
			
			
			
			REPP(i, 3, n+1)
			REPP(j, i+1, n+1){
				if(!vis[i] && !vis[j] && !M[i][j]){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
			
			REPP(i, 1, n+1) if(!vis[i] && col[i] == -1) biCol(i, 0);
			REPP(i, 1, n+1) cout << i << " COR " << col[i] << endl;
			
			if(pos){
				//print(A, B);
				F = D; G = E; H = C;
				REP(i, A.size()){
					if(col[A[i]] == 0) D.push_back(A[i]);
					else if(col[A[i]] == 1) C.push_back(A[i]);
				}
				REP(i, B.size()){
					if(col[B[i]] == 0) E.push_back(B[i]);
					else if(col[B[i]] == 1) C.push_back(B[i]);
				}
				filterEdges(D);
				filterEdges(E);
				//cout << " POS " << pos << endl;
				//print(D, E);
				//print(E, C);
			
				if(pos && isClique(D) && isClique(E) && isClique(C)){
					sort(D.begin(), D.end());
					sort(E.begin(), E.end());
					sort(C.begin(), C.end());
					print(D, E);
				}
				else{
					pos = true;
					D = F; E = G; C = H;
					REP(i, A.size()){
						if(col[A[i]] == 1) D.push_back(A[i]);
						else if(col[A[i]] == 0) C.push_back(A[i]);
					}
					REP(i, B.size()){
						if(col[B[i]] == 1) E.push_back(B[i]);
						else if(col[B[i]] == 0) C.push_back(B[i]);
					}
					filterEdges(D);
					filterEdges(E);
					if(pos && isClique(D) && isClique(E) && isClique(C)){
						sort(D.begin(), D.end());
						sort(E.begin(), E.end());
						sort(C.begin(), C.end());
						print(D, E);
					}
					else printf("impossible\n");
				}
			}
			else cout << "impossible\n";
		}
	}
}
