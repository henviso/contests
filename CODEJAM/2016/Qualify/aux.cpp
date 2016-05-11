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
//L[i]=L[i/2]+1;

int m[3][4];

int main(){
	m[0][0] = 6;
	m[0][1] = 2;
	m[0][2] = 4;
	m[0][3] = 8;
	
	m[1][0] = 6;
	m[1][1] = 4;
	m[1][2] = 6;
	m[1][3] = 4;
	
	m[2][0] = 6;
	m[2][1] = 8;
	m[2][2] = 4;
	m[2][3] = 2;
	
	set< vi > hist;
	
	for(int i = 0; i<4; i++)
	for(int j = 0; j<4; j++)
	for(int k = 0; k<4; k++)
	for(int l = 0; l<4; l++)
	for(int z = 0; z<4; z++)
	for(int zz = 0; zz<4; zz++){
		int v[3] = {8, 4, 2};
		REP(x, 3) v[x] = (v[x] + m[x][i] + m[x][j] + m[x][k] + m[x][l] + m[x][z] + m[x][zz])%10;
		if(v[0] == v[1] && v[1] == v[2] && v[1] == 4){
			vi v;
			v.push_back(i);
			v.push_back(j);
			v.push_back(k);
			v.push_back(l);
			v.push_back(z);
			v.push_back(zz);
			sort(v.begin(), v.end());
			if(!hist.count(v)){
				cout << " IGUAL A:\n";
				hist.insert(v);
				REP(i, v.size()) cout << " " << v[i] << " ";
				cout << endl;
			}
			
		}
	}
	
	
	

}
