#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	int B = 0;
	int H = 0;
	int W = 0;

	while (cin >> N >> B >> H >> W)
	{
		vector<int> P(H);
		vector<vector<int>> A;
		A.resize(H);
		for (int i = 0; i < H; i++)
			A.at(i).resize(W);

		for (int i = 0; i < H; i++)
		{
			cin >> P.at(i);
			for (int j = 0; j < W; j++)
			{
				cin >> A.at(i).at(j);
			}
		}

		// count min price
		// 1. 看哪個旅館能夠住，床數夠多
		// 2. 都夠就比較價格
		vector<int> price;
		int min = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (A.at(i).at(j) >= N && N * P.at(i) < B)
				{
					// 計算價格並 push
					price.push_back(N * P.at(i));
					//cout << N * P.at(i) << endl;
				}
			}
		}

		sort(price.begin(), price.end());
		if (price.size() == 0)
			cout << "stay home" << endl;
		else
			cout << price.at(0) << endl;
	}
}

/*
N: the number of participants 人數
B: budget
H: the number of hotels to consider
W: the number of weeks you can choose between

P:  the price for one person staying the weekend at the hotel
A:  the number of available beds for each weekend at the hotel

Output:
minimum cost of the stay
or "stay home"

** All participants must stay at the same hotel **
*/