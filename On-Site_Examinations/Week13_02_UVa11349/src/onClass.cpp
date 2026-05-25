#include <iostream>

using namespace std;
using LL = long long;

int main()
{
	int t = 0; // number of test cases
	int counter = 0;
	cin >> t;
	while (t--)
	{
		counter++;

		char c1, c2;
		int n = 0; // the dimension of square matrix
		cin >> c1 >> c2 >> n;

		// n * n matrix
		LL** a = new LL* [n];
		for (int i = 0; i < n; i++)
			a[i] = new LL[n];

		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				cin >> a[row][col];
			}
		}

		bool isSymmetric = true;
		for (int row = 0; row < n; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (a[row][col] != a[col][row])
				{
					isSymmetric = false;
					break;
				}
				if (a[row][col] < 0)
				{
					isSymmetric = false;
					break;
				}
			}
			if (isSymmetric == false)
				break;
		}

		cout << "Test #" << counter << ": ";
		if (isSymmetric == true)
			cout << "Symmetric." << endl;
		else
			cout << "Non-symmetric." << endl;
	}
}