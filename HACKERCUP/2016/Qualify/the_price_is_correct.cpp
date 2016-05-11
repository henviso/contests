#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
typedef long long ll;
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)

int t, n;
ll P, ac[100100];

ll sum(int l, int r){
	if(l > r) swap(l, r);
	return ac[r] - ac[l-1];
}

int main(){
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> n >> P;
		ll x;
		ac[0] = 0LL;
		REPP(i, 1, n+1){
			cin >> x;
			ac[i] = ac[i-1] + x;
		}
		ll ans = 0LL;
		REPP(i, 1, n+1){
			if(sum(i, i) > P) continue;
			int hi = n+1, lo = i, mid, lm = i; 
			while(hi-lo > 1){
				mid = (hi+lo)/2;
				if(sum(i, mid) <= P){
					lm = mid;
					lo = mid;
				}
				else hi = mid;
			}
			ans += (ll) (lm-i+1);
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
}

