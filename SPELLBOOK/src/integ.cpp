#define SIEVE_MAX 10000000
bitset<SIEVE_MAX+1> _prime; 
vi primes;

void sieve(){
	_prime.set();
	_prime[0] = _prime[1] = 0; primes.pb(2);
	for(ll i = 4; i<SIEVE_MAX; i+=2) _prime[i] = 0;
	for(ll i = 3; i<SIEVE_MAX; i+=2){
		if(_prime[i]){ 
			for(ll j = i*i; j<SIEVE_MAX; j+=2*i) _prime[j] = 0;
			primes.push_back((int) i);
		}
	}
}

bool isPrime(ll N){
	if(N <= SIEVE_MAX) return _prime[N];
	for(int i = 0; i<(int) primes.size(); i++){
		if(N%primes[i] == 0) return false;
	}
	return true;
}

vi primeFactors(ll N) {
	vi factors;     //TROCAR PRA vll SE O NUMERO FOR > QUE INT
	ll PF_idx = 0, PF = primes[PF_idx];
	while(N > 1 && (PF*PF <= N)){
		while(N%PF == 0){ N /= PF; factors.push_back((int) PF); }
		PF = primes[++PF_idx];
	}
	if(N > 1) factors.push_back((int) N);
	return factors; 
}

ll numPf(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
	while(N > 1 && (PF*PF <= N)){
		while(N%PF == 0){ N /= PF; ans++; }
		PF = primes[++PF_idx];
	}
	if(N > 1) ans++;
	return ans;
}

ll numDiv(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while(N > 1 && (PF*PF <= N)){
		ll power = 0;
		while(N%PF == 0){ N /= PF; power++; }
		ans *= (power+1);
		PF = primes[++PF_idx];;
	}
	if(N > 1) ans *= 2;
	else return N;
	return ans;
}

ll EulerPhi(ll N){
	ll PF_idx = 0, PF = primes[PF_idx], ans = N;
	while(N != 1 && (PF * PF <= N)){
		if(N%PF == 0) ans -= ans / PF;
		while(N%PF == 0) N /= PF;
		PF = primes[++PF_idx];
	}
	if(N != 1) ans -= ans/N;
	return ans;
}

unsigned long long fastExp(unsigned long long base, unsigned long long p, unsigned long long m){
	if(p == 0) return 1;
	else if(p == 1) return base%m;
	else{
		unsigned long long res = fastExp(base, p/2, m);
		res = (res*res)%m;
		if(p%2 == 1) res = (res*base)%m;
		return res;
	}
}


int x, y, d;

//inv modular de a mod b = m é o x
void extendedEuclid(int a, int b){
	if(b == 0){ x = 1; y = 0; d = a; return; }
	extendedEuclid(b, a%b);
	int x1 = y;
	int y1 = x - (a/b) * y;
	x = x1;
	y = y1;
}

ll invMult(ll a, ll m){
	extendedEuclid(a, m);
	if(x < 0) x += m;
	return x;
}

ll weakComp(int n, int k){
	ll res = fat[n+k-1];
	ll a = (fat[n] * fat[k-1])%M;
	if(res == 0 || a == 0) return 0;
	invMult(a, M);
	//cout << "FAT DEU " << fat[n+k-1] << " D DEU " << d << " INV DEU " << x << endl;
	if(a != 1) if(d == 1) res = (res*x)%M;
	return res;
}

int grid[360][360];
int R, C;

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void floodfill(int r, int c){
	//cout << "CHAMANDO FLOOD EM " << r << " " << c << " E O N " << n << endl;
	if(r < 0 || r >= R || c < 0 || c >= C) return;
	if(classify(grid[r][c]) != classe) return;
	grid[r][c] = -1;
	//cout << " DESBLOQUEANDO " << r << " " << c << endl;
	for(int d = 0; d<4; d++) floodfill(r+dr[d], c+dc[d], classe);
	return;
}
