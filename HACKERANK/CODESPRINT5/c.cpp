#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll ans[600];
    vector<int> av(500);
	for(ll i = 1; i<=500; i++){ av[i-1] = i; ans[i] = 0; }
	
	ll mask = 1, x;
	while(mask < (1 << 20)){
		ll p = 1; x = 0;
		for(int k = 0; k<20; k++, p*=10){
			if(mask & (1 << k)) x += p*9;
		}	
		for(int i = 0; i<av.size(); i++){
			if(x%av[i] == 0){
				ans[av[i]] = x;
				av.erase(av.begin()+i);
				i--;	
			}
		}
		if(av.empty()) break;
		mask++;
	}
	
    int t;
    ll n;
    scanf(" %d ", &t);
    while(t--){
        cin >> n;
        cout << ans[n] << endl;
    }
    return 0;
}
