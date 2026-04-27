#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0;
	int S = 0;

	while (cin >> N >> S)
	{
		vector<int> seq;
		int num = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			seq.push_back(num);
		}

		// 從 1 項 到 N 項
		// 0 1 2 3 4
		int min = 0;
		for (int i = 1; i <= N; i++) // 1 to 4
		{
			for (int j = 0; j < N; j++) // 0 to 4
			{
				// begin j, end j + i
				for (int k = j; k < i) // 0 to 0; 0 to 1
			}
		}
	}
}

/*
N positive integers
a positive integer S (S < 100 000 000) are given
the sum of which is greater than or equal to S
minimal length of the subsequence

連續的項要大於等於給定的值，
1: a1, a2, a3...
2: a1+a2, a2+a3 ...
*/