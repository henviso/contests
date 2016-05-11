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
//ios::sync_with_stdio(false);

#define MAX_N 500100
#define MAX_S 250000
#define OWNER(x) (x < n1)

typedef long long unsigned hash;

#define MAXN 500100
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXN];

string T, a_, b_;
int n, n1, n2;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];
int Phi[MAX_N], LCP[MAX_N], PLCP[MAX_N];

void countingSort(int k){
	int i, sum, maxi = max(300, n);
	CLEAR0(c);
	for(i = 0; i<n; i++) c[i + k < n ? RA[i+k] : 0]++;
	for(i = sum = 0; i<maxi; i++){ int t = c[i]; c[i] = sum; sum += t; }
	for(i = 0; i<n; i++) tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for(i = 0; i<n; i++) SA[i] = tempSA[i];	
}

void constructSA(){
	int i, k, r;
	for(i = 0; i<n; i++){ RA[i] = T[i]; SA[i] = i; }
	for(k = 1; k<n; k <<= 1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i<n; i++) tempRA[SA[i]] =  (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for(i = 0; i<n; i++) RA[i] = tempRA[i];
		if(RA[SA[n-1]] == n-1) break;
	}
}

void computeLCP(){
	int i, L;
	Phi[SA[0]] = -1;
	for(i = 1; i<n; i++) Phi[SA[i]] = SA[i-1];
	for(i = L = 0; i<n; i++){
		if(Phi[i] == -1){ PLCP[i] = 0; continue;}
		while(T[i+L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for(i = 0; i<n; i++) LCP[i] = PLCP[SA[i]];
}

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
	REP(i, n) p[i+1] = p[i]*B + T[i];
}

hash calc_dhash(int a, int b) {
	if (a > b) return 0;
	return p[b+1] - p[a] * power[b - a + 1];
}


void print(int a, int b){
	for(int i = a; i<=b; i++){
		printf("%c", T[i]);
	}
	printf("\n");
}

int main(){
	cin >> a_ >> b_;
	if(a_.length() < b_.length()) swap(a_, b_);
	a_ += '$';
	b_ += '#';
	n1 = a_.length();
	T = a_+b_;
	n = T.length();
	
	//cout << " T " << T << endl;
	//cout << " N " << n << endl;
	constructSA();
	computeLCP();
	int ans = 0;
	REP(i, n-1)	if(OWNER(SA[i]) != OWNER(SA[i+1])) ans = max(ans, LCP[i+1]);
	if(ans != 0){
		precalc();
		set<hash> cnt;
		int ansp = 0;
		for(int i =  ans-1; i<n; i++){
			int l = i-(ans-1), r = i;
			hash h = calc_dhash(l, r);
			if(r < n1){
				cnt.insert(h);
			}
			if(l >= n1){
				if(cnt.count(h)){
					ansp = l;
					break;
				}
			}
		}
		REP(i, ans) printf("%c", T[ansp+i]);
		printf("\n");
	}
	printf("%d\n", ans);
}
