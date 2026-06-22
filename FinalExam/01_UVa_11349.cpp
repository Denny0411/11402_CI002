#include <iostream>
#include <vector>

using namespace std;

using LL = long long;

int main()
{
	int T = 0;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++)
	{
		bool isSymmetric = true;
		char c1, c2;
		int n = 0;
		cin >> c1 >> c2 >> n;
		vector<vector<LL>> v(n, vector<LL>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> v.at(i).at(j);
				if (v.at(i).at(j) < 0)
					isSymmetric = false;
			}
		}

		
		for (int i = 0; i < n / 2 + 1; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (v.at(i).at(j) != v.at(n - i - 1).at(n - j - 1))
				{
					isSymmetric = false;
					break;
				}
			}
			if (isSymmetric == false)
				break;
		}

		if (isSymmetric == true)
			cout << "Test #" << caseNum << ": Symmetric." << endl;
		else if (caseNum != T)
			cout << "Test #" << caseNum << ": Non-symmetric." << endl;
		else
			cout << "Test #" << caseNum << ": Non-symmetric.";
	}
}