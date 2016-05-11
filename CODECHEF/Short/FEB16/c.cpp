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
#include <iomanip>
#include <utility>   
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;
typedef vector< ii > vii;
typedef vector< ll > vll;
///////////////////////////////UTIL/////////////////////////////////
#define ALL(x) (x).begin(),x.end()
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define REPDP(i,a,n) for(int i = n-1; i>=a; i--)

#define PI 3.14159265359
#define DEGtoRAD(x) (x * PI / 180.0)
#define EPS 10e-11

typedef double real;

struct point{ 
	real x, y;
	point(){ };
	point(real _x, real _y){ x = _x; y = _y; }
	bool operator < (point other) const{
		if(fabs(x - other.x) >= EPS) return x < other.x;
		return y < other.y;
	}
	bool operator == (point other){
		return fabs(x - other.x) < EPS && fabs(y - other.y) < EPS;
	}
	double dist(point other){
		return hypot(x - other.x, y - other.y);		
	}
	point rotate(double theta){
		double rad = DEGtoRAD(theta);
		return point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
	}
	friend istream& operator >>(istream &is, point &p);
    friend ostream& operator <<(ostream &os, const point &p);
};

ostream& operator<<(ostream& os, const point& p){
	os << "(" << p.x << "," << p.y << ")";
}

istream& operator>>(istream& is, point& p){
	is >> p.x >> p.y;
}

struct line{
	real a, b, c;
	line(){ };
	line(point p1, point p2){ 
		set(p1, p2);
	}
	void set(point p1, point p2){
		if(p1.x == p2.x){     //linha vertical
			a = 1.0; b = 0.0; c = -p1.x;
		}
		else{
			a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
			b = 1.0;
			c = -(double)(a * p1.x) - (b * p1.y);
		}
	}
	
	
	bool isParallel(line other){
		return fabs(a - other.a) < EPS && fabs(b - other.b) < EPS;
	}
	
	bool isSame(line other){
		return isParallel(other) && (fabs(c - other.c) < EPS);
	}
	
	bool operator == (line other){
		return isSame(other);
	}
	
	bool doIntersect(line other, point *p){
		if(isSame(other)) return false;        //todos os pontos intersectam
		if(isParallel(other)) return false;    //nenhum pontos intersecta
		
		p->x = (other.b * c - b * other.c) / (other.a * b - a * other.b);
		if(fabs(b) > EPS) p->y = -(a * p->x + c) / b;
		else p->y = -(other.a * p->x + other.c) / other.b;
		return true;
	} 
};
		
struct vec{
	real x, y;
	vec(real _x, real _y){ set(_x, _y); }
	vec(point p1, point p2){ set(p1, p2); }
	void set(real _x, real _y){
		x = _x; y = _y;
	}
	void set(point p1, point p2){
		set(p2.x - p1.x, p2.y - p1.y);
	}
	vec scale(double s){   //s nao negativo
		return vec(x * s, y*s);
	}
	point translate(point p){
		return point(p.x + x, p.y + y);
	}	
};

ostream& operator<<(ostream& os, const line& l){
	os << "(" << l.a << "," << l.b << "," << l.c << ")";
}

istream& operator>>(istream& is, line& l){
	is >> l.a >> l.b >> l.c;
}

ostream& operator<<(ostream& os, const vec& v){
	os << "(" << v.x << "," << v.y << ")";
}

istream& operator<<(istream& is, vec& v){
	is >> v.x >> v.y;
}

typedef vector<point> vp;

double distToLine(point p, point A, point B, point *c){
	double scale = (double) ((p.x - A.x) * (B.x -A.x) + (p.y - A.y) * (B.y - A.y)) /
							((B.x - A.x) * (B.x -A.x) + (B.y - A.y) * (B.y - A.y));
	c->x = A.x + scale * (B.x - A.x);
	c->y = A.y + scale * (B.y - A.y);
	return p.dist(*c);
}

double distToLineSegment(point p, point A, point B, point *c){
	if((B.x-A.x) * (p.x-A.x) + (B.y-A.y) * (p.y-A.y) < EPS){
		c->x = A.x; c->y = A.y;
		return p.dist(A);
	}
	if((A.x-B.x) * (p.x-B.x) + (A.y-B.y) * (p.y-B.y) < EPS){
		c->x = B.x; c->y = B.y;
		return p.dist(B);
	}
	return distToLine(p, A, B, c);
}

double cross(point p, point q, point r){
	return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x);
}

bool collinear(point p, point q, point r){
	return fabs(cross(p, q, r)) < EPS;
}

bool ccw(point p, point q, point r){
	return cross(p,q,r) > 0;
}


int n, m, q;
point red[111];
point black[3333];
int p[111];

int main(){
	//scanf(" %d ", &n, &m);
	cin >> n >> m;
	REP(i, n){
		cin >> red[i];
		//red[i].x += 10001;
		//red[i].y += 10001;
	} 
	REP(i, m){
		cin >> black[i];
		//black[i].x += 10001;
		//black[i].y += 10001;
	}
	cin >> q;
	REP(i, q){
		int k;
		cin >> k;
		REP(j, k){
			cin >> p[j];
			p[j]--;
		}
		int ans = 0;
		REP(j, m){
			bool inside = true;
			REP(l, k){
				if(l == k-1){
					if(ccw(red[p[l]], red[p[0]], black[j])){
						//cout << " RETA ENTRE " << red[p[l]] << " E " << red[p[(l+1)%k]] << " E O PRETO ESTA FORA " << black[j] << endl;
						inside = false;
						break;
					}
				}
				else if(ccw(red[p[l]], red[p[l+1]], black[j])){
					//cout << " RETA ENTRE " << red[p[l]] << " E " << red[p[(l+1)%k]] << " E O PRETO ESTA FORA " << black[j] << endl;
					inside = false;
					break;
				}
			}
			ans += inside;
		}
		cout << ans << endl;
		
	}
}

