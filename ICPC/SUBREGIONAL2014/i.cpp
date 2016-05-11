#include <cstdio>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

typedef long long int int64;

map<int64, int64> mapa;

int64 expo(int64 a, int64 b, int64 m)
{
int64 y = a, x = 1;
while (b > 0) {
if (b % 2 == 1) {
x = (x*y) % m;
}
y = (y*y) % m;
b = b/2;
}
return x % m;
}

int64 log(int64 p, int64 b, int64 n) {
	mapa.clear();
	int64 d, q, r;
	d = ceil(sqrt(p));
	int64 a = expo(b, d, p) % p;
	int64 acumulado = expo(b, p - 1 - (d - 1), p) % p;
	mapa[(acumulado * (n % p)) % p] = d;
	for (r = d - 2; r >= 0; r--) {
	acumulado = (acumulado * (b % p) ) % p;
	mapa[(acumulado * (n % p)) % p] = r + 1;
	}
	acumulado = 1;
	int64 valor;
	valor = mapa[acumulado];
	if (valor != 0) {
	return valor - 1;
	}
	for (int q = 1; q < d; q++) {
	acumulado = (acumulado * a)
	% p;
	valor = mapa[acumulado];
	if (valor != 0) {
	return q*d + (valor -1);
	}
	}
	return -1;
}

/**** Exemplo simples de uso ****/
int main()
{
	int64 p, b, n;
	while (scanf("%lld %lld %lld", &p, &b, &n) != EOF) {
		int64 x;
		x = log(p, b, n);
		if (x == -1) {
			printf("no solution\n");
		}
		else {
			printf("%lld\n", x);
		}
	}
	return 0;
}
