# UVa 10359 - Tiling

## Link

https://onlinejudge.org/external/103/10359.pdf

## onClass

Result: wrong answer

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int wall = 0;
	// long double arr[251];
	vector<long double> arr(251);
	//vector<string> str(251);
	//arr[0] = 1;
	//arr[1] = 1;
	//arr[2] = 3;
	//str.at(0) = "1";
	//str.at(1) = "1";
	//str.at(2) = "3";
	arr.at(0) = 1;
	arr.at(1) = 1;
	arr.at(2) = 3;
	for (int i = 3; i <= 250; i++)
	{
		// arr[i] = 2 * arr[i - 2] + arr[i - 1];
		arr.at(i) = 2 * arr.at(i - 2) + arr.at(i - 1);
		//str.at(i) = to_string(arr.at(i));
		//str.at(i) = to_string(2 * stoi(str.at(i - 2)) + stoi(str.at(i - 1)));
	}

	while (cin >> wall)
	{
		//cout << str.at(wall) << endl;
		cout << arr.at(wall) << endl;
	}
}
```

## Analysis

我已經找到這一題的遞迴模式了，但卻卡在不知道怎麼處理大數。

由於 C++ 沒有內建可以處理無限長度的「大整數（Big Integer）」型別（不像 Python 或 Java），遇到這種結果會超過 19 位數的題目，只能自行處理。

## afterClass

Result: accepted

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// a += b
void add(vector<int>& a, vector<int>& b)
{
	vector<int> result;
	int carry = 0; // 進位
	int i = 0; // index

	while (i < a.size() || i < b.size() || carry != 0)
	{
		int sum = carry; // 每一位的總和先加上進位

		if (i < a.size())
			sum += a.at(i);

		if (i < b.size())
			sum += b.at(i);

		// 將個位數放進結果陣列 (例如總和是 13，只存 3)
		result.push_back(sum % 10);

		// 更新進位 (例如總和是 13，進位就是 1)
		carry = sum / 10;
		i++;
	}

	a = result;
}

int main()
{
	int wall = 0;

	// 二維陣列
	// 每一列 row 是一個大數
	// arr[i][j] 只存放一個數字 digit
	vector<vector<int>> arr(251);

	arr.at(0).push_back(1);
	arr.at(1).push_back(1);
	arr.at(2).push_back(3);

	for (int i = 3; i < 251; i++)
	{
		// f(n) = 2 * f(n - 2) + f(n - 1)
		add(arr.at(i), arr.at(i - 2));
		add(arr.at(i), arr.at(i - 2));
		add(arr.at(i), arr.at(i - 1));
	}

	while (cin >> wall)
	{
		for (int i = arr.at(wall).size() - 1; i >= 0; i--)
		{
			cout << arr.at(wall).at(i);
		}
		cout << endl;
	}
}
```