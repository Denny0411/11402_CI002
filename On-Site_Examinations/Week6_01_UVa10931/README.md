# UVa 10931 – Parity

## Link

https://onlinejudge.org/external/109/10931.pdf

## Thinking Logic and Solution Strategy

* 將輸入轉換成二進制
* 計算該二進制中 digit 1 的數量

## Code

onClass.cpp: accepted

```cpp
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
```

## Reflection

* `digit` 這個變數如果改成複數形式 `digits` 或是 `binaryDigits` 會更貼切，因為這個 Vector 裡面儲存了「多個」位數。

### Unsolved: 使用位元運算子 (Bitwise Operators) 解題

* 雖然你現在使用 `% 2`（取餘數）和 `/ 2`（除法）在邏輯上完全正確，但因為這題的本質是在探討「二進制 (Binary)」，在 C/C++ 中，處理二進制最直接、最道地且執行速度最快的方式是使用位元運算子。
* `% 2` 其實可以透過「位元 AND (`&`)」來達成。
* `/ 2` 其實可以透過「位元向右位移 (`>>`)」來達成。