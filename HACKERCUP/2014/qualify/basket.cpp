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
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define IN0(x, n) ((x) > -1 && (x) < n)
#define IN(x, a, b) ((x) >= a && (x) <= b)
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
//__builtin_popcount(m)
//scanf(" %d ", &t);

typedef struct s_player{
	string nm;
	int sp;
	int h;
	int ind;
} PLAYER;

bool draft_cmp(const PLAYER &a, const PLAYER &b){
	if(a.sp != b.sp) return (a.sp > b.sp);
	return (a.h > b.h);
} 

int n, m, p, t;

PLAYER v[200];
PLAYER a[200], b[200];

int main(){
	scanf(" %d ", &t);
	REPP(ca, 1, t+1){
		scanf(" %d %d %d ", &n, &m, &p);
		REP(i, n) cin >> v[i].nm >> v[i].sp >> v[i].h;
		sort(v, v+n, draft_cmp);
		REP(i, n) v[i].ind = i;
		bitset<200> playing; playing.reset();
		
		int sa = 0, sb = 0;
		REP(i, n){
			if(i%2) b[sb++] = v[i];
			else a[sa++] = v[i];
		}
		
		int time[200]; CLEAR0(time);
		
		priority_queue< ii, vii, greater<ii> > ba, bb;
		priority_queue< ii, vii> fa, fb;
		
		REP(i, sa){
			int x = (a[i].ind);
			if(i < p) playing[x] = true;
			else ba.push(mp(time[x], x));
		}
		REP(i, sb){
			int x = (b[i].ind);
			if(i < p) playing[x] = true;
			else bb.push(mp(time[x], x));
		}
		REP(tt, m){
			while(!fa.empty()) fa.pop();
			while(!fb.empty()) fb.pop();
			
			REP(i, n){
				if(playing[i]){
					time[i]++;
					if(i%2) fb.push(mp(time[i], i));
					else fa.push(mp(time[i], i));
				}
			}
			
			if(!ba.empty()){
				int outa = fa.top().second; fa.pop();
				int ina = ba.top().second; ba.pop();
				playing[outa] = false;
				playing[ina] = true;
				ba.push(mp(time[outa], outa));
			}
			
			if(!bb.empty()){
				int outb = fb.top().second; fb.pop();
				int inb = bb.top().second; bb.pop();
				playing[outb] = false;
				playing[inb] = true;
				bb.push(mp(time[outb], outb));
			}
		}
		
		string ans[200]; int qnt = 0;
		REP(i, n) if(playing[i]){
			ans[qnt++] = v[i].nm;
		}
		sort(ans, ans+qnt);
		printf("Case #%d:", ca);
		REP(i, qnt) cout << " " << ans[i];
		printf("\n");
	}
}

