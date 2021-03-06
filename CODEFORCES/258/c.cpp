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
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define INRANGE0(x, n) ((x) > -1 && (x) < n)
#define INRANGE(x, a, b) ((x) >= a && (x) <= b)
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
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-11
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S))  //PRECISA DE UMA TABELA PARA TRANSFORMAR EM INDICE
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  //J PRIMEIROS
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL  //J PRIMEIROS
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//scanf(" %d ", &t);

ll n, k, d1, d2;
ll s1, s2, s3;
int t;

int main(){
    cin >> t;
    while(t--){
		cin >> n >> k >> d1 >> d2;
		
		bool pos = false;
		ll x = k - 2*d2 - d1;
		ll MX;
		
		if(x >= 0LL && (x%3LL == 0LL)){
			s3 = x/3LL;
			s2 = s3 + d2;
			s1 = s2 + d1;
			if(s2 >= 0LL && s1 >= 0LL){
				MX = max(s1, s2);
				MX = max(MX, s3);
				ll lft = n-k;
				lft -= (3*MX -(s1+s2+s3));
				if(lft >= 0LL && (lft%3LL == 0LL)) pos = true;
			}
		}
		
		x = k + 2*d2 - d1;
		 
		if(x >= 0LL && (x%3LL == 0LL)){
			s3 = x/3LL;
			s2 = s3 - d2;
			s1 = s2 + d1;
			if(s2 >= 0LL && s1 >= 0LL){
				MX = max(s1, s2);
				MX = max(MX, s3);
				ll lft = n-k;
				lft -= (3*MX -(s1+s2+s3));
				if(lft >= 0LL && (lft%3LL == 0LL)) pos = true;
			}
		}
		
		x = k - 2*d2 + d1;
		 
		if(x >= 0LL && (x%3LL == 0LL)){
			s3 = x/3LL;
			s2 = s3 + d2;
			s1 = s2 - d1;
			if(s2 >= 0LL && s1 >= 0LL){
				MX = max(s1, s2);
				MX = max(MX, s3);
				ll lft = n-k;
				lft -= (3*MX - (s1+s2+s3));
				if(lft >= 0LL && (lft%3LL == 0LL)) pos = true;
			}
		}
		
		x = k + 2*d2 + d1;
		 
		if(x >= 0LL && (x%3LL == 0LL)){
			s3 = x/3LL;
			s2 = s3 - d2;
			s1 = s2 - d1;
			if(s2 >= 0LL && s1 >= 0LL){
				MX = max(s1, s2);
				MX = max(MX, s3);
				ll lft = n-k;
				lft -= (3*MX -(s1+s2+s3));
				if(lft >= 0LL && (lft%3LL == 0LL)) pos = true;
			}
		}
		
		if(pos) cout << "yes\n";
		else cout << "no\n";
	}
}
