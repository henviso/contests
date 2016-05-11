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

void ft_create(vi &t, int n){ t.assign(n+1, 0); }

int ft_rsq(const vi &t, int b){
    int sum = 0; for(; b; b -= CHECKFIRST(b)) sum += t[b];
    return sum;
}

int ft_rsq(const vi &t, int a, int b){
    return ft_rsq(t, b) - (a == 1? 0 : ft_rsq(t, a-1)); 
}

void ft_adjust(vi &t, int k, int v){
    for(; k  <= (int)t.size(); k += CHECKFIRST(k)) t[k] += v;
}

int n;
map<int, int> pos;
map<int, int> rev;
int a[1000000];
vi ft;

int main(){
    int a, b;
    cin >> n;
    REP(i, n){
        cin >> a >> b;
        if(a > b) swap(a, b);
        if(pos.count(a) == 0) pos[a] = a;
        if(pos.count(b) == 0) pos[b] = b;
        int x = pos[a]; pos[a] = pos[b]; pos[b] = x;
    }
    ll ans = 0;
    int k = 0;
    int cnt = 1;
    vi aux;
    n *= 2;
    //cout << " POS.size " << pos.size() << endl;
    ft_create(ft, n+10);
    for(map<int, int>::iterator it = pos.begin(); it != pos.end(); it++){ rev[it->first] = cnt; cnt++; } cnt = 1;
    for(map<int, int>::iterator it = pos.begin(); it != pos.end(); it++){
        int x = it->first;
        int y = it->second;
        
        //cout << "X " << x << "-> " << y << endl;
        //cout << "AUX: ";
        //REP(i, aux.size()) cout << aux[i] << " ";
        //cout << endl;
        /*
        cout << "BUX: ";
        REP(i, bux.size()) cout << bux[i] << " ";
        cout << endl;*/
        
        int Z = lower_bound(aux.begin(), aux.end(), y+1) - aux.begin();
        int t = (y < x-1) ? x-1-y-(aux.size() - Z) : 0;
        ll e = (aux.empty())? 0 : (x - 1 - aux[aux.size()-1]);
        
        ans += t;
        //cout << "ANS1 " << t << endl;
        aux.push_back(x);
        
        ll q;
        if(rev.count(x-1)){
            q = ft_rsq(ft, rev[x-1], n+5); 
        }
        else{
            q = ft_rsq(ft, rev[x], n+5);
            ans += q * e;
        }
        
        //cout << "ANS2 " << q * e << endl;
        
        q = ft_rsq(ft, rev[y], n+5);
        ans += q;
        ft_adjust(ft, rev[y], 1);
        //cout << "INC NA POS " << rev[y] << " DA FT\n";
        //cout << "ANS3 " << q << endl;
        //cout << "ANS " << ans << endl;
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
