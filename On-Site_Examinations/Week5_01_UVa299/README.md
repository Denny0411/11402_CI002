# UVa299

## Problem Information

- **Problem Link:** https://onlinejudge.org/external/2/299.pdf

## Description

* bubble sort and counting

## Correct Code

### onClass.cpp

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		int L = 0; // determining the length of the train
		cin >> L;
		int* carriages = new int[L];
		for (int j = 0; j < L; j++)
		{
			cin >> carriages[j];
		}

		// swap
		for (int k = L - 1; k >= 1; k--)
		{
			for (int l = 0; l + 1 <= k; l++)
			{
				if (carriages[l] > carriages[l + 1])
				{
					swap(carriages[l], carriages[l + 1]);
					count++;
				}
			}
		}

		cout << "Optimal train swapping takes " << count << " swaps." << endl;

		delete [] carriages;
	}
}
```

## Analysis

* **結構與記憶體管理 (Structure)：建議汰換指標與動態陣列**
你使用了 `new` 和 `delete[]` 來管理陣列。雖然你有記得釋放記憶體，但在現代的 C++ 開發中，我們強烈建議使用 `std::vector`。它可以自動幫你管理記憶體，不僅語法更簡潔，也能完全避免忘記寫 `delete` 而導致的記憶體洩漏風險。

## Version 1

* 使用 `std::vector` 改寫程式。

### version1.cpp

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		int L = 0; // determining the length of the train
		cin >> L;
		vector<int> carriages(L);
		for (int j = 0; j < L; j++)
		{
			cin >> carriages.at(j);
		}

		// swap
		for (int k = L - 1; k >= 1; k--)
		{
			for (int l = 0; l + 1 <= k; l++)
			{
				if (carriages.at(l) > carriages.at(l + 1))
				{
					swap(carriages.at(l), carriages.at(l + 1));
					count++;
				}
			}
		}

		cout << "Optimal train swapping takes " << count << " swaps." << endl;
	}
}
```