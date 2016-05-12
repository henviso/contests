#define MAX_N 1000010

int B1[MAX_N], B2[MAX_N];

void ft_create(int ft[MAX_N], int n){ CLEAR0(ft); }

int ft_query(int ft[MAX_N], int b){	
	int sum = 0; while(b){ sum += ft[b]; b -= LSOne(b);}
	return sum;
}

void ft_update(int ft[MAX_N], int k, int v){
	while(k <= MAX_N){ ft[k] += v; k += LSOne(k); }
}

int query(int b) {
    return ft_query(B1, b) * b - ft_query(B2, b);
}

int range_query(int i, int j)    {
    return query(j) - query(i - 1);
}

void range_update(int i, int j, ll v)	{
	ft_update(B1, i, v);
	ft_update(B1, j + 1, -v);
	ft_update(B2, i, v * (i - 1));
	ft_update(B2, j + 1, -v * j);
}

----------------------------------------------------

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


/*-----------3D-----------------------------*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 100
long long tree[MAX+10][MAX+10][MAX+10]; /*nao usar posicao em 0*/
int N, M;

long long q(int x, int y, int z) {
    long long sum=0;
    int yy=y, zz = z;
    if (x==0 || y==0 || z == 0) return 0LL;
    while (x) {
        while (y) {
            while (z){
                sum+=tree[x][y][z];
                z-=z & (-z);
            }
            y-=y & (-y);
            z = zz;
        }
        x-=x & (-x);
        y=yy;
    }
    return sum;
}

void update(int x, int y, int z, long long v) {
    int yy=y, zz = z;
    if(x==0 || y==0 || z == 0) return;
    while (x<=MAX) {
        while (y<=MAX) {
            while (z<=MAX){
                tree[x][y][z]+=v;
                z+=z & (-z);
            }
            y+=y & (-y);
            z = zz;
        }
        x+=x & (-x);
        y=yy;
    }
}

long long sum(int r1, int c1, int d1, int r2, int c2, int d2){
    return (q(r2,c2,d2) - q(r1-1,c2,d2) - q(r2,c1-1,d2) + q(r1-1,c1-1,d2) + q(r2,c1-1,d1-1) - q(r2,c2,d1-1) + q(r1-1,c2,d1-1) - q(r1-1,c1-1,d1-1));
}
