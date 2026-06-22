#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, d, r;
	/*
	* n: n bus drivers, n morning bus routes and n afternoon bus routes
	* d: day limit
	* r: 加班費每小時
	*/

	while (cin >> n >> d >> r)
	{
		if (n == 0 && d == 0 && r == 0)
			break;

		vector<int> morning(n);
		vector<int> evening(n);

		for (int i = 0; i < n; i++)
			cin >> morning.at(i);
		for (int i = 0; i < n; i++)
			cin >> evening.at(i);
		sort(morning.begin(), morning.end());
		sort(evening.begin(), evening.end());
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < n; i++)
		{
			int temp;

			// sum1: morning 小到大，evening 大到小
			temp = (morning.at(i) + evening.at(n - 1 - i)) - d;
			if (temp < 0)
				temp = 0;

			sum1 += r * temp;

			// sum2: morning 大到小，evening 小到大
			temp = (morning.at(n - 1 - i) + evening.at(i)) - d;
			if (temp < 0)
				temp = 0;

			sum2 += r * temp;
		}

		if (sum1 <= sum2)
			cout << sum1 << endl;
		else
			cout << sum2 << endl;
	}
}