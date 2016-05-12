typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const int K = 2;
	 
// computes A * B
matrix mul(matrix A, matrix B)
{
    matrix C(K, vector<ll>(K));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}
	 
// computes A ^ p
matrix pow(matrix A, int p)
{
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}
 
// returns the N-th term of Fibonacci sequence
int fib(int N)
{
    // create vector F1
    vector<ll> F1(K);
    F1[0] = 1;
    F1[1] = 1;
	 
    // create matrix T
    matrix T(K, vector<ll>(K));
    T[0][0] = 0, T[0][1] = 1;
    T[1][0] = 1, T[1][1] = 1;
	 
    // raise T to the (N-1)th power
    if (N == 1)
        return F1[0];
    T = pow(T, N-1);
 
    // the answer is the first row of T . F1
    ll res = 0;
    REP(i, K)
        res = (res + T[0][i] * F1[i]) % MOD;
    if(res < 0) res += MOD;
    return res;
}

int main(){
	int t, x;
	scanf(" %d ", &t);
	while(t--){
		scanf(" %d ", &x);
		printf("%d\n", fib(x));
	}
}
