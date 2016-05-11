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

typedef long long unsigned hash;

#define MAXS 2
#define MAXN 10100
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXS][MAXN];
char str[MAXS][MAXN];
int t[MAXS], n;

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
	REP(i, n){
		p[i][0] = 0ULL;
		REP(j, t[i]){
			p[i][j+1] = p[i][j]*B + str[i][j];
		}
	}
}

void print(int e, int a, int b){
	for(int i = a; i<=b; i++){
		printf("%c", str[e][i]);
	}
}

hash calc_dhash(int e, int a, int b) {
	if (a > b) return 0;
	return p[e][b+1] - p[e][a] * power[b - a + 1];
}

int main(){
	cin.getline(str[0], MAXN); t[0] = strlen(str[0]);
	cin.getline(str[1], MAXN); t[1] = strlen(str[1]);
	n = 2;
	precalc();
	int ans = -1;
	int lower = 0;
	if(t[1] < t[0]) lower = 1-lower;
	int other = 1-lower;
	
	//cout << " LOWER " << str[lower] << endl;
	//cout << " OTHER " << str[other] << endl;
	
	REPP(k, 1, t[lower]+1){
		tr1::unordered_map< ll, int > oc[2];
		REP(i, t[0]-(k-1)){
			int l = i, r = i+k-1;
			ll h = calc_dhash(lower, l, r);
			oc[lower][h]++;
			//cout << " OC NO LOWER DE "; print(lower, l, r); cout << " HASH " << h;
			//cout << " " << oc[lower][h] << " INDICES " << l << " ATE " << r << endl;
		}
		int cnt = 0; 
		REP(i, t[other]-(k-1)){
			int l = i, r = i+k-1;
			ll h = calc_dhash(other, l, r);
			if(oc[lower].count(h) && oc[lower][h] == 1){
				int x = ++oc[other][h];
				if(x == 1) cnt++;
				else if(x == 2) cnt--;
				//cout << " OC NO OUTRO DE "; print(other, l, r);
				//cout << " " << oc[other][h] << endl;
			}
		}
		if(cnt > 0){
			ans = k;
			break;
		}
		if(ans != -1) break;
	}
	cout << ans << endl;
}

