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
        bool isSymmetric = true;

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
                if (a[row][col] < 0)
                    isSymmetric = false;
			}
		}

		for (int row = 0; row <= n / 2; row++) // 只需檢查上半部
		{
			for (int col = 0; col < n; col++)
			{
				if (a[row][col] != a[n - 1 - row][n - 1 - col])
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