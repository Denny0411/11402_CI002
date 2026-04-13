#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0; //  the number of elements in the sequence
	int casesNum = 0;

	while (cin >> N)
	{
		casesNum++;
		vector<int> input(N);
		for (int i = 0; i < N; i++)
		{
			cin >> input.at(i);
		}

		vector <int> pairwiseSums(N - 1);
		for (int i = 0; i < N - 1; i++)
		{
			pairwiseSums.at(i) = input.at(i) + input.at(i + 1);
		}

		// compare two seq
		// if there is overlap
		// set isB2Seq to false
		bool isB2Seq = true;

		for (int i = 0; i < N; i++) // iterate input
		{
			for (int j = 0; j < N - 1; j++) // iterate pairwiseSums
			{
				if (input.at(i) == pairwiseSums.at(j)) // there is overlap
				{
					isB2Seq = false;
					break;
				}
			}
		}

		if (isB2Seq == true)
		{
			cout << "Case #" << casesNum << ": It is a B2-Sequence." << endl;
		}
		else // isB2Seq == false
		{
			cout << "Case #" << casesNum << ": It is not a B2-Sequence." << endl;
		}

		cout << endl;
	}
}

/*
1. 輸入
	有幾個數字
	每個數字
2. b1 + b2, b2 + b3 ...
3. 2 個數列是否有相同的項？
*/