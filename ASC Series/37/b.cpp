#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <bitset>
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
#define PI 3.1415926535897932384626
#define MAX_PRIME 11111



int main(){
	REPP(n, 3, 1001){
		//cout << n << endl;
		for(ll ac = n; ac>=2; ac--){
			if(ac%2LL){
				if((ac*(ac-1))/2LL <= n && (ac*(ac-1))/2LL != n-1){
					cout << ac << endl;
					break;
				}
			}
			else{
				if((ac*ac)/2 <= n){
					cout << ac << endl;
					break;
				}
			}
		}
	}
}
