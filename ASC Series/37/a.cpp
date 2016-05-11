#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <bitset>
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
#define MOD 1000000007LL
#define PI 3.1415926535897932384626
#define MAX_PRIME 11111


class Node{
	public:	
		Node *nxt, *prev;
		int data;
	
	Node(){
		this->data = 0;
		this->nxt = NULL;
		this->prev = NULL;
	}
	Node(int info){
		this->data = info;
		this->nxt = this;
		this->prev = this;
	}
	
	Node(int info, Node *pv, Node *nx){
		this->data = info;
		this->nxt = nx;
		this->prev = pv;
	}
	
	Node(int info, Node *pv){
		this->data = info;
		this->nxt = NULL;
		this->prev = pv;
	}
};

class LinkedList{
	public:
	
	Node *first;
	
	LinkedList(){
		this->first = NULL;
	}
	
	Node *push_back(int info){
		Node *ret;
		if(first == NULL){
			ret = new Node(info);
			first = ret;
		}
		else{
			ret = new Node(info, first->prev, first);
			first->prev->nxt = ret;
			first->prev = ret;
		}
		return ret;
	}
	
	Node *back(){
		if(first == NULL) return NULL;
		return first->prev;
	}
	
	void print(){
		if(first != NULL){
			Node *aux = first; int lst = 0;
			do{
				if(aux != first) printf(" ");
				printf("%d", aux->data+1);
				aux = aux->nxt;
			}while(aux != first);
		}
		else printf("//");
		printf("\n");
	}
	
	int size(){
		int ans = 0;
		Node *aux = first;
		if(aux != NULL){
			do{
				ans++;
				aux = aux->nxt;
			}while(aux != first);
		}
		return ans;
	}
	
	~LinkedList(){
		if(first != NULL){
			Node *aux = first, *nxt;
			do{
				nxt = aux->nxt;
				delete aux;
				aux = nxt;
			}while(aux != first);
		}
		
	}
	
} NODE;

int n, N, edgeIdx = 0;
int bst[11000];
int extra[11000];
ii edges[11000];
bitset<11000> used;
LinkedList circuit;
vi ciclePath;
vi g[11000];
Node *firstNode[11000];

void addEdge(int v, int w){
	edges[edgeIdx] = make_pair(min(v,w), max(v, w));
	g[v].push_back(edgeIdx);
	g[w].push_back(edgeIdx);
	edgeIdx++;
}

int otherEnd(int v, int e){
	if(edges[e].first == v) return edges[e].second;
	return edges[e].first;
}

int removeLastEdge(int v){
	while(!g[v].empty() && used[g[v].back()]) g[v].pop_back();
	if(!g[v].empty()){
		int e = g[v].back();
		g[v].pop_back();
		used[e] = true;
		return otherEnd(v, e);
	}
	return -1;
}

void dfs(int v, int t){
	if(v == t) return;
	ciclePath.push_back(v);
	int w = removeLastEdge(v);
	if(w >= 0) dfs(w, t);
}

void addCicle(vi path){
	if(path.empty()) return;
	int x = path[0], y;
	Node *first = firstNode[x];
	if(first == NULL){
		REP(i, path.size()){
			y = path[i];
			first = circuit.push_back(y);
			if(firstNode[y] == NULL) firstNode[y] = first;
		}
	} 
	else{
		Node *last = first->nxt, *prev = first, *aux;
		for(int i = 1; i<path.size(); i++){
			y = path[i];
			aux = new Node(y, prev);
			prev->nxt = aux;
			if(firstNode[y] == NULL) firstNode[y] = aux;
			prev = prev->nxt;
		}
		x = path[0];
		aux = new Node(x, prev, last);
		prev->nxt = aux;
		last->prev = aux;
		if(firstNode[x] == NULL) firstNode[x] = aux;
	}
	
}

int startCicle(int v){
	int w = removeLastEdge(v);
	if(w >= 0){
		ciclePath.push_back(v);
		dfs(w, v);
		addCicle(ciclePath);
		ciclePath.clear();
	}
	return w;
}

void setup(){
	REP(i, 10001){
	    firstNode[i] = NULL;
	    g[i].clear();
	}
	edgeIdx = 0;
	used.reset();
}

int main(){
	CLEAR0(bst);
	CLEAR0(extra);
	freopen("achromatic.in","r",stdin);
    freopen("achromatic.out","w",stdout);
	for(int i = 3; i <= 1000; i++){
		int ed = (i%2)? (i*(i-1))/2 : (i*(i-1))/2 + i/2;
		if(ed > 10001) break;
		bst[ed] = i;
		extra[ed] = 0;
	}
	for(int i = 3; i<= 10001; i++){
		if(bst[i] == 0){
			bst[i] = bst[i-1];
			extra[i] = extra[i-1]+1;
		}
	}
	
	while(scanf(" %d ", &n) != EOF){
		if(n == 3) printf("3\n1 2 3\n");
		else if(n == 4) printf("2\n1 2 1 2\n");
		else{
			N = bst[n];
			if(N%2 && extra[n] == 1) N--;
			printf("%d\n", N);
			setup();
			
			for(int i = 0; i<N; i++)
			for(int j = i+1; j<N; j++) addEdge(i, j);
				
			if(N%2){
				int rem = n-edgeIdx;
				if(rem%2){ addEdge(0, 1); addEdge(1, 2); addEdge(2, 0); rem -= 3; } 
				while(rem > 0){ addEdge(0, 1); rem--; }
				startCicle(0);
				for(int i = 0; i<N; i++) if(firstNode[i] != NULL) while(startCicle(i) >= 0);
			}
			else{
				
				int rem = n-edgeIdx;
				
				int matching = max(0, N-rem), star = min(rem-matching, N-1);
				for(int i = 0; i < matching; i++){ 
					addEdge(2*i, 2*i+1); 
				}
				for(int i = 0; i < star; i++){
					addEdge(0, N-1-i);
				}
					
				rem -= (matching + star);
				if(rem%2){ addEdge(0, 1); addEdge(1, 2); addEdge(2, 0); rem -= 3; } 
				while(rem > 0){ 
					addEdge(0, 1); rem--; 
				}
				startCicle(0);
				for(int i = 0; i<N; i++) if(firstNode[i] != NULL) while(startCicle(i) >= 0);
			}
			circuit.print();
			circuit = LinkedList();
		}
	}
	return 0;
}
