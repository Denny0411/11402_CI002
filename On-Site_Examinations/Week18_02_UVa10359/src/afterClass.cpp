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