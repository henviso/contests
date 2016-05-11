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

#define UNVISITED 0
#define EXPLORED 1
#define VISITED 2
#define ALPHABET_SIZE 3
#define CHAR_TO_INDEX(a) a-'a'

struct trie_node{
    bool value;
    trie_node *children[ALPHABET_SIZE];	
	trie_node(){
		value = false;
	}
};

trie_node *getNode(void){
    trie_node *pNode = NULL;
    pNode = new trie_node(); 
    if( pNode )
    {
        int i;
        pNode->value = 0;
        for(i = 0; i < ALPHABET_SIZE; i++)
        {
            pNode->children[i] = NULL;
        }
    }
    return pNode;
}
 
void initialize(trie_node *pTrie){
    pTrie = getNode();
    pTrie->value = 0;
}
 
void insert(trie_node *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node *pCrawl = pTrie;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] ){
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
    }
 
    // mark last node as leaf
    pCrawl->value = true;
}
 
// Returns non zero, if key presents in trie
bool straight_search(trie_node *pTrie, char key[], int length)
{
    int level;
    int index;
    trie_node *pCrawl = pTrie;

    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if( !pCrawl->children[index] )
        {
            return false;
        }
 
        pCrawl = pCrawl->children[index];
    }
	
	return pCrawl->value;
}

bool search(trie_node *pTrie, char key[], int length){
	int level;
    int index;
    trie_node *pCrawl = pTrie;
 
    for( level = 0; level < length; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
		REP(idx, ALPHABET_SIZE)
			if(pCrawl->children[idx] && idx != index && straight_search(pCrawl->children[idx], &key[level+1], length-(level+1))) 
			return true;
			
        if(!pCrawl->children[index]){
            return false;
        }
        pCrawl = pCrawl->children[index];
    }
    return false;
}
 
int n, m;
char str[600100]; 
trie_node t;
 
int main()
{
    initialize(&t);
 
	scanf(" %d %d ", &n, &m);
	REP(i, n){
		scanf(" %s ", str);
        insert(&t, str);
    }
    REP(i, m){
		scanf(" %s ", str);
        if(search(&t, str, strlen(str))) cout << "YES\n";
        else cout << "NO\n";
	}
 
   
    return 0;
}
