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
//L[i]=L[i/2]+1;

int n, q;
int pos[1111111];

int main(){
	scanf(" %d %d ", &n, &q);
	int d = 0; 
	int x, y, trocas = 0;
	int pep = true;
	int even = 0, odd = 0;
	REP(i, q){
		scanf(" %d ", &x);
		if(x == 1){
			scanf(" %d ", &y);
			d = (d+y)%n;
			if(d < 0) d += n;
			if(y%2) pep = !pep;
		}
		else if(x == 2){
			if(pep){
				even--;
				odd++;
			}
			else{
				even++;
				odd--;
			}
			pep = !pep;
		}
	}
	even = even %n;
	if(even < 0) even += n;
	odd = odd%n;
	if(odd < 0) odd += n;
	REPP(i, 1, n+1){
		if(i%2) pos[((i - 1 + d + odd)%n)+1] = i;
		else pos[((i - 1 + d + even)%n)+1] = i;
	}
	printf("%d", pos[1]);
	REPP(i, 2, n+1) printf(" %d", pos[i]);
	printf("\n"); 
}
