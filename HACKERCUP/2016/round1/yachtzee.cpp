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
typedef pair<ll,ll> pll;
typedef vector< ii > vii;
typedef vector< ll > vll;
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

ll t, n, A, B;
ll c[200000];

double interSize(ll a, ll b, ll c, ll d){
	if(a > b) swap(a, b);
	if(c > d) swap(c, d);
	if(b <= c || d <= a) return 0.0;
	return (double) (min(b, d) - max(a, c)); 
}

double interGrade(ll a, ll b, ll c, ll d){
	if(a > b) swap(a, b);
	if(c > d) swap(c, d);
	if(b <= c || d <= a) return 0.0;
	if(a <= c && b >= d) return (double) ((d-c)/2.0);
	if(c <= a && d >= b) return (double) (a - c + (b - a)/2.0);
	if(a < c) return (double) ((b-c)/2.0);
	return (double) (a - c + (d - a)/2.0);
}


int main(){
	cin >> t;
	REPP(tc, 1, t+1){
		cin >> n >> A >> B;
		REP(i, n) cin >> c[i];
		double ans = 0.0;
		double full = 0.0;
		ll fullTurn = 0LL;
		ll ac = 0LL;
		REP(i, n){		
			double ad = interSize(ac, ac+c[i], ac, ac+c[i]) * interGrade(ac, ac+c[i], ac, ac+c[i]);
			full += ad;
			fullTurn += c[i];
		}
		ll x = A/fullTurn;
		ac = x*fullTurn;
		REP(i, n){ 
			double ad = interSize(A, B, ac, ac+c[i]) * interGrade(A, B, ac, ac+c[i]);
			ans += ad;
			ac += c[i];
		}
		if(B > ac){
			ll left = B-ac, turns = (left)/fullTurn;
			ans += turns*full;
			ac += turns*fullTurn;
			if((left%fullTurn)>0LL){
				REP(i, n){ 
					double ad = interSize(A, B, ac, ac+c[i]) * interGrade(A, B, ac, ac+c[i]);
					ans += ad;
					ac += c[i];
				}
			}
		}
		if(B!=A) ans /= ((double) (B-A));
		printf("Case #%d: %.10lf\n", tc, ans);
	}
}

