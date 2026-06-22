#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int c; // the number of chambers in the centrifuge 離心機
	int s; // the number of specimens 樣本
	int count = 0;
	while (cin >> c >> s)
	{
		count++;
		vector<int> specimen(s);
		for (int i = 0; i < s; i++)
		{
			cin >> specimen.at(i);
		}
		sort(specimen.begin(), specimen.end());
		vector<vector<int>> ans()
		// case 1: s % c == 1

		// case 2: s % c == 0

		// IMBALANCE
	}
}