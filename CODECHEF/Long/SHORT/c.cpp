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

int t, nd;


ll n;
ll p[20], f[20][20];
ll s[100], sf[100];

void precmp(ll x){
	CLEAR0(s);
	CLEAR0(sf);
	
	stack<ll> st;
	while(x){
		st.push(x%10LL);
		x /= 10LL;
	}
	while(!st.empty()){
		s[nd++] = st.top();
		st.pop();
	}
	REP(i, nd){
		ll r = 0LL; 
		for(int j = i; j<nd; j++) r = r*10LL + s[j];
		sf[i] = r;
	}
}

ll solve(ll d){
	//cout << " PROCURANDO " << d << endl;
	ll ans = 0LL;
	for(int i = 0; i<nd; i++){
		int lft = nd - (i+1);
		REP(k, s[i]){
			if(k == d && (i > 0 || d > 0)) ans += p[lft];
			else{
				if(d != 0) ans += f[d][lft];
				else{
					if(k > 0) ans += f[d][lft];
			cout << " F " << lft << " " << f[d][lft] << endl;
			cout << " K " << k << " " << " ans " << ans << endl;
		}
		if(s[i] == d) return(ans + sf[i+1] + 1);
		cout << " I " << i << " ans " << ans << endl;
	}
	return ans;
}

int main(){
	/*
	scanf(" %d ", &t);
	p[0] = 1LL;
	REPP(i, 1, 20) p[i] = p[i-1]*10;
	while(t--){
		
		
		
		printf("\n");
	}*/
	scanf(" %lld ", &n);
	p[0] = 1LL;
	REP(k, 10){ f[k][1] = 1LL; f[k][0] = 0LL; }
	REPP(i, 1, 20) p[i] = p[i-1] * 10LL;
	REPP(i, 2, 20){
		REP(k, 10){
			if(k) f[k][i] = 9LL*f[k][i-1] + p[i-1];
			else{
				f[k][i] = 9LL*f[k][i-1];
				REPP(j, 1, i-1) f[k][i] += 9LL * p[j];
				f[k][i]++;
			}
		}
	}
	
	precmp(n);
	
	//f[1] = numero de vezes q um digito ocorre numa dezena, centena...
	ll x = n;
	int cnt[10]; CLEAR0(cnt);
	REPP(i, 1, x+1){
		int k = i;
		bitset<10> vis; vis.reset();
		while(k){
			int d = k%10;
			if(!vis[d]){ cnt[d]++; vis[d] = true; }
			k /= 10;
			if(d == 0) cout << i << " " << cnt[d] << endl;
		}
	}
	REP(i, 10) cout << i << " " << cnt[i] << endl;
	cout << "---------------------------------------------------------------\n";
	//REP(i, 10) cout << i << " " << solve(i) << endl;
	solve(0LL);
}
