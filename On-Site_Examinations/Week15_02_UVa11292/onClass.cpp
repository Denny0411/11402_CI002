#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// the number n of heads that the dragon has,
	// and the number m of knights in the kingdom
	int n, m;
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0)
			break;

		vector<int> head(n, 0); // dragon’s heads
		vector<int> height(m, 0); // the heights of the knights

		for (int i = 0; i < n; i++)
			cin >> head.at(i);
		for (int i = 0; i < m; i++)
			cin >> height.at(i);

		int sumOfHeight = 0;
		bool isDoomed = false;

		if (n > m)
			isDoomed = true;
		else
		{
			sort(head.begin(), head.end());
			sort(height.begin(), height.end());

			int headPtr = 0;
			int heightPtr = 0;
			int sumOfHeight = 0;
			while(headPtr < head.size() && heightPtr < height.size())
			{
				/*
				if heightPtr 的騎士 >= headPtr 的龍
					headPtr++
					sumOfHeight += height.at(heightPtr)
					heightPtr++
				else heightPtr 的騎士 < headPtr 的龍
					heightPtr++
				*/
				if (height.at(heightPtr) >= head.at(headPtr))
				{
					headPtr++;
					sumOfHeight += height.at(heightPtr);
					heightPtr++;
				}
				else
				{
					heightPtr++;
				}
			}
			if (headPtr < head.size())
				isDoomed = true;

			if (isDoomed == false)
				cout << sumOfHeight << endl;
			else
				cout << "Loowater is doomed!" << endl;
		}
	}
}

/*
2 4

7
2
-> 2 7

2
1
8
5
-> 1 2 5 8

10 // output
*/