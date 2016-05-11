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

#define PI 3.14159265359
#define DEGtoRAD(x) (x * PI / 180.0)
#define DINF  1E+36

#define foreach(it, a,b) for(typeof(a)it=(a) ; it!=(b) ; it++)
#define all(x) (x).begin(), (x).end()

const double pi = acos(-1);

inline int cmp(double a, double b = 0){
if(fabs(a-b)<=EPS) return 0;
if(a<b) return -1;
return 1;
}

struct point {
double x,y;
int id;
point(double x = 0, double y = 0): x(x), y(y) {}
point operator +(point q){ return point(x + q.x, y + q.y); }
point operator -(point q){ return point(x - q.x, y - q.y); }
point operator *(double t){ return point(x * t, y * t); }
point operator /(double t){ return point(x / t, y / t); }
double operator *(point q){ return x * q.x + y * q.y; }
double operator %(point q){ return x * q.y - y * q.x; }
int cmp(point q) const {
if (int t = ::cmp(x, q.x)) return t;
return ::cmp(y, q.y);
}
bool operator ==(point q) const { return cmp(q) == 0; }
bool operator !=(point q) const { return cmp(q) != 0; }
bool operator < (point q) const { return cmp(q) < 0; }
};
struct reta {
point ini,fim;
reta(){}
reta(point ini, point fim): ini(ini), fim(fim) {}
};
typedef vector<point> poly;
typedef point vetor;

bool ycmp(point a, point b) {
	if (a.y!=b.y) return a.y<b.y;
	return a.x<b.x;
}

double norma(point a){
	return sqrt((a.x * a.x + a.y *a.y));
}

int a, b;

double closest_pair (poly &P) {
	int n = P.size();
	double d = norma(P[0]-P[1]);
	a = P[0].id; b = P[1].id;
	set<point, bool(*)(point,point)> s(&ycmp);
	sort(all(P));
	for(int i=0,j=0 ; i<n ; i++) {
		point lower(0, P[i].y - d) , upper(0, P[i].y + d);
		while(P[i].x - P[j].x > d)
		s.erase(P[j++]);
		foreach(p, s.lower_bound(lower), s.upper_bound(upper))
		/* os pontos mais proximos sao tirados de P[i] e *p */
		if(d > norma(P[i] - *p)){
			d = norma(P[i] - *p);
			a = p->id;
			b = P[i].id;
		}
		s.insert(P[i]);
	}
	return d;
}

int main(){
	/**** especifico para o problema UVa 10245 ****/
	point i;
	poly p;
	int k,n;
	double d;
	while(scanf(" %d", &n)==1 && n) {
	p.clear();
	for(k=0 ; k<n ; k++) {
		scanf(" %lf %lf", &i.x,&i.y);
		i.id = k;
		p.push_back(i);
	}
	if(n==1) d = 10e20;
	else d = closest_pair(p);
	printf("%d %d %.6lf\n", min(a,b), max(a,b), d);
	}
	return 0;
}
