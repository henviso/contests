#include <iostream>
#include <cstdio>

#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)

using namespace std;

int main(){
	int n = 200, k = 100;
	cout << "1\n" << n << " " << k << endl;
	cout << "1";
	REPP(i, 2, n+1) cout << " " << i;
	cout << endl;
}
