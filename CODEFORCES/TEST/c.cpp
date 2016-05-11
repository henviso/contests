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
#define EPS 1e-9
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

char str[500000];
int n;
int cnt[500000][26];

int diver(int a, int b){
	int ans = 0;
	REP(i, 26) ans += ((cnt[b][i] - cnt[a-1][i]) > 0);
	return ans;
}

int main(){
	scanf(" %s ", &str[0]);
	n = strlen(str);
	
	CLEAR0(cnt);
	REP(i, n){
		REP(j, 26) cnt[i+1][j] = cnt[i][j];
		cnt[i+1][(str[i]-'a')]++;
	}
	
	int ans[100]; CLEAR0(ans);
	REPP(i, 1, n+1){
		REPP(k, 1, 27){
			int hi = n+1, lo = i-1, mid, HI, LO = -1;
			while(hi-lo > 1){
				mid = (hi+lo)/2;
				int d = diver(i, mid);
				if(d < k){
					lo = mid;
				}
				else{
					if(d == k) LO = mid;
					hi = mid;
				}
			}
			if(LO != -1){
				hi = n+1, lo = LO, mid, HI = LO;
				while(hi-lo > 1){
					mid = (hi+lo)/2;
					int d = diver(i, mid); 
					//if(k == 1) cout << "lo " << lo << " hi " << hi << " mid " << mid << " d " << d << endl;
					if(d == k){
						//cout << "substitui\n";
						lo = mid;
						HI = mid;
					}
					else{ hi = mid; } 
				}
				int aux = (HI-LO)+1;
				//if(k == 1) cout << " I " << i << " K " << k <<  " RES EH " << aux << " HI " << HI << " LO " << LO << endl;
				ans[k] += aux;
			}
		}
	}
	printf("%d\n", diver(1, n));
	REPP(i, 1, 27){
		if(ans[i] == 0) break;
		printf("%d\n", ans[i]);
	}
}
