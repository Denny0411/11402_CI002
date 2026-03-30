#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		int L = 0; // determining the length of the train
		cin >> L;
		vector<int> carriages(L);
		for (int j = 0; j < L; j++)
		{
			cin >> carriages.at(j);
		}

		// swap
		for (int k = L - 1; k >= 1; k--)
		{
			for (int l = 0; l + 1 <= k; l++)
			{
				if (carriages.at(l) > carriages.at(l + 1))
				{
					swap(carriages.at(l), carriages.at(l + 1));
					count++;
				}
			}
		}

		cout << "Optimal train swapping takes " << count << " swaps." << endl;
	}
}