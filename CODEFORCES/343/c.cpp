#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>

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
#define MOD 1000000007LL

int n, m;
string s;
ll pd[2222][2222];

int main(){
	CLEAR0(pd);
	pd[0][0] = 1LL;
	REPP(l, 1, 2001){
		REP(r, l+1){
			if(l > r) pd[l][r] = (pd[l][r] + pd[l-1][r])%MOD;
			if(r) pd[l][r] = (pd[l][r] + pd[l][r-1])%MOD;
		}
	}
	
	while(cin >> n >> m >> s){
		ll ans = 0LL;
		int d = n-m;
		int score = 0, mn = s.length();
		REP(i, s.length()){
			if(s[i] == '(') score++;
			else score--;
			mn = min(score, mn);
		}
		REP(p, d+1){
			int q = d-p;
			REP(l, p+1){
				int r = p-l;
				int nscore = score + l - r;
				if(l < r || mn + l - r < 0 || q < nscore || ((q-nscore)%2)) continue;
				int x = (q-nscore)/2;
				ans = (ans + (pd[l][r] * pd[x+nscore][x])%MOD)%MOD;  
			}
		}
		cout << ans << endl;
	}
	
}
