#include <iostream>

using namespace std;
using ULL = unsigned long long;

ULL func(ULL n)
{
	ULL sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	
	if (sum >= 10)
	{
		return func(sum);
	}
	else // sum < 10
	{
		return sum;
	}
}

int main()
{
	ULL n = 0;

	while (cin >> n)
	{
		if (n == 0)
			break;

		int sum = func(n);
		cout << sum << endl;
	}
}

/*
輸入
遞迴
	拆成 digits
	sum += digits
	if sum < 10
	return sum
	else
	f()

輸入
拆成 digit
如果 
*/