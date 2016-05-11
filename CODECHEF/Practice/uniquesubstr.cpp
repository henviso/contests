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
#define mp make_pair
/////////////////////////////NUMERICAL//////////////////////////////
#define INCMOD(a,b,c) (((a)+b)%c)
#define DECMOD(a,b,c) (((a)+c-b)%c)
#define ROUNDINT(a) (int)((double)(a) + 0.5)
#define INF 0x3f3f3f3f
#define EPS 1e-7
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

#define MAX_N 1000100

char T[MAX_N];
/*
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int AC[MAX_N], BC[MAX_N];
int c[MAX_N];

void countingSort(int k){
	int sum, maxi = max(300, n);
	CLEAR0(c);
	REP(i, n) c[i + k < n ? RA[i + k] : 0]++;
	for(int i = sum = 0; i<maxi; i++){
		int t =  c[i];
		c[i] = sum;
		sum += t;
	}
	REP(i, n) tempSA[c[(SA[i]+k < n)? RA[SA[i]+k] : 0]++] = SA[i];
	REP(i, n) SA[i] = tempSA[i];
}

void constructSA(){
	int i, k, r;
	REP(i, n){
		RA[i] = T[i];  //initial rankings
		SA[i] = i;     //initial SA: {0,1,2,...,n-1}
	}
	for(k = 1; k<n; k <<= 1){        //repeat the sorting process log n times
		countingSort(k);             //actually radix sort: sort based on the second item
		countingSort(0);             //then stable sort based on the first item
		tempRA[SA[0]] = r = 0;       //reranking start from rank r = 0
		REPP(i, 1, n) tempRA[SA[i]] = //if same pair => same rank r; otherwise, increase r
		(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k])? r : ++r;
		REP(i, n) RA[i] = tempRA[i];  //update the rank array RA
		if(RA[SA[n-1]] == n-1) break;
	}
}

void computeLCP(){
	int Phi[MAX_N], PLCP[MAX_N], LCP; 
	REPP(i, 1, n) Phi[SA[i]] = SA[i-1];
	
	for(int i = 0, L = 0; i<n; i++){
		if(Phi[i] == -1){ PLCP[i] = 0; continue;}
		while(T[i+L] == T[Phi[i] + L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	
	int a, b;
	CLEAR0(ACLCP);
	REP(i, n){
		LCP = PLCP[SA[i]];
		if(LCP){
			a = SA[i];
			b = SA[i-1]+1;
			AC[a] += LCP;
			REP(k, LCP) ACLC[b+k]--;
		}
	}
	ll ac = 0;
	REP(i, n+1){
		ACLCP[i] += ac;
		ac = ACLCP[i];
	}
}

int equalSUBSTR(int a, int b){ //RECEIVES 0-BASED STRING INDEX
	if(b <= a) return 0;
	cout << " IGUAIS DE " << a << " ATE " << b << " EH " << max(ACLCP[a] - ACLCP[b+1], 0) << endl;
	return max(ACLCP[a] - ACLCP[b+1], 0);
}

int q;
char str[2000000];
int a[MAX_N], b[MAX_N];
string s;
*/
int main(){
	cin.getline(T, MAX_N);
	cout << T << endl;

}
