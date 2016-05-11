#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)

int t, n, m, guards;
char a[10][2000];
int dr[4] = {0,0,1,-1};
int dc[4] = {-1,1,0,0};

bool valid(int r, int c){
	return (min(r, c) >= 0 || r < n || c < m);
}

bool freePos(int r, int c){
	return (valid(r, c) &&  (a[r][c] == '.' || a[r][c] == 'x'));
}

bool putGuard(int r, int c){
	if(!freePos(r, c)){
		return false;
	}
	a[r][c] = 'X';
	REP(k, 4){
		int nr = r+dr[k], nc = c+dc[k];
		while(freePos(nr, nc)){
			a[nr][nc] = 'x';
			nr += dr[k], nc += dc[k];
		}
	}
	guards++;
	return true;
}

int main(){
	cin >> t;
	a[0][0] = a[1][0] = 'X'; 
	n = 2;
	REPP(tc, 1, t+1){
		cin >> m;
		REP(i, 2) REPP(j, 1, m+1) cin >> a[i][j];
		a[0][m+1] = a[1][m+1] = 'X'; m += 2;
		guards = 0;
		REP(i, 2) REPP(j, 1, m-1)
		if(a[i][j] == '.' && a[i][j-1] == 'X' && a[i][j+1] == 'X'){
			putGuard((i+1)%2, j);
		}
		REP(i, 2) REPP(j, 1, m-1)
		if(a[i][j] == '.') putGuard(i, j);
		cout << "Case #" << tc << ": " << guards << endl;
	}
}

