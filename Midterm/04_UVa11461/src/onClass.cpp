#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isSquare(int n)
{
	// bool judge = false;
	int j = static_cast<int>(sqrt(n));

	for (int i = j; i <= j+1; i++)
	{
		if (i * i == n)
			return true;
	}
	return false;
}

int main()
{
	int a = 0;
	int b = 0;

	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
			break;

		if (a > b)
			swap(a, b);

		int sum = 0;
		for (int i = a; i <= b; i++)
		{
			if (isSquare(i) == true)
			{
				sum++;
			}
		}
		cout << sum << endl;
	}
}

/*
input
if a == 0 && b == 0
	break
if a > b
	swap

for i from a to b
	if i is square num
	sum++
output sum

*/