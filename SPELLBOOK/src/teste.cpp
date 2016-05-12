#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;

void st_build(vi &st, const vi &A, int node, int L, int R){
	if (L == R) st[node] = L;                                      
	else{   
		int nL = 2 * node, nR = 2 * node + 1;
		st_build(st, A, nL, L              , (L + R) / 2);
		st_build(st, A, nR, (L + R) / 2 + 1, R          );
		int lContent = st[nL]     , rContent = st[nR];
		int lValue   = A[lContent], rValue   = A[rContent];
		st[node] = (lValue <= rValue) ? lContent : rContent;
	}
}

void st_create(vi &st, vi &stf, const vi &A) {       
	int len = (int)(2*pow(2.0, floor((log((double)A.size())/log(2.0)) + 1)));
	st.assign(len, 0); stf.assign(len, 0); 
	st_build(st, A, 1, 0, (int)A.size() - 1);
}

int st_rmq(vi &st, vi &stf, vi &A, int node, int L, int R, int i, int j, int up){
	if(i > R || i < L) return -1;
	if (L >= i && R <= j){
		
		stf[node] += up;
		return st[node];
	}
	
	up += stf[node];
	stf[node] = 0;
	int mid = (L+R)/2;
	int p1 = st_rmq(st, A, 2*node, L, mid, i, j, up); 
 	int p2 = st_rmq(st, A, 2*node+1, mid+1, R, i, j, up);
 	int b1 = stf[2*node];
 	int b2 = stf[2*node+1];

	if(p1 == -1) return p2;     
	if(p2 == -1) return p1;                            
	return (A[p1]+b1 <= A[p2]+b2) ? p1 : p2;
}

int st_rmq(vi &st, vi &stf, vi& A, int i, int j) {     
	return st_rmq(st, stf, A, 1, 0, 0, (int)A.size() - 1, i, j); 
}

void st_update_range(vi &stf, vi& A, int node, int L, int R, int i, int j, int v){
	if(i>R || j<L) return;
	if(L >= i && R <= j){
		stf[node] += v;
		return;
	}
	else{		
		v += stf[node];
		stf[node] = 0;
		st_update_range(stf, A, 2*node, L, (L+R)/2, i, j, v);
		st_update_range(stf, A, 2*node+1, (L+R)/2+1, R, i, j, v);
		return;
	}
}

void st_update_range(vi &stf, vi& A, int i, int j, int v){
	return st_update_range(stf, A, f, 1, 0, (int)A.size() - 1, i, j, v);
}

int st_update_point(vi &st, vi &A, int node, int b, int e, int idx, int v) {
	int i = idx, j = idx;

	if (i > e || j < b) return st[node];

	if (b == i && e == j) {
		A[i] = v; 
		return st[node] = b;
	}

	int p1, p2;
	p1 = st_update_point(st, A, 2 * node    , b              , (b + e) / 2, idx, new_value);
	p2 = st_update_point(st, A, 2 * node + 1, (b + e) / 2 + 1, e          , idx, new_value);

	return st[node] = (A[p1] <= A[p2]) ? p1 : p2;
}

int st_update_point(vi &st, vi &A, int idx, int v){
	return st_update_point(st, A, 1, 0, (int)A.size() - 1, idx, v); 
}

int main() {
  int arr[7] = { 8, 7, 3, 9, 5, 1, 10 };                   // the original array
  vi A(arr, arr + 7);
  vi st, stf; 
  st_create(st, stf, A);

  printf("              idx    0, 1, 2, 3, 4, 5  , 6\n");
  printf("              A is { 8, 7, 3, 9, 5, 1  , 10 }\n");
  printf("RMQ(1, 3) = %d\n", st_rmq(st, A, 1, 3));          // answer is index 2
  printf("RMQ(4, 6) = %d\n", st_rmq(st, A, 4, 6));          // answer is index 5
  printf("RMQ(3, 4) = %d\n", st_rmq(st, A, 3, 4)); // 4
  printf("RMQ(0, 0) = %d\n", st_rmq(st, A, 0, 0)); // 0
  printf("RMQ(0, 1) = %d\n", st_rmq(st, A, 0, 1)); // 1
  printf("RMQ(0, 6) = %d\n", st_rmq(st, A, 0, 6)); // 5

  printf("              idx    0, 1, 2, 3, 4, 5  , 6\n");
  printf("Now, modify A into { 8, 7, 3, 9, 5, 100, 10 }\n");
  st_update_point(st, A, 5, 100); // update A[5] from 1 to 100
  printf("These values do not change\n");
  printf("RMQ(1, 3) = %d\n", st_rmq(st, A, 1, 3)); // 2
  printf("RMQ(3, 4) = %d\n", st_rmq(st, A, 3, 4)); // 4
  printf("RMQ(0, 0) = %d\n", st_rmq(st, A, 0, 0)); // 0
  printf("RMQ(0, 1) = %d\n", st_rmq(st, A, 0, 1)); // 1
  printf("These values change\n");
  printf("RMQ(0, 6) = %d\n", st_rmq(st, A, 0, 6)); // 5->2
  printf("RMQ(4, 6) = %d\n", st_rmq(st, A, 4, 6)); // 5->4
  printf("RMQ(4, 5) = %d\n", st_rmq(st, A, 4, 5)); // 5->4
} // return 0;
