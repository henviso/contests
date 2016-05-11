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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

char s[100];
int ans[100];

int main(){
	while(1){
		scanf(" %s ", &s[0]);
		if(s[0] == '-') return 0;
		if(s[0] == '0'){ printf("0\n"); continue; }
		int t = strlen(s);
		char *p = strdup(s);
		
		int i = 0, j = 0, x = 0;
		while(1){
			while(x < 9 && i < t){
				x = x*10+(s[i++]-'0');
				if(i > 1 && i < t && x < 9) ans[j++] = 0;
			}
			if(i < t){
				ans[j++] = (x/9);
				//cout << j-1 << " EH " << ans[j-1] << endl;
				x = x%9;
			}
			else break;
		}
		if(x) ans[j++] = (x/9)+(x%9 != 0);
		ans[j] = '\0';
		int c = 0;
		for(int i = j-1; i>=0; i--){
			c += ans[i];
			ans[i] = c%10;
			c /= 10;
		}
		if(c) printf("%d", c);
		REP(i, j) printf("%d", ans[i]);
		printf("\n");
	}
}
