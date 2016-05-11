#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define NN 10024
/* Geometry Defs {{{ */
struct point { double x, y; int id };
double distsqr(point a, point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
/* }}} */
/* Closest-Pair Problem {{{ */
#define INF 1E10
#define EPS 1E-10
int n;
point p[NN]; /* cuidado! input deve ser global */
bool xcmp(point a, point b) { return a.x < b.x; }
bool ycmp(int a, int b) { return p[a].y < p[b].y; }

pair<double, ii> cpsolve(int a[NN], int L, int R) {
	int i, j, k, n = R-L, q = (L+R)>>1;
	int LT;
	if(n <= 1) return INF;
	if(n == 2) return distsqr(p[a[0]], p[a[1]]);
	/* divida */
	int b[NN];
	for(i = k = 0, j = q - L; k < n; k++)
		if(a[k] <= q && i < (q-L)) b[i++] = a[k];
		else b[j++] = a[k];
	/* conquiste */
	pair<double, ii> al = min(cpsolve(b, L, q), ar = cpsolve(b+q-L, q+1, R), ans;
	if(al.first <= ar.first){
		ans.first = al.first;
		ans.second = al.second;
	}
	else{
		ans.first = ar.first;
		ans.second = ar.second;
	}
	/* combine */
	int f[NN], t = 0;
	for(k = 0; k < n; k++)
		if(fabs(p[a[k]].x - p[q].x) - ans < EPS)
			f[t++] = a[k];
	for(i = 0; i < t-1; i++) {
		for(j = min(i+7, t-1); j > i; j--) {
			double d = distsqr(p[f[i]], p[f[j]]);
			if(d < ans){
				ans.first = d;
				ans.second.first = p[f[i]];
				ans.second.second = p[f[j]];
			}
		}
	}
	return ans;
}

pair<double, ii> closestpair() {
	int i, a[NN];
	for(i = 0; i < n; i++) a[i] = i;
	sort(p, p+n, xcmp);
	sort(a, a+n, ycmp);
	return cpsolve(a, 0, n);
}
/* }}} */
int main(void) {
	int i;
	while(scanf("%d", &n) && n) {
		double ans = INF;
		for(i = 0; i < n; i++){
			scanf("%lf %lf", &p[i].x, &p[i].y);
			p[i].ind = i;
		}
		pair<double, ii> ans = closestpair();
		printf("%d %d %lf\n", min(ans.second.first, ans.second.second), max(ans.second.first, ans.second.second), ans.first);
	}
	return 0;
}
