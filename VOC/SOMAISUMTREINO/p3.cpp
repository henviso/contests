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

int p[110000], t[110000];
int n, m;

int main(){
	bool patBroken;
	scanf(" %d ", &n);
	REP(i, n){
		scanf(" %d ", &t[i]);
		if(t[i] == 0) patBroken = false;
	}
	scanf(" %d ", &m);
	REP(i, m){
		scanf(" %d ", &p[i]);
		if(p[i] == 0) patBroken = true;
	}
	if(patBroken){ //SO PRECISO SABER O SEGUNDO MENOR
		//if(n == m) REP(i, n) p[i] = t[i];
		//else{
			int best[110000];
			int sbest[110000];
			int tbest[110000];
			best[0] = sbest[0] = tbest[0] = 0;
			int cnt[1100000], d = n-m; 
			CLEAR0(cnt);
			REP(i, n){
				best[i+1] = best[i];
				sbest[i+1] = sbest[i];
				tbest[i+1] = tbest[i];
				if(i-d-1 >= 0){
					cnt[t[i-d-1]]--;
					if(cnt[best[i+1]] < cnt[sbest[i+1]]) swap(best[i+1], sbest[i+1]);
					if(cnt[sbest[i+1]] < cnt[tbest[i+1]]) swap(sbest[i+1], tbest[i+1]);
				}
				cnt[t[i]]++;
				if(t[i] != best[i+1]){
					if(cnt[t[i]] >= cnt[best[i+1]]){
						tbest[i+1] = sbest[i+1];
						sbest[i+1] = best[i+1];
						best[i+1] = t[i];
					}
					else if(t[i] != sbest[i+1]){
						if(cnt[t[i]] >= cnt[sbest[i+1]]){
							tbest[i+1] = sbest[i+1];
							sbest[i+1] = t[i];
						}
						else if(t[i] != tbest[i+1] && cnt[t[i]] >= cnt[tbest[i+1]]) tbest[i+1] = t[i];
					}
				}
				//cout << " NO PADRAO ESTOU OLHANDO PARA " << i-d << endl;
				//cout << " I " << i << " BEST " << best[i+1] << endl;
				if(i-d >= 0 && p[i-d] == 0){	
					p[i-d] = best[i+1];
				}
			}
		//}
	}
	else{ //SO PRECISO SABER O MENOR OLHAR DE TRAS PRA FRENTE
		//if(n == m) REP(i, n) t[i] = p[i];
		//else{
			int cnt[1100000]; CLEAR0(cnt);
			int i;
			int first = 0;
			priority_queue< ii, vector<ii> > pq; pq.push(ii(0,0));
			for(i = 0; i<n; i++){
				if(i+m-1 >= n){
					//cout << " TIRANDO " << p[first] << endl;
					cnt[p[first]]--;
					pq.push(ii(cnt[p[first]], p[first]));
					first++;
				}
				if(i < m){
					//cout << "COLOCANDO " << p[i] << endl;
					cnt[p[i]]++;
					pq.push(ii(cnt[p[i]], p[i]));
				}
				if(t[i] == 0){
					ii aux = pq.top();
					//cout << " AUX EH " << aux.first << " , " << aux.second << " CNT " << cnt[aux.second] << endl;
					while(aux.first != cnt[aux.second]){
						pq.pop(); aux = pq.top();
					}
					//cout << " SAIU " << endl;
					//cout << " AUX EH " << aux.first << " , " << aux.second << " CNT " << cnt[aux.second] << endl;
					t[i] = aux.second;
				}
				//cout << i+1 << " BEST " << best[i+1] << " SBEST " << sbest[i+1] << " TBEST " << tbest[i+1] << endl;
			}
		//}
	}
	printf("%d", t[0]);
	REPP(i, 1, n) printf(" %d", t[i]);
	printf("\n");
	printf("%d", p[0]);
	REPP(i, 1, m) printf(" %d", p[i]);
	printf("\n");
}
