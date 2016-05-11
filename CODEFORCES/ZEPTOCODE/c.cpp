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
#define EPS 10e-20
//__builtin_popcount(m)
//scanf(" %d ", &t);

ll c, hr, hb, wr, wb;

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

ll best(int k){
    ll a = 0LL;
    if(k >= wr) a = max(a, best(k-wr)+hr);
    if(k >= wb) a = max(a, best(k-wb)+hb);
    return a;
}

int main(){
    cin >> c >> hr >> hb >> wr >> wb;
    double pr = ((double) hr)/wr;
    double pb = ((double) hb)/wb;
    if(pr < pb){ swap(hr, hb); swap(wr, wb); }
    
    ll m = mmc(wr, wb);
    
    
    cout << "PR " << pr << " PB " << pb << endl;
    cout << " M " << m << endl;
    
    
    ll ANS = (c/m) * ((m/wr)*hr);
    
    cout << " ANS " << ANS << endl;
    
    ANS += best(c%m);
    cout << ANS << endl;
    
}