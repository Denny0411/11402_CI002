#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int T = 0; // test cases
	cin >> T;
	while (T--)
	{
		int r = 0; // number of relatives
		set<int> numSet;

		cin >> r;
		vector<int> s(r, 0); // street numbers
		vector<int> s_noRepeat;
		for (int i = 0; i < s.size(); i++)
		{
			cin >> s.at(i);
			bool isRepeat = false;
			for (int j = 0; j < s_noRepeat.size(); j++)
			{
				if (s.at(i) == s_noRepeat.at(j))
				{
					isRepeat == true;
					break;
				}
			}
			if (isRepeat == false)
				s_noRepeat.push_back(s.at(i));
		}

		//// sort set
		//sort(numSet.begin(), numSet.end());
		//// int midIndex = numSet.size() / 2;
		//size_t midIndex = numSet.size() / 2;
		//auto mid = numSet.find(midIndex);

		sort(s_noRepeat.begin(), s_noRepeat.end());
		int mid = s_noRepeat.at(s_noRepeat.size() / 2);

		// abs
		int minSum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			minSum += abs(mid - s.at(i));
		}

		cout << minSum << endl;
	}
}

/*
sort vector
find mid index
calculate abs
*/