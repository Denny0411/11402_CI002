# Version 1

```cpp
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string input[100];
	int row = 0;

	while (getline(cin, input[row]))
	{
		row++;
	}

	int max = 0;
	for (int i = 0; i < 100; i++)
	{
		if (max < input[i].size())
		{
			max = input[i].size();
		}
	}

	for (int i = 0; i < 100; i++)
	{
		input[i].resize(max);
	}

	for (int i = 0; i <= max; i++)
	{
		for (int j = row - 1; j >= 0; j--)
		{
			cout << input[j][i];
		}
		cout << endl;
	}
}
```

Runtime error

## Analysis

* `for (int i = 0; i <= max; i++)` 這部分會導致 segmentation fault，應該要改成 `i < max`。
* 在 C++ 中，`string.resize(n)` 如果沒有指定第二個參數，預設會補上 `\0` (空字符, null character)，而不是空白鍵 `' '`。
* string resize 第二個參數可以指定填充用的字元。

# Version 2

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input[100];
	int row = 0;

	while (getline(cin, input[row]))
	{
		row++;
	}

	int max = 0;
	for (int i = 0; i < 100; i++)
	{
		if (max < input[i].size())
		{
			max = input[i].size();
		}
	}

	for (int i = 0; i < 100; i++)
	{
		input[i].resize(max, ' ');
	}

	for (int i = 0; i < max; i++)
	{
		for (int j = row - 1; j >= 0; j--)
		{
			cout << input[j][i];
		}
		cout << endl;
	}
}
```

Runtime error

## Analysis

* 如果輸入正好有 100 句，目前的程式會不會 out of boundary？
* 0 - 99 放完句子，需要有空間放 EOF。
* 不要把 input 的大小卡的那麼死。

# Version 3

* 只是把 `string input[100];` 改成 `string input[101];`。

Accepted