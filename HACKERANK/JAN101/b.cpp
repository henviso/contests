#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007LL

typedef long long ll;

int x, y, d;

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

ll fat[2000100]; 

int main() {
    ll moves, n, m;
    fat[0] = fat[1] = 1LL;
    for(int i = 2; i<=2000000; i++) fat[i] = (fat[i-1]*i)%MOD;
    int t;
    scanf(" %d ", &t);
    while(t--){
        cin >> n >> m;
        moves = (n-1)+(m-1);
        ll ans = (fat[moves]*invMult((fat[n-1]*fat[m-1])%MOD, MOD))%MOD;
        cout << ans << endl;
    }
    return 0;
}
