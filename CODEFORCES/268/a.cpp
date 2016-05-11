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
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

ll n;

int main(){
	cin >> n;
	//REPP(i, 1, n+1) a[i-1] = ((ll) i);
	if(n >= 4){
		cout << "YES\n";
		if(n%2){
			if(n > 5){
				int cnt = 0;
				for(int x = n; x>5; x-=2){
					cout << x << " - " << x-1 << " = 1\n";
					cnt++;
				}
				while(cnt > 1){
					int aux = cnt;
					cnt = 0;
					while(aux > 1){
						cout << 1 << " * " << 1 << " = 1\n";
						cnt++;
						aux -= 2;
					}
					cnt += aux;
				}
				cout << 1 << " * " << 1 << " = 1\n";
			}
			cout << "3 * 5 = 15\n";
			cout << "2 * 4 = 8\n";
			cout << "8 + 15 = 23\n";
			cout << "23 + 1 = 24\n";
		}
		else{
			if(n > 5){
				int cnt = 0;
				for(int x = n; x>4; x-=2){
					cout << x << " - " << x-1 << " = 1\n";
					cnt++;
				}
				while(cnt > 1){
					int aux = cnt;
					cnt = 0;
					while(aux > 1){
						cout << 1 << " * " << 1 << " = 1\n";
						cnt++;
						aux -= 2;
					}
					cnt += aux;
				}
				cout << 1 << " * " << 1 << " = 1\n";
			}
			cout << "3 * 4 = 12\n";
			cout << "2 * 12 = 24\n";
			cout << "1 * 24 = 24\n";
		}
		
	} 
	else cout << "NO\n";
}
