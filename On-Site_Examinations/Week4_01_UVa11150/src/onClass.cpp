#include <iostream>

using namespace std;

int main()
{
	int full = 0;
	int empty = 0;
	int borrow = 0;

	while (cin >> full)
	{
		int sum = 0;

		if (full % 3 == 2)
		{
			full++;
			borrow = 1;
		}

		while (full >= 3)
		{
			sum += full;
			full /= 3;
		}

		cout << sum << endl;
	}
}