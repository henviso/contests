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

#define INF 0x3f3f3f3f

#define NMAX 210
#define MMAX 410

int x[MMAX][MMAX];
int cmp[NMAX][NMAX];
int n;

vi g[2*NMAX];
int mate[2*NMAX];
bitset<2*NMAX> vis;

bool aug(int v){
    if(vis[v]) return false;
    vis[v] = true;
    REP(i, g[v].size()){
        int w = g[v][i];
        if(mate[w] == -INF || aug(mate[w])){
            mate[w] = v;
            return true;
        }
    }
    return false;
}

int MCBM(){
    REP(i, 2*NMAX) mate[i] = -INF; 
    int mcbm = 0;
    REP(i, n){
        vis.reset();
        mcbm += aug(i);
    }
    return mcbm;
}



int main(){
	freopen("bubble.in","r",stdin);
    freopen("bubble.out","w",stdout);
	scanf(" %d ", &n);
	CLEAR0(cmp);
	REP(i, MMAX) REP(j, MMAX){
		x[i][j] = -1;
	}
	int base = 201;
	vi v;
	REP(i, n-1){
		v.push_back(i);
		REP(j, i+1) scanf(" %d ", &x[i][base-i+2*j]);
	}
	v.push_back(n-1);
	
	bool pos = true;
	REP(j, MMAX){
		for(int i = n-2; i>=0; i--){
			if(x[i][j] == 1){
				if(cmp[v[i+1]][v[i]] == 1){
					//cout << " BOSTA AQUI " << v[i+1] << " ERA PRA SER MENOR QUE " << v[i] << " MAS EH MAIOR " << endl;
					pos = false;
				}
				cmp[v[i+1]][v[i]] = -1;
				cmp[v[i]][v[i+1]] = 1;
				swap(v[i], v[i+1]);
			}
		}
	}
	REP(cnt, NMAX){
		REP(i, n){
			REPP(j, i+1, n){
				if(cmp[i][j] == 0) continue;
				REPP(k, j+1, n){
					if(cmp[j][k] == cmp[i][j]){
						if(cmp[i][k] == 0){
							cmp[i][k] = cmp[i][j];
							cmp[k][i] = -cmp[i][j];
						}
						else if(cmp[i][k] != cmp[i][j]){
							pos = false;
						}
					}
				}
			}
		}
	}
	
	for(int i = 0; i<n; i++){
		int l = 1, r = n;
		for(int j = 0; j<n; j++){
			if(i == j) continue;
			if(cmp[i][j] < 0) r--;
			else if(cmp[i][j]) l++;
		}
		for(int k = l; k<=r; k++){
			g[i].push_back(k+NMAX);
			g[k+NMAX].push_back(i);
		}
	}
	int mm = MCBM();
	pos = pos && (mm == n);
	//cout << " MM " << mm << endl;
	if(pos){
		printf("YES\n");
		for(int i = 1; i<=n; i++){
			int idx = mate[i+NMAX];
			v[idx] = i;
		}
		printf("%d", v[0]);
		REPP(i, 1, n) printf(" %d", v[i]);
	}
	else printf("NO");
	printf("\n");
	/*
	for(int i = 0; i<199; i++){
		for(int j = 0; j<i+1; j++){
			if(j) printf(" ");
			printf("1");
		}
		printf("\n");
	}*/
	
	return 0;
}
