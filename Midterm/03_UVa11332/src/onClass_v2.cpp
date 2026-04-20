#include <iostream>

using namespace std;
using ULL = unsigned long long;

int digitSum(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	ULL n = 0;

	while (cin >> n)
	{
		if (n == 0)
			break;

		int sum = n;
		do
		{
			sum = digitSum(sum);
		} while (sum >= 10);
		cout << sum << endl;
	}
}