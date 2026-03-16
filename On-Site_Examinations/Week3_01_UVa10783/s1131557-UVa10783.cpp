#include <iostream>

using namespace std;

int main()
{
	int T;
	int a;
	int b;

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		int sum = 0;

		cin >> a;
		cin >> b;
		
		for (int j = a; j <= b; j++)
		{
			if (j % 2 == 1)
			{
				sum += j;
			}
		}

		cout << "Case " << i << ": " << sum << endl;
	}
}