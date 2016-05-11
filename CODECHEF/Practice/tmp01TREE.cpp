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

#define MAXL 27
#define cor(x) (str[x] - 'a'+1)
class Stree {
	public:
		int n,l,r;
		Stree *ch[MAXL], *slink;
		//string str;
	
		Stree(int i = 0, int f = 0):l(i),r(f) {
			slink = NULL;
			CLEAR0(ch);
		}
		
		~Stree() {
			REP(i,MAXL) if (ch[i]) delete ch[i];
		}

		void canonize(Stree *&anode, int &al, int ar) {
			Stree *next;
			while (al <= ar) {
				next = anode->ch[cor(al)];
				if (next->r - next->l > ar - al) break;
				al += next->r - next->l+1; anode = next;
			}
		}
		
		bool testsplit(Stree *&anode, int al, int ar, char t, Stree *&mid) {
			if (al > ar) {
				mid = anode;
				return anode->ch[cor(al)] != NULL;
			}
			
			Stree *next = anode->ch[cor(al)];
			int p = ar - al + next->l+1;
			
			if (t == cor(p)) return true;
			mid = new Stree(next->l,p-1);
			next->l = p; mid->ch[cor(p)] = next;
			anode->ch[cor(al)] = mid;
			return false;
		}
		
		void update(Stree *&anode, int &al, int ar) {
			Stree *old = this, *mid;
			while(!testsplit(anode,al,ar-1,cor(ar),mid)) {
				mid->ch[cor(ar)] = new Stree(ar,n-1);
				if (old != this) old->slink = mid;
				old = mid; anode = anode->slink;
				canonize(anode,al,ar-1);
			}
			if(old != this) old->slink = anode;
		}
		
		void buildtree(string &str) {
			int al, ar; //active node
			Stree *anode = this;
			this->str = str;
			n = str.size(); l=-1,r=-1;
			Stree dummy;
			REP(i,MAXL) dummy.ch[i] = this;
			slink = &dummy;
			for(al = ar = 0; ar < n; ar++) {
				update(anode,al,ar);
				canonize(anode,al,ar);
			}
			CLEAR0(dummy.ch);
		}
};

int longest, last;
int n,m;

int dfs(Stree *t, int deep) {
	int sz = min(t->r,n-1) - t->l + 1;
	if (t->r == n && sz == 0) return 1;
	if (t->l != -1) deep += sz;
	int freq = 0;

	if (t->r == n) freq++;
	REP(i,MAXL) {
	if (t->ch[i]) freq += dfs(t->ch[i],deep);
	}
	int start = min(n-1, t->r) - deep+2;
	if (t->l != -1 && freq >= m && (deep > longest || (deep == longest && start < last))) {
		longest = deep;
		last = start;
	}
	return freq;
}

int q;
char qe[1000000][2];
char str[2000000];
int ini, fim;
string s;

int main(){
	scanf(" %d ", &q);
	
	ini = fim = 0;
	REP(i, q){
		scanf(" %c ", &qe[i][0]);
		if(qe[i][0] == '+'){
			scanf(" %c ", &qe[i][1]);
			str[fim++] = qe[i][1];
		}
		else ini++;
	}
	str[fim] = '\0';
	s = string(&str[0]);
	cout << "STRING COMPLETA " << str << endl;
	/*
	Stree t;
	s += 'a'-1;
	n = s.size()-1;
	t.buildtree(s);
	longest = last = 0;
	dfs(&t,0);
	if (longest == 0) printf("none\n");
	else printf("%d %d\n",longest,n-longest-last+1);
	*/
}
