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

int n;

int main(){
	vi v;
	bool problem = false;
	int y = 2;
	while(scanf(" %d", &n) != EOF){
		v.clear();
		int x;
		scanf(" %d", &x); v.push_back(x);
		while(cin.peek() != EOF && cin.peek() != '\n'){
			scanf(" %d", &x); v.push_back(x);
		}
		bool pares[n+10][n+10];
		CLEAR0(pares);
		
		for(int i = 0; i<v.size(); i++){
			int x = v[i], y = v[(i+1)%v.size()]; 
			if(x == y){
				cout << " COLORACAO NAO PROPRIA ENCONTRADA VERTICES ADJACENTES: " << x << " " << y << endl; 
				problem = true;
				break;
			}
			pares[x][y] = pares[y][x] = true;
		}
		if(problem) break;
		for(int i = 1; i<=n; i++)
		for(int j = i+1; j<=n; j++){
			if(!pares[i][j]){
				cout << "COLORACAO NAO EH PROPRIA O PAR " << i << " " << j << " ESTA FALTANDO\n";
				problem = true;
				break;
			}
		}
		if(problem) break;
		if(v.size() != y+1){
			problem = true;
			cout << " NUMERO DE ARESTAS ERRADO DEVERIA SER " << x+1 << endl;
			break;
		}
		y = v.size();
	}
	if(problem){
		cout << "PROBLEMA NA COLORAÇÃO\n";
		cout << "COLORACAO DE " << n << " CORES: ";
		REP(i, v.size()) cout << v[i] << " ";
		cout << endl;
	}
}
