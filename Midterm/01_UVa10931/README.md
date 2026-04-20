# UVa 10931 - Parity

## Link

https://onlinejudge.org/external/109/10931.pdf

## onClass

### Thinking Logic and Solution Strategy

```
binary form
num of '1' digit
```

### Code

```cpp
#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

int main()
{
	LL I = 0;

	while (cin >> I)
	{
		if (I == 0)
			break;

		vector<int> digits;

		while (I >= 1)
		{
			if (I % 2 == 0)
			{
				digits.push_back(0);
				
			}
			else // ( I % 2 == 1)
			{
				digits.push_back(1);
			}
			I /= 2;
		}

		int sum = 0;
		for (int i = 0; i < digits.size(); i++)
		{
			if (digits.at(i) == 1)
				sum++;
		}

		cout << "The parity of ";
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			cout << digits.at(i);
		}
		cout << " is " << sum << " (mod 2)." << endl;
	}
}
```

## Analysis

這一題有在之前出現過，所以沒遇到什麼問題。

參考 [Week6_01_UVa10931](../../On-Site_Examinations/Week6_01_UVa10931/README.md)。