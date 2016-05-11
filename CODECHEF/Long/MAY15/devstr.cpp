#include <iostream>
#include <cstdio>
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
#include <cstring>
#include <unistd.h>
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
#define EPS 10e-20
//__builtin_popcount(m)
//scanf(" %d ", &t);

int t;
int n, k;
char s[100100];
int ac[100100];

void troca(int x){
	if(s[x] == '1') s[x] = '0';
	else s[x] = '1';
}

int main(){
    scanf(" %d ", &t);
    while(t--){
		scanf(" %d %d ", &n, &k);
		scanf(" %s ", &s[1]);
		int ans = 0;
		if(k == 1){
			int a = 0, b = 0;
			REPP(i, 1, n+1){
				if((i%2) == 1) a += (s[i] == '1');
				else a += (s[i] == '0');
			}
			REPP(i, 1, n+1){
				if((i%2) == 1) b += (s[i] == '0');
				else b += (s[i] == '1');
			}
			printf("%d\n", min(a,b));
			if(a < b){
				REP(i, n){
					if(i%2 == 0) printf("0");
					else printf("1");
				}
			}
			else{
				REP(i, n){
					if(i%2 == 0) printf("1");
					else printf("0");
				}
			}
			printf("\n");
		}
		else{
			ans = 0;
			CLEAR0(ac);
			for(int i = n; i>=1; i--){
				if(s[i] == s[i+1]) ac[i] = ac[i+1]+1;
				else ac[i] = 1;
			}
			REPP(i, 1, n+1){
				//cout << " I EH " << i << " AC " << ac[i] << endl;
				int j = i+k;
				int inc = ac[i]-1;
				while(j < i+ac[i]){
					if(j+1 == i+ac[i]){ 
						j--;
					}
					troca(j);
					ans++;
					j += k+1;
				}
				i += inc;
			}
			printf("%d\n%s\n", ans, &s[1]);
		}
	}
}
