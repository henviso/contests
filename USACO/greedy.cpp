/*
ID: henviso1
PROG: gift1
LANG: C++                  
*/
#include <iostream>
#include <fstream>
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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
string p[100];
map<string, int> idx;
int r[100];

int main(){
	ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
	fin >> n;
	REP(i, n){ fin >> p[i]; idx[p[i]] = i; }
	CLEAR0(r);
	string x;
	int id;
	int m, q;
	REP(i, n){
		fin >> x;
		id = idx[x];
		fin >> q >> m;
		if(m > 0){
			int tip = q/m;
			REP(j, m){
				fin >> x;
				int k = idx[x];
				r[k] += tip;
				r[id] -= tip;
			}
		}
	}
	REP(i, n) fout << p[i] << " " << r[i] << endl;
	return 0;
}
