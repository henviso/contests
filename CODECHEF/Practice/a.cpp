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

int v[100100];
int h[10], bck[10];
pair< ii, int > g[100100];
int n;
int a;

int main(){
	CLEAR0(h);
	cin >> n;
	REP(i, n){
		cin >> v[i];
		h[v[i]]++;
	}
	int aux[] = {1, 2, 3, 4, 6};
	int cc = 0;
	memcpy(bck, h, sizeof(h));
	do{
		cc = 0;
		
		REP(i, 5){
			REPP(j, i+1, 5){
				REPP(k, j+1, 5){
					int groups = min(min(h[aux[i]],h[aux[j]]), h[aux[k]]);
					int mem[3]; mem[0] = aux[i]; mem[1] = aux[j]; mem[2] = aux[k];
					sort(mem, mem+3);
					
					if(mem[2]%mem[1] != 0 || mem[1]%mem[0] != 0) continue;
					
					REP(z, groups){
						g[cc+z].first.first = mem[0];
						g[cc+z].first.second = mem[1];
						g[cc+z].second = mem[2];
					}
					cc += groups;
					h[aux[i]] -= groups;
					h[aux[j]] -= groups;
					h[aux[k]] -= groups;
				}
			}
		}
		if(cc == n/3) break;
		memcpy(h, bck, sizeof(h));
	} while( next_permutation(aux, aux+5) );
	
	if(cc != (n/3)) cout << "-1" << endl;
	else{
		sort(g, g+cc);
		REP(i, cc){
			printf("%d %d %d\n", g[i].first.first, g[i].first.second, g[i].second);
		}
	}
}
