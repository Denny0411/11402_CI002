#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isOverlap(vector<int> pairwise, int currentTerm)
{
	for (int i = 0; i < pairwise.size(); i++)
	{
		if (pairwise.at(i) == currentTerm)
			return true;
	}
	return false;
}

int main()
{
	int N = 0; //  the number of elements in the sequence
	int casesNum = 0;

	while (cin >> N)
	{
		bool isB2Seq = true;
		casesNum++;
		vector<int> input(N);
		for (int i = 0; i < N; i++)
		{
			cin >> input.at(i);
			if (input.at(i) < 1)
				isB2Seq = false;
			for (int j = 0; j < i; j++)
			{
				if (input.at(i) <= input.at(j)) // input.at(i) > input.at(j)
				{
					isB2Seq = false;
				}
			}
		}
		sort(input.begin(), input.end());
		/*for (int i = 0; i < N; i++)
		{
			cout << input.at(i) << " ";
		}
		cout << endl;*/

		// compare two seq
		// if there is overlap
		// set isB2Seq to false

		vector<int> pairwise;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				int currentTerm = input.at(i) + input.at(j);
				//cout << "currentTerm: " << currentTerm << endl;
				if (isOverlap(pairwise, currentTerm) == true)
				{
					isB2Seq = false;
					break;
				}
				else // isOverlap(pairwise, currentTerm) == false
				{
					pairwise.push_back(currentTerm);
					sort(pairwise.begin(), pairwise.end());
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

比較
b0 + b0
跟之前的結果有相同？
沒有
	push_back
有
	isB2Seq = false
	break
*/