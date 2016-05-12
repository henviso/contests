#define MAXCL 2100
#define MAXV 2100

#define N(x) (2*x + 1)
#define Y(x) (2*x)
#define NEG(x) (x%2 == 1 ? x-1 : x+1) //positive variables has even index and negative variables has odd index 

int x[MAXCL], y[MAXCL]; //clauses
int nc, nv;             //number of clauses and number of variables
int n, m;               //number of vertices and edges of the graph
int numSCC;				
vi g[4*MAXCL], ng[4*MAXCL];  //implication graph and its complement
stack<int> st;
bitset<4*MAXCL> vis;         //bitset to mark visited vertices

int pos[4*MAXCL], comp[4*MAXCL], idx;
bool val[4*MAXCL];

void dfs(int v){
	vis[v] = true;
	REP(i, g[v].size()) if(!vis[g[v][i]]) dfs(g[v][i]);
	st.push(v);
}

void dfs2(int v){
	vis[v] = true;
	REP(i, ng[v].size()) if(!vis[ng[v][i]]) dfs2(ng[v][i]);
	comp[v] = numSCC;
	pos[v] = idx++;
}

bool twoSat(){
	numSCC = 0;
	vis.reset();
	REP(i, V) if(!vis[i]) dfs(i);
	vis.reset();
	idx = 0;
	while(!st.empty()){
		int v = st.top(); st.pop();
		if(!vis[v]){
			numSCC++;
			dfs2(v);
		}
	}
	REP(i, nv){
		if(comp[Y[i]] == comp[N[i]]) return false;
		val[Y[i]] = (pos[Y[i]] > pos[N[i]]);
		val[N[i]] = !val[Y[i]];
	}
	return true;
}
