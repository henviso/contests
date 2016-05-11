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

bitset<1000100> sq;

int n, k;

int main(){
	int h, m;
	while(scanf(" %d:%d ", &h, &m) != EOF){			
		cout << " ____________________________________________\n";
		cout << "|                                            |\n";
		cout << "|    ____________________________________    |_\n";
		cout << "|   |                                    |   |_)\n";
		cout << "|   |   8         4         2         1  |   |\n";
		cout << "|   |                                    |   |\n";
		cout << "|   |   ";
		for(int i = 3; i>=0; i--){
			if(h&(1 << i)) cout << "o";
			else cout << " ";
			if(i) cout << "         ";
		}
		cout << "  |   |\n";
		cout << "|   |                                    |   |\n";
		cout << "|   |                                    |   |\n";
		cout << "|   |   ";
		for(int i = 5; i>=0; i--){
			if(m&(1 << i)){
				if(i >= 4) cout << "o ";
				else cout << "o";
			}
			else{
				if(i >= 4) cout << "  ";
				else cout << " ";
			}
			if(i){
				if(i >= 4) cout << "    ";
				else cout << "     ";
			}
		}
		cout << "  |   |\n";
		cout << "|   |                                    |   |\n";
		cout << "|   |   32    16    8     4     2     1  |   |_\n";
		cout << "|   |____________________________________|   |_)\n";
		cout << "|                                            |\n";
		cout << "|____________________________________________|\n";
		cout << endl;
	}
}

