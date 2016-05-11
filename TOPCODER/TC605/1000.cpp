#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>

#define ALL(x) (x).begin(),x.end()
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define MOD 1000000007LL
typedef long long ll;

using namespace std;

class AlienAndSetDiv2 {
	public:
	ll x, y, d;
	ll fat[200];
	
	void extendedEuclid(int a, int b){
		if(b == 0){ x = 1; y = 0; d = a; return; }
		extendedEuclid(b, a%b);
		int x1 = y;
		int y1 = x - (a/b) * y;
		x = x1;
		y = y1;
	}

	ll invMult(ll a, ll m){
		extendedEuclid(a, m);
		if(x < 0) x += m;
		return x;
	}
	
	ll comb(ll n, ll p){
		if(p > n) return 0LL;
		return (fat[n] * invMult( (fat[n-p] * fat[p])%MOD, MOD))%MOD;
	}
	
	
	int getNumber(int N, int K) {
		
		fat[0] = fat[1] = 1LL;
		REPP(i, 2, 2*N+1) fat[i] = (fat[i-1]*i)%MOD;
		
		ll cnt[200]; CLEAR0(cnt);
		ll ans = 0LL, M = min(2*N, 2*K), lft = 2*N-M;
		int l = (1 << M);
		REP(m, l){
			int a = 0, b = 0;
			int fa = 100000, fb = 10000;
			REP(k, M){
				if(m&(1 << k)){
					a++;
					fa = min(fa, k);
				}
				else{
					b++;
					fb = min(fb, k);
				}
			} 
			cout << " m " << m << " a " << a << " b " << b << " fa " << fa << " fb " << fb << endl;
			if(abs(fa-fb) <= K) cnt[a]++;
			cout << "cnt " << a << " EH " << cnt[a] << endl;
		} 
		
		cout << " M EH " << M << endl;
		
		REP(i, N+1){
			cout << " I EH " << i << endl;
			cout << "lft " << lft << " N-i " << N-i << " CNT " << cnt[i] << " COMB " << comb(lft, N-i) << endl;
			ans = (ans + (cnt[i] * comb(lft, N-i))%MOD)%MOD; 
			cout << "ans " << ans << endl;
		}
		return ans;
	}
};
