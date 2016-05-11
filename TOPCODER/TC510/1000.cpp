#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>

#define ALL(x) (x).begin(),x.end()
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)

using namespace std;

class TheLuckyBasesDivTwo {
	public:
	
	long long ANS;
	unsigned long long N;
	unsigned long long row[100];
	
	unsigned long long aval(int col, unsigned long long base){
		unsigned long long ans = 0ULL;
		unsigned long long b = 1ULL;
		REP(j, col){
			ans += row[j]*b;
			b *= base;
			if(base <= row[j]) return 0ULL;
			if(ans > N) return 1000000000000000ULL;
		}
		return ans;
	}
	
	void bt(int col){
		if(col > 0){
			//cout << " ROW EH "; REP(i, col) cout << row[i] << " "; cout << "\nANS EH " << ANS << endl;
			if(found(col)){
				ANS++;
			}
			if(col == 18) return;
		}	
		row[col] = 4ULL;
		bt(col+1);
		row[col] = 7ULL;
		bt(col+1);
	}
	
	bool found(int col){
		unsigned long long hi = N+2, num, lo = 1, mid, res = 0ULL;
		while(hi-lo > 1){
			mid = (hi+lo)/2;
			num = aval(col, mid);
			if(num == N){
				res = mid;
				break;
			}
			else if(num < N){ lo = mid; }
			else{ hi = mid; }
		}
		return (res != 0ULL);
	}
	
	
	long long find(long long n) {
		N = (unsigned long long) n;
		if(n == 7LL || n == 4LL) return -1LL;
		ANS = 0LL;
		bt(0);
		
		return ANS;
	}
};
