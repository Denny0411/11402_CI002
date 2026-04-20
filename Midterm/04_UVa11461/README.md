# UVa 11461 - Square Numbers

## Link

https://onlinejudge.org/external/114/11461.pdf

## onClass

### Thinking Logic and Solution Strategy

```
input
if a == 0 && b == 0
	break
if a > b
	swap

for i from a to b
	if i is square num
	sum++
output sum
```

### Code

Result: accepted

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool isSquare(int n)
{
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
```

## Analysis

記得當時寫這一題時有幾次 TLE，因為 `bool isSquare(int n)` 計算根號算得太慢了。我記得我最一開始是寫 `for (int i = 2; i <= n / 2; i++)`，但其實不需要算那麼多次。

我們可以先對 `n` 開根號取整數。

```cpp
int j = static_cast<int>(sqrt(n));
```

只要 `j` 的平方跟 `j + 1` 的平方不是 `n` 的話，`n` 就不是平方數。

* **$O(1)$ 的數學解法**

>目前的程式碼使用了一個 `for` 迴圈，從 `a` 檢查到 `b`，並呼叫 `isSquare` 檢查每一個數字。雖然題目限制 $a$ 和 $b$ 最大到 100000，且測資最多只有 201 行，這樣的 $O(N)$ 迴圈（N 為 a 到 b 的區間長度）是有可能通過的。但我們可以做得更好、更有效率！
>
>我們其實不需要用迴圈一個一個去檢查數字是不是平方數。我們可以利用簡單的數學性質，一口氣算出區間內有幾個平方數！
>
>**運作方式與邏輯：**
>* 從 `1` 到 `X` 之間，總共有 $\lfloor\sqrt{X}\rfloor$ （對 X 開根號後無條件捨去）個平方數。例如：從 1 到 10 之間，$\lfloor\sqrt{10}\rfloor = 3$，也就是有 1, 4, 9 這三個平方數。
>* 如果我們想知道 `a` 到 `b` 之間有幾個平方數，我們只需要計算：**「1 到 b 的平方數總數」減去「1 到 a-1 的平方數總數」**。
>* 也就是說，公式為：`floor(sqrt(b)) - floor(sqrt(a - 1))`。
>
>**優點：**
>這樣做的話，不論區間有多大，我們每次只要算兩次平方根並相減即可。時間複雜度會從原本的 $O(N)$ 大幅降到 $O(1)$（常數時間），程式執行會飛快！
>
> written by gemini