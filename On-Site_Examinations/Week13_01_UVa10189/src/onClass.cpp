#include <iostream>
#include <string>

using namespace std;

int calc(int** a, const int &row, const int &col, const int &m, const int &n)
{
	int rowBegin = 0;
	int rowEnd = row;
	int colBegin = 0;
	int colEnd = col;
	int sum = 0;

	if (row > 0)
		rowBegin = row - 1;
	if (col > 0)
		colBegin = col - 1;
	if (row < m - 1)
		rowEnd = row + 1;
	else
		rowEnd = m - 1;
	if (col < n - 1)
		colEnd = col + 1;
	else
		colEnd = n - 1;

	for (int i = rowBegin; i <= rowEnd; i++)
	{
		for (int j = colBegin; j <= colEnd; j++)
		{
			if (i == row && j == col)
				continue;

			sum += a[i][j];
		}
	}

	return sum;
}

int main()
{
	int m, n;
	int caseCounter = 0;
	while (cin >> m >> n)
	{
		if (m == 0 && n == 0)
			break;
		caseCounter++;

		int** a = new int* [m];
		for (int i = 0; i < m; i++)
			a[i] = new int[n];

		// input
		for (int row = 0; row < m; row++)
		{
			string rowInput;
			cin >> rowInput;
			for (int col = 0; col < n; col++)
			{
				if (rowInput.at(col) == '*')
					a[row][col] = 1;
				else
					a[row][col] = 0;
			}
		}

		cout << "Field #" << caseCounter << ":" << endl;
		for (int row = 0; row < m; row++)
		{
			for (int col = 0; col < n; col++)
			{
				if (a[row][col] == 1)
					cout << "*";
				else
				{
					// output number
					cout << calc(a, row, col, m, n);
				}
			}
			cout << endl;
		}

		cout << endl;
	}
}

/*
if a[row][col] = 1
	cout << *
else
	cout number
*/