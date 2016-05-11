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

int n;
bool ans[2000][2000];

int main(){
	cin >> n;
	
	CLEAR0(ans);
	
	int label = 3, maxpath = 1;
	int x = n, d;
	while(x){
		x /= 10;
		maxpath++;
	}	
	x = n;
	int k = 0;
	while(x){
		d = x%10;
		if(d){
			REP(z, d){ 
				ans[1][label] = ans[label][1] = true; 
				label++;
			}
			int t = k, lst = d, v;
			REP(i, maxpath-2){
				if(t <= 0) v = 1;
				else v = 10;
				REP(z, v){
					REP(zz, lst) ans[label][label-(z+1+zz)] = ans[label-(z+1+zz)][label] = true;
					label++;
				}
				lst = v;
				t--;
			}
			
			REP(z, lst) ans[2][label-(z+1)] = ans[label-(z+1)][2] = true; 
			
		}
		x /= 10;
		k++;
	}
	printf("1000\n");
	REPP(i, 1, 1001){
		REPP(j, 1, 1001){
			if(ans[i][j]) printf("Y");
			else printf("N");
		}
		printf("\n");
	}
}
