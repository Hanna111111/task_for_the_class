#include <bits/stdc++.h>
using namespace std;
#include <iostream>

const int MAX = 100;

void luDecomposition(int mat[][MAX], int n)
{
	int lower[n][n], upper[n][n];
	memset(lower, 0, sizeof(lower));
	memset(upper, 0, sizeof(upper));

	// Decomposing matrix into Upper and Lower
	// triangular matrix
	for (int i = 0; i < n; i++)
	{
		// Upper Triangular
		for (int k = i; k < n; k++)
		{
			// Summation of L(i, j) * U(j, k)
			int sum = 0;
			for (int j = 0; j < i; j++)
				sum += (lower[i][j] * upper[j][k]);

			// Evaluating U(i, k)
			upper[i][k] = mat[i][k] - sum;
		}

		// Lower Triangular
		for (int k = i; k < n; k++)
		{
			if (i == k)
				lower[i][i] = 1; // Diagonal as 1
			else
			{
				// Summation of L(k, j) * U(j, i)
				int sum = 0;
				for (int j = 0; j < i; j++)
					sum += (lower[k][j] * upper[j][i]);

				// Evaluating L(k, i)
				lower[k][i]	= (mat[k][i] - sum) / upper[i][i];
			}
		}
	}


	/*// output it for displaying nicely
	cout << setw(6) << "	 Lower Triangular"
		<< setw(32)
		<< "Upper Triangular" << endl;
*/

	// Lower :
	cout << "Lower: "<< endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout  << lower[i][j] << "\t ";
		    }
		cout << endl ;
	}
	
	cout << "----------------------" << endl;

		// Upper
		cout << "Upper: "<< endl;
		for (int i = 0; i < n; i++){
		    for (int j = 0; j < n; j++){
			cout << upper[i][j] << "\t";
	            }
		cout <<endl;
	}
}
int main(){
	int mat[][MAX]
		= { { 1, 3, 4, 6 },
		    { 2, 3, 4, 5 },
		    { 2, 1, 2, 1 },
		    {-1, 2, -4, 6}};

	luDecomposition(mat, 4);
	return 0;
}
