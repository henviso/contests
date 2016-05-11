#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
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
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector< ii > vii;
///////////////////////////////UTIL/////////////////////////////////
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define COPY(a, b) memcpy(a, b, sizeof(a))
#define CMP(a, b) memcmp(a, b, sizeof(a))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define LSOne(S) (S & (-S)) 
/////////////////////////////NUMERICAL//////////////////////////////
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MOD 1000000007LL
#define MAX_N 1000010
//__builtin_popcount(m)
//scanf(" %d ", &t);

#define LSOne(S) (S & (-S))
using namespace std;

typedef long long ll;


double n, l;
double p

int main(){
	scanf(" %d ", &t);
	ft_create(B1, 1000010);
	ft_create(B2, 1000010);
	while(t--){
		scanf(" %d ", &n);
		blocked.reset();
		h.clear();
		v.clear();
		REP(i, n){
			scanf(" %d %d %d %d ", &x[i].first, &y[i].first, &x[i].second, &y[i].second);
			x[i].first++; x[i].second++; y[i].first++; y[i].second++;
			if(x[i].first > x[i].second) swap(x[i].first, x[i].second);
			if(y[i].first > y[i].second) swap(y[i].first, y[i].second);
			v[x[i].first].push_back(i);
			if(x[i].second != x[i].first) v[x[i].second].push_back(i);
			h[y[i].first].push_back(i);
			if(y[i].second != y[i].first) h[y[i].second].push_back(i);
		}
		for(map<int, vi>::iterator i = v.begin(); i != v.end(); i++){
			REP(j, i->second.size()){
				int k = i->second[j];
				int q = (x[k].first == i->first) + (x[k].second == i->first);
				range_update(y[k].first, y[k].second, q);
			}
			REP(j, i->second.size()){	
				int k = i->second[j];
				int q = (x[k].first == i->first) + (x[k].second == i->first);
				if(range_query(y[k].first, y[k].second) != ((y[k].second-y[k].first+1)*q)){
					blocked[k] = true;
				}
			}
			REP(j, i->second.size()){
				int k = i->second[j];
				int q = (x[k].first == i->first) + (x[k].second == i->first);
				range_update(y[k].first, y[k].second, -q);
			}
		}
		for(map<int, vi>::iterator i = h.begin(); i != h.end(); i++){
			REP(j, i->second.size()){
				int k = i->second[j];
				int q = (y[k].first == i->first) + (y[k].second == i->first);
				range_update(x[k].first, x[k].second, q);
			}
			REP(j, i->second.size()){
				int k = i->second[j];
				int q = (y[k].first == i->first) + (y[k].second == i->first);
				if(range_query(x[k].first, x[k].second) != ((x[k].second-x[k].first+1)*q)){
					blocked[k] = true;
				}
			}
			REP(j, i->second.size()){
				int k = i->second[j];
				int q = (y[k].first == i->first) + (y[k].second == i->first);
				range_update(x[k].first, x[k].second, -q);
			}
		}
		int ans = 0;
		REP(i, n) if(!blocked[i]) ans++;
		printf("%d\n", ans);
	}
}
