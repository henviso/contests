#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>

#define CLEAR(v, x) memset(v, x, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)

using namespace std;

int A[1100][1100];
int B[1100][1100];

class PairGame {
	public:

	void btA(int x, int y){
		A[x][y] = 1;
		//cout << " A " << x << " " << y << endl;
		if(y-x > 0 && A[x][y-x] == -1) btA(x, y-x);
		if(x-y > 0 && A[x-y][y] == -1) btA(x-y, y);
	} 
	
	void btB(int x, int y){
		B[x][y] = 1;
		//cout << " B " << x << " " << y << endl;
		if(y-x > 0 && B[x][y-x] == -1) btB(x, y-x);
		if(x-y > 0 && B[x-y][y] == -1) btB(x-y, y);
	} 
	 
	int maxSum(int a, int b, int c, int d) {
		REP(i, 1100) REP(j, 1100) A[i][j] = B[i][j] = -1;
		btA(a, b);
		btB(c, d);
		int ans = -1;
		REP(i, 1001) REP(j, 1001){
			if(A[i][j] == 1 && B[i][j] == 1) ans = max(ans, i+j);
		}
		return ans;
	}
};

int main(){
	PairGame p;
	cout << p.maxSum(1000, 1001, 2000, 2001) << endl;
}
