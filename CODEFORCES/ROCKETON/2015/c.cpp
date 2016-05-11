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
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-21
//__builtin_popcount(m)
//scanf(" %d ", &t);

int n;
int l[10];
int r[10];
double p[10][10100];
double pr[10][10100];
double pe[10][10100];


int main(){
    cin >> n;
    REP(i, n)
    REP(j, 10010) pr[i][j] = pe[i][j] = p[i][j] = 0.0;
    REP(i, n){
        cin >> l[i] >> r[i];
        double d = r[i]-l[i]+1.0;
        double P = (1.0 / d);
        REPP(k, 1, 10001){
            p[i][k] = p[i][k-1];
            if(k >= l[i] && k <= r[i]){
                p[i][k] = ((double) (k-l[i]+1.0))/d;
                pe[i][k] = P;
            }
        }
        for(int k = 10000; k>0; k--){
            pr[i][k] = pr[i][k+1];
            if(k >= l[i] && k <= r[i]){
                pr[i][k] = ((double) (r[i]-k+1.0))/d;
            }
        }
    }
    double ans = 0.0;
    REP(i, n){
        REPP(k, 1, r[i]){
            REPP(msk, 1, (1 << (n-1))){
                double P = pr[i][k+1];
                int jog = 0;
                REP(j, n-1){
                    if(jog == i) jog++;
                    if(msk&(1<<j)) P *= pe[jog][k];
                    else P *= p[jog][k-1];
                    jog++;
                }
                //if(fabs(P) >= EPS){
                    //cout << "JOGADOR " << i << " SEGUNDO EH " << k << " JOGADO PELA MASCARA " << msk << endl;
                    ans += P*((double) k);
                    //cout << " PROBABILIDADE " << P <<  " ANS " << ans << endl;
                //}
            }
        }
    }
    REPP(k, 1, 10001){
        REPP(msk, 1, (1 << n)){
            int ones = __builtin_popcount(msk);
            if(ones < 2) continue;
            double P = 1.0;
            REP(j, n){
                if(msk&(1<<j)) P *= pe[j][k];
                else P *= p[j][k-1];
            }
            //if(fabs(P) >= EPS){
                //cout << " PRIM E SEG " << k << " PROB " << P << endl;
                ans += P*((double) k);
            //}
        }
    }
    
    printf("%.10lf\n", ans);
}
