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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
//__builtin_popcount(m)
//scanf(" %d ", &t);

const int DIG = 1;
const int BASE = 10; // BASE**3 < 2**51
const int TAM = 2048;
struct bigint {
    int v[TAM], n;
    bigint(int x = 0): n(1) {
        memset(v, 0, sizeof(v)); v[n++] = x; fix();
    }
    bigint(char *s): n(1) {
        memset(v, 0, sizeof(v));
        int sign = 1;
        while (*s && !isdigit(*s)) if (*s++ == '-') sign *= -1;
        char *t = strdup(s), *p = t + strlen(t);
        while (p > t) {
            *p = 0; p = max(t, p - DIG);
            sscanf(p, "%d", &v[n]);
            v[n++] *= sign;
        }
        free(t); fix();
    }
    bigint& fix(int m = 0) {
        n = max(m, n);
        int sign = 0;
        for (int i = 1, e = 0; i <= n || e && (n = i); i++) {
            v[i] += e; e = v[i] / BASE; v[i] %= BASE;
            if (v[i]) sign = (v[i] > 0) ? 1 : -1;
        }
        for (int i = n - 1; i > 0; i--)
            if (v[i] * sign < 0) { v[i] += sign * BASE; v[i+1] -= sign; }
        while (n && !v[n]) n--;
        return *this;
    }
    int cmp(const int a, const int b) const{
		if(a < b) return -1;
		if(a > b) return 1;
		return 0;
	}
    
    int cmp(const bigint& x = 0) const {
        int i = max(n, x.n), t = 0;
        while (1) if ((t = cmp(v[i], x.v[i])) || i-- == 0) return t;
    }
    bool operator <(const bigint& x) const { return cmp(x) < 0; }
    bool operator ==(const bigint& x) const { return cmp(x) == 0; }
    bool operator !=(const bigint& x) const { return cmp(x) != 0; }
    operator string() const {
        ostringstream s; s << v[n];
        for (int i = n - 1; i > 0; i--) {
            s.width(DIG); s.fill('0'); s << abs(v[i]);
        }
        return s.str();
    }
    friend ostream& operator <<(ostream& o, const bigint& x) {
        return o << (string) x;
    }
    bigint& operator +=(const bigint& x) {
        for (int i = 1; i <= x.n; i++) v[i] += x.v[i];
        return fix(x.n);
    }
    bigint operator +(const bigint& x) { return bigint(*this) += x; }
    bigint& operator -=(const bigint& x) {
        for (int i = 1; i <= x.n; i++) v[i] -= x.v[i];
        return fix(x.n);
    }
    bigint operator -(const bigint& x) { return bigint(*this) -= x; }
    bigint operator -() { bigint r = 0; return r -= *this; }
    void ams(const bigint& x, int m, int b) { // *this += (x * m) << b;
        for (int i = 1, e = 0; (i <= x.n || e) && (n = i + b); i++) {
            v[i+b] += x.v[i] * m + e; e = v[i+b] / BASE; v[i+b] %= BASE;
        }
    }
    bigint operator *(const bigint& x) const {
        bigint r;
        for (int i = 1; i <= n; i++) r.ams(x, v[i], i-1);
        return r;
    }
    bigint& operator *=(const bigint& x) { return *this = *this * x; }
    // cmp(x / y) == cmp(x) * cmp(y); cmp(x % y) == cmp(x);
    bigint div(const bigint& x) {
        if (x == 0) return 0;
        bigint q; q.n = max(n - x.n + 1, 0);
        int d = x.v[x.n] * BASE + x.v[x.n-1];
        for (int i = q.n; i > 0; i--) {
            int j = x.n + i - 1;
            q.v[i] = int((v[j] * double(BASE) + v[j-1]) / d);
            ams(x, -q.v[i], i-1);
            if (i == 1 || j == 1) break;
            v[j-1] += BASE * v[j]; v[j] = 0;
        }
        fix(x.n); return q.fix();
    }
    bigint& operator /=(const bigint& x) { return *this = div(x); }
    bigint& operator %=(const bigint& x) { div(x); return *this; }
    bigint operator /(const bigint& x) { return bigint(*this).div(x); }
    bigint operator %(const bigint& x) { return bigint(*this) %= x; }
    bigint pow(int x) {
        if (x < 0) return (*this == 1 || *this == -1) ? pow(-x) : 0;
        bigint r = 1;
        for (int i = 0; i < x; i++) r *= *this;
        return r;
    }
    bigint root(int x) {
        if (cmp() == 0 || cmp() < 0 && x % 2 == 0) return 0;
        if (*this == 1 || x == 1) return *this;
        if (cmp() < 0) return -(-*this).root(x);
        bigint a = 1, d = *this;
        while (d != 1) {
            bigint b = a + (d /= 2);
            if (cmp(b.pow(x)) >= 0) { d += 1; a = b; }
        }
        return a;
    }
};

#define SIEVE_MAX 1000000
bitset<SIEVE_MAX+1> _prime; 
vi primes;

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.push_back(2);
	for(ll i = 4; i<SIEVE_MAX; i+=2) _prime[i] = 0;
	for(ll i = 3; i<SIEVE_MAX; i+=2){
		if(_prime[i]){ 
			for(ll j = i*i; j<SIEVE_MAX; j+=2*i) _prime[j] = 0;
			primes.push_back((int) i);
		}
	}
}

char num[100];

int main(){
	sieve();
	while(scanf(" %s ", &num[0]) != EOF){
		bigint a(1);
		bigint b(num);
		bigint c;
		REP(i, primes.size()){
			int p = primes[i];
			c = a;
			a *= bigint(p) ;
			if(a.cmp(b) > 0) break;
		}
		cout << c << endl;
	}
}
