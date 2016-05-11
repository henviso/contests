#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cstring>

#define ALL(x) (x).begin(),x.end()
#define CLEAR(v, x) memset(v, x, sizeof(v))
#define CLEAR0(v) memset(v, 0, sizeof(v))
#define REP(i,n) for(int i = 0; i<n; i++)
#define REPP(i,a,n) for(int i = a; i<n; i++)
#define REPD(i,n) for(int i = n-1; i>-1; i--)
#define EPS 1e-9

using namespace std;

class GraphWalkWithProbabilities {
	public:
	
	double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start) {
		int n = graph.size();
		double mAdj[100][100];
		double cAdj[100][100];
		REP(i, n) REP(j, n) 
		if(graph[i][j]){
			mAdj[i][j] = 0.0; 
			cAdj[i][j] = 1.0;
		    //(((double) winprob[i])/100.0);
		    //cAdj[i][j] = (100.0 - winprob[i] - looseprob[i]) / 100.0; 
		}
		else mAdj[i][j] = cAdj[i][j] = 10e10;
		REP(i, n) REP(j, n){
			if(i == j) continue;
			double pj = ((double) winprob[j]) / (winprob[j]+looseprob[j]);
			REP(k, n){
				double wt = (((double) winprob[k])/100.0);
				double nt = ((100.0 - winprob[k] - looseprob[k]) / 100.0);
				if(nt == 0) continue;
				if(mAdj[i][j]+cAdj[i][j]*pj+EPS < mAdj[i][k]+mAdj[k][j]+wt + cAdj[i][k]*cAdj[k][j]*nt*pj){
					mAdj[i][j] = mAdj[i][k]+mAdj[k][j]+wt;
					cAdj[i][j] = cAdj[i][k]*cAdj[k][j]*nt;
				}
			}
		}
		double ans = -10e10;
		REP(i, n){
			double pi = ((double) winprob[i]) / (winprob[i]+looseprob[i]);
			double proba = mAdj[Start][i] + cAdj[Start][i]*pi;
			cout << " PROBA " << proba << endl;
			if(proba - EPS < 1.0) ans = max(ans, proba);
			cout << mAdj[Start][i] << " " << cAdj[Start][i] << " " << pi << "\n";
		}
		return ans;
	}
};
