#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)

using namespace std;

#define MAXN 10100
#define B 33ULL
#define C 5381ULL



class PalindromicSubstringsDiv2 {
	public:
	
	string s;
	long long unsigned power[MAXN];
	long long unsigned p[MAXN];
	long long unsigned r[MAXN];
	
	void precalc(){
		power[0] = 1ULL;
		REPP(i, 1, MAXN) power[i] = power[i-1]*B;
		p[0] = r[s.size()+1] = 0ULL;
		REP(j, s.size()){
			p[j+1] = p[j]*B + s[j];
		}
		for(int j = s.size()-1; j>=0; j--) r[j+1] = p[j+2]*B + s[j]; 
	}
	
	long long unsigned calc_dhash(int a, int b) {
		if(a > b) return 0;
		return p[b+1] - p[a] * power[b - a + 1];
	}
	
	long long unsigned calc_rhash(int a, int b) {
		if(a > b) return 0;
		return p[a+1] - p[b+2] * power[b - a + 1];
	}
	
	bool pal(int a, int b){
		int n = b-a+1;
		return (calc_dhash(a, a+(n/2-1)) == calc_rhash(b-(n/2-1), b));
	}
	
	int count(vector <string> S1, vector <string> S2) {
		s = "";
		REP(i, S1.size()) s += S1[i];
		REP(i, S2.size()) s += S2[i];
		
		precalc();
		int ans = 0;
		REP(i, s.size()){
			REPP(j, i, s.size()){
				ans += pal(i, j);
			}
		}
		return ans;
	}
};
