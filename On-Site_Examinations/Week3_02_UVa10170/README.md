# 教訓

有時候程式是對的，但只是型態宣告得不夠大，導致 overflow 啊！

# On Class

```cpp
#include <iostream>

using namespace std;

bool judge(unsigned int begin, unsigned int end, unsigned int D)
{
	if (begin <= D && D <= end)
		return false;
	else
		return true;
}

int main()
{
	unsigned int S; // denotes the initial size of the group
	unsigned int D;

	while (cin >> S >> D)
	{
		unsigned int peopleNum = S;
		unsigned int beginDay = 1;
		unsigned int endDay = S;

		while (judge(beginDay, endDay, D))
		{
			beginDay += peopleNum;
			endDay = beginDay + peopleNum;
			peopleNum++;
		}
		cout << peopleNum << endl;
	}
}
```

## Result

wrong answer

## Analysis

* input D 為 $1 <= D <= 10^{15}$，目前的 unsigned int 最大只能存到大約 $4.29 \times 10^9$，發生溢位 overflow。

* 把 `unsigned int` 改成 `unsigned long long int` 或是 `long long`

# Version 1

```cpp
#include <iostream>

using namespace std;

bool judge(unsigned int begin, unsigned int end, unsigned long long int D)
{
	if (begin <= D && D <= end)
		return false;
	else
		return true;
}

int main()
{
	unsigned int S; // denotes the initial size of the group
	unsigned long long int D;

	while (cin >> S >> D)
	{
		unsigned int peopleNum = S;
		unsigned int beginDay = 1;
		unsigned int endDay = S;

		// if beginDay <= D && D <= endDay, output peopleNum
		while (judge(beginDay, endDay, D))
		{
			beginDay += peopleNum;
			endDay = beginDay + peopleNum;
			peopleNum++;
		}
		cout << peopleNum << endl;
	}
}
```

## Result

Time limit exceeded

## Analysis

* TLE 的可能：無窮迴圈
* `beginDay` 和 `endDay` 在迴圈中不斷加上 `peopleNum`，很可能就會溢位，導致無窮迴圈
* 全部都要改成 `unsigned long long int`，不要偷懶

# Version 2

```cpp
#include <iostream>

using namespace std;
using ULL = unsigned long long int;

bool judge(ULL begin, ULL end, ULL D)
{
	if (begin <= D && D <= end)
		return false;
	else
		return true;
}

int main()
{
	ULL S; // denotes the initial size of the group
	ULL D;

	while (cin >> S >> D)
	{
		ULL peopleNum = S;
		ULL beginDay = 1;
		ULL endDay = S;

		// if beginDay <= D && D <= endDay, output peopleNum
		while (judge(beginDay, endDay, D))
		{
			beginDay += peopleNum;
			endDay = beginDay + peopleNum;
			peopleNum++;
		}
		cout << peopleNum << endl;
	}
}
```

* `using ULL = unsigned long long int;` 進行縮寫，現代 C++11 之後的推薦做法
* 其他寫法：
```cpp
#define ULL unsigned long long int // C 語言的寫法
typedef unsigned long long int ULL; // 傳統 C/C++ 做法
```

## Result

Accepted