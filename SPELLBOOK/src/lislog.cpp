#define MAX

struct myGreater {
  bool operator()(int A, int B) const {
    return A <= B;
  }
};

int M[MAX+1], P[MAX+1], X[MAX+1];

void print(int a){
	if(P[a] != -1) print(P[a]);
	printf("%d\n", X[a]);
}

void LIS(int n){ //N = NUMERO DE ELEMENTOS DA SEQUENCIA INICIAL

	int A[n+1], len, i, lnis, j;

	P[0] = -1;
	M[1] = 0;
	for (A[0] = X[0], i = lnis = 1; i < n; i++) { // O(n)

	  int *l = upper_bound(A, A + lnis, X[i], myGreater()); // find insertion point, O(log k)
	  *l = X[i];
	  len = (int)((l - A)+1);
	  P[i] = (len > 1)? M[len-1] : -1;
	  //cout << "SETANDO P DE " << i << " = " << P[i] << endl;

	  if(len >= lnis || X[i] < X[M[len]]){
		M[len] = i;
      		lnis = max(lnis, len);
	  }
    }

    printf("%d\n", lnis);
    printf("-\n");
    print(M[lnis]);
}
