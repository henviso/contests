#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t;
vi g[1000100];

int main() {
    scanf(" %d ", &t);
    while(t--){
        scanf(" %d ", &n);
        if(n == 2){ printf("1 2\n"); continue; }
        if(n%2){
            ans[0] = n/2 + 1;
            int x = n/2, inc = 0, p = 1;
            while(p < n){
                ans[p] = x-inc;
                ans[p+1] = x + inc + 2;
                p += 2;
                inc++;
            }
        }
        else{
            int x = n/2, inc = 0, p = 0;
            while(p < n){
                ans[p] = x-inc;
                ans[p+1] = x + inc + 1;
                p += 2;
                inc++;
            }
        }
        printf("%d", ans[0]);
        for(int i = 1; i<n; i++) printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}
