#define MAXV 110 //COMPLEXIDADE O(V*E^2)

int g[MAXV][MAXV], grau[MAXV], n, m, res[MAXV][MAXV]; //PREENCHER
int mf, f, s, t, p[MAXV];
bitset<MAXV> vis;

void augment(int v, int minEdge, int totalW){
	if(v == s){ f = minEdge; return; }
	else if(p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]), totalW + g[p[v]][v]);
		res[p[v]][v] -= f; //cout << " DIMINUINDO ARESTA " << p[v] << " " << v << " EM " << f << endl;
		res[v][p[v]] += f;
	}
}

int maxflow(){
	mf = 0;
	while(1){		
		f = 0; 		//cout << "INICIANDO NOVO FLUXO " << endl;
		vis.reset(); vis[s] = true; CLEAR(p, -1);
		int q[MAXV+10], ini, fim;
		ini = fim = 0; q[fim++] = s;
		while(ini != fim){
			int u = q[ini++]; //cout << "visitando vertice " << u << " E T EH " << t << endl;
			if(u == t) break;
			REP(i, grau[u]){
				int v = g[u][i];
				//cout << "tentando ir pra " << v << " no residual, peso eh " << res[u][v] << " VIS EH " << vis[v] << endl;
				if(res[u][v] > 0 && !vis[v]){
					vis[v] = true; q[fim++] = v; p[v] = u;
					//cout << " COLOCANDO " << v << " NA FILA " << endl;
				}
			}
		} 
		augment(t, INF, 0);
		if(f == 0) break;
		mf += f;
	}
	return mf;
}

int main(){ //EXEMPLO
	scanf(" %d ", &n);
	if(n == 0) break;
	scanf(" %d ", &m);
	s = 1;
	t = n;
	
	CLEAR0(g); CLEAR0(grau); CLEAR0(res); 
	
	int u, v, x;
	REP(i, m){
		scanf(" %d %d %d ", &u, &v, &x);
		res[u][v] = res[v][u] = x;
		g[u][grau[u]++] = v;
		g[v][grau[v]++] = u;
	}
	printf("%d\n", maxflow());
}

