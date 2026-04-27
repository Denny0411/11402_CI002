#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int store = 0;
		cin >> store;
		vector<int> position;
		for (int j = 0; j < store; j++)
		{
			int x = 0;
			cin >> x;
			position.push_back(x);
		}

		sort(position.begin(), position.end());
		//cout << position.front() << " " << position.back() << endl;
		cout << (position.back() - position.front()) * 2 << endl;
	}
}