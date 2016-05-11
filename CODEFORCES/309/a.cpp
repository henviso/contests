#include <iostream>
#include <cstdio>
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
#include <cstring>
#include <unistd.h>
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
#define INF 0x3f3f3f3f
#define EPS 1e-9
/////////////////////////////BITWISE////////////////////////////////
#define CHECK(S, j) (S & (1 << j))
#define CHECKFIRST(S) (S & (-S)) 
#define SET(S, j) S |= (1 << j)
#define SETALL(S, j) S = (1 << j)-1  
#define UNSET(S, j) S &= ~(1 << j)
#define TOOGLE(S, j) S ^= (1 << j)
///////////////////////////////64 BITS//////////////////////////////
#define LCHECK(S, j) (S & (1ULL << j))
#define LSET(S, j) S |= (1ULL << j)
#define LSETALL(S, j) S = (1ULL << j)-1ULL 
#define LUNSET(S, j) S &= ~(1ULL << j)
#define LTOOGLE(S, j) S ^= (1ULL << j)
//__builtin_popcount(m)
//scanf(" %d ", &t);

ll m, x1, h1, Y1, a1, x2, h2, Y2, a2;
ll A[1000100];
ll B[1000100];

ll mdc(ll a, ll b) {
  if(a<0LL) a = -a;
  if(b<0LL) b = -b;

  if(b == 0LL)
    return a;
  else
    return mdc(b, a%b);
}

ll mmc(ll a, ll b){
    return (a*b)/mdc(a,b);
}

int main(){
    cin >> m;
    cin >> h1 >> a1 >> x1 >> Y1;
    cin >> h2 >> a2 >> x2 >> Y2;
    REP(i, m+1) A[i] = B[i] = -1LL;
    ll time = 0LL, ans = -1LL;
    while(true){
        if(h1 == a1 && h2 == a2){ ans = time; break;}
        if(A[h1] != -1LL && B[h2] != -1LL && A[h1] == B[h2]) break;
        if(A[h1] == -1LL) A[h1] = time;
        if(B[h2] == -1LL) B[h2] = time;
        h1 = (x1*h1 + Y1)%m;
        h2 = (x2*h2 + Y2)%m;
        time++;
    }
    int cheat = 1;
    if(cheat == 1);
    //cout << h1 << " A " << A[h1] << " OUTRO " << h2 << " " << B[h2] << endl;
    if(ans == -1) cout << "-1\n";
    else cout << ans << endl;
     
}
