#include <iostream>

using namespace std;

int func(int n)
{
	int len = 0;
	while (n > 1)
	{
		if (n % 2 == 1)
		{

		}
		else if (n % 2 == 0)
		{

		}
	}
	return len;
}

int main()
{
	int i = 0;
	int j = 0;
	int len = 0;
	int maxLen = 0;

	while (cin >> i >> j)
	{
		cout << i << " " << j << " ";
		for (int count = i; count <= j; count++)
		{
			len = func(count);
			if (maxLen < len)
				maxLen = len;
		}
		cout << maxLen << endl;
	}
}