#include <iostream>
#include <algorithm>

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
		int* carriages = new int[L];
		for (int j = 0; j < L; j++)
		{
			cin >> carriages[j];
		}

		// swap
		for (int k = L - 1; k >= 1; k--)
		{
			for (int l = 0; l + 1 <= k; l++)
			{
				if (carriages[l] > carriages[l + 1])
				{
					swap(carriages[l], carriages[l + 1]);
					count++;
				}
			}
		}

		cout << "Optimal train swapping takes " << count << " swaps." << endl;

		delete [] carriages;
	}
}