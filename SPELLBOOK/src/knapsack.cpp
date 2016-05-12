#include <iostream>
#define MAT(a, b) *(mem + (a) * (cap + 1) + b)
#define PRECO(a) pesos[0][0]
#define PESO(a) pesos[0][1]
#define PRECOK(a) *(pesos + (a) * 2)
#define PESOK(a) *(pesos + (a) * 2 + 1)

using namespace std;

int cap;

int knapsack(int n, int *mem, int *pesos)
{
	int max, maxgeral = 0;
	for(int i = 1; i<n; i++)
	{
		for(int j = 0; j<cap+1; j++)
		{
			max = MAT(i-1, j);
			if(j-PESOK(i) > -1 && MAT(i-1, j-PESOK(i)) != -1)
			{
				if( (MAT(i-1, j-PESOK(i)) + PRECOK(i)) > max ) 
					max = MAT(i-1, j-PESOK(i)) + PRECOK(i);
			}
			MAT(i, j) = max;
			if(MAT(i, j) > maxgeral) maxgeral = MAT(i,j);
		}
	}
	return maxgeral;
}

int main()
{
	int n;
	cin >> n;
	while(n)
	{
		int pesos[n][2];
		for(int i = 0; i<n; i++)
		{
			cin >> pesos[i][0] >> pesos[i][1];
		}
		cin >> cap;
		int mem[n][cap+1];
		for(int i = 0; i<n; i++){ mem[i][0] = 0; for(int j = 1; j<cap+1; j++) mem[i][j] = -1; };
		mem[0][PESO(0)] = PRECO(0);
	
		cout << knapsack(n, &mem[0][0], &pesos[0][0]) << endl;
		cin >> n;
	}
}

