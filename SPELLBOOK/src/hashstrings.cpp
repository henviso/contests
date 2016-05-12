typedef long long unsigned hash;

#define MAXS 10
#define MAXN 300100
#define B 33ULL
#define C 5381ULL

ull power[MAXN];
hash p[MAXS][MAXN];
char str[MAXS][MAXN];
int t[MAXS], n;

void precalc(){
	power[0] = 1ULL;
	REPP(i, 1, MAXN) power[i] = power[i-1]*B;
	REP(i, n){
		p[i][0] = 0ULL;
		REP(j, t[i]){
			p[i][j+1] = p[i][j]*B + str[i][j];
		}
	}
}

void print(int e, int a, int b){
	for(int i = a; i<=b; i++){
		printf("%c", str[e][i]);
	}
	printf("\n");
}

hash calc_dhash(int e, int a, int b) {
	if (a > b) return 0;
	return p[e][b+1] - p[e][a] * power[b - a + 1];
}
