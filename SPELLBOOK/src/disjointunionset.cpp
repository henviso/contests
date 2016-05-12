vi pset;
vi psize;
 
void initSet(int N){
	pset.assign(N, 0);
	psize.assign(N, 1);
	for(int i = 0; i<N; i++) pset[i] = i;
}
 
int findSet(int i){
	return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
 
bool isSameSet(int i, int j){
	return findSet(i) == findSet(j);
}
 
int unionSet(int i, int j){
	if(isSameSet(i,j)) return psize[findSet(j)];
	if(psize[findSet(j)] < psize[findSet(i)]) return unionSet(j, i);
	psize[findSet(j)] += psize[findSet(i)];
	pset[findSet(i)] = findSet(j);
	return psize[findSet(j)];
}
