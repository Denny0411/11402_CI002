# Version 1

```cpp
#include <iostream>

using namespace std;

int func(int n)
{
	int len = 0;
	while (n > 1)
	{
        if (n % 2 == 1)
        {
            n = 3 * n + 1;
            len++;
        }
        else // n % 2 == 0
        {
            n /= 2;
            len++;
        }
	}
    len++;
	return len;
}

int main()
{
	int i = 0;
	int j = 0;
	int currLen = 0;
	int maxLen = 0;

	while (cin >> i >> j)
	{
		cout << i << " " << j << " ";
		for (int count = i; count <= j; count++)
		{
			currLen = func(count); // 獲得當前數字的 cycle-length
			if (maxLen < currLen)
				maxLen = currLen;
		}
		cout << maxLen << endl;
        maxLen = 0; // initializa
	}
}
```

## Result

題目測資通過，wrong answer。

## Analysis

- [x] 目前的程式只能處理 i > j 的情況，不能處理 i < j 的情況。應該要在 i < j 時 swap。

- [x] i 跟 j 應該要是 `unsigned int` 型別，否則可能會 overflow。

# Version 2

```cpp
#include <iostream>

using namespace std;

int func(unsigned int n)
{
	int len = 0;

	while (n > 1)
	{
        if (n % 2 == 1)
        {
            n = 3 * n + 1;
            len++;
        }
        else // n % 2 == 0
        {
            n /= 2;
            len++;
        }
	}

    len++;
	return len;
}

int main()
{
	unsigned int i = 0;
	unsigned int j = 0;
	int currLen = 0;
	int maxLen = 0;

	while (cin >> i >> j)
	{
		cout << i << " " << j << " ";
        
        // deal with i > j
        if (i > j)
        {
            int temp = i;
            i = j;
            j = temp;
        }

		for (unsigned int count = i; count <= j; count++)
		{
			currLen = func(count); // 獲得當前數字的 cycle-length
			if (maxLen < currLen)
				maxLen = currLen;
		}

		cout << maxLen << endl;
        maxLen = 0; // initializa
	}
}
```

## Result

Accepted