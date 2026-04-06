#include <iostream>
#include <vector>

using namespace std;

using LL = unsigned long long int;

int main()
{
	LL I;
	while (cin >> I)
	{
		if (I == 0)
			break;

		int parity = 0;
		vector<int> digit;

		// turn into binary
		while (I >= 1)
		{
			digit.push_back(I % 2);
			if (I % 2 == 1)
				parity++;

			I /= 2;
		}

		// output
		cout << "The parity of ";
		for (int i = digit.size() - 1; i >= 0; i--)
		{
			cout << digit.at(i);
		}
		cout << " is " << parity << " (mod 2)." << endl;
	}
}

/*
* 將輸入轉換成二進制
* 計算該二進制中 digit 1 的數量
*/