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
//__builtin_popcount(m)
//scanf(" %d ", &t);
//L[i]=L[i/2]+1;

int t;
char s[1000100];
int b[1000100];

int main(){
	scanf(" %d ", &t);
	while(t--){
		scanf(" %s ", s);
		int tam = strlen(s);
		REP(i, tam){
			if(s[i] == 'G') s[i] = 'A';
			else if(s[i] == 'T') s[i] = 'C';
		}
		s[tam++] = 'C';
		int block = 0, p = 0;
		int as = 0, cs = -1;
		REP(i, tam){
			if(s[i] == 'A'){
				as++;
				block++;
			}
			else{
				b[p++] = block;
				block = 0;
				cs++;
			}
		}
		int bw = 0, ls = 0;
		int puri = 0, pyri = 0;
		REP(i, p-1){
			if(b[i] == 0 && i > 0){
				int w = b[i-1] + b[i+1];
				int l = b[i-1] + b[i+1] + 2;
				if(w > bw || (w == bw && l > ls)){
					bw = w;
					ls = l;
					puri = b[i-1] + b[i+1];
					pyri = 2;
				}
			}
			int w = 2*(b[i]+b[i+1]);
			int l = b[i]+b[i+1]+1;
			if(w > bw || (w == bw && l > ls)){
				bw = w;
				ls = l;
				puri = b[i]+b[i+1];
				pyri = 1;
			}
		}
		if(as == 0 || cs == 0) printf("%d %d\n", as, cs);
		else printf("%d %d\n", puri, pyri); 
	}
	
}
