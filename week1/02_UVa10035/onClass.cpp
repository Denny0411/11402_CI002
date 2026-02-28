#include <iostream>

using namespace std;

int func(int num)
{
	int leng = 0;
	while (num >= 1)
	{
		leng++;
		num /= 10;
	}
	return leng;
}

int main()
{
	unsigned int a = 0;
	unsigned int b = 0;

	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;

		int carry = 0;
		int lengA = func(a);
		int lengB = func(b);
		int leng = (lengA >= lengB ? lengA : lengB);

		for (int i = 0; i < leng; i++)
		{
			int digitA = a % 10;
			int digitB = b % 10;

			if (digitA + digitB >= 10)
			{
				carry++;
			}

			a /= 10;
			b /= 10;
		}

		if (carry == 0)
		{
			cout << "No carry operation.\n";
		}
		else if (carry == 1)
		{
			cout << carry << " carry operation.\n";
		}
		else
		{
			cout << carry << " carrys operation.\n";
		}
	}
}