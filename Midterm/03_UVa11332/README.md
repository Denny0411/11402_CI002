# UVa 11332 - Summing Digits

## Link

https://onlinejudge.org/external/113/11332.pdf

## onClass_v1-1: recursive version

### Thinking Logic and Solution Strategy

```
輸入
遞迴
	拆成 digits
	sum += digits
	if sum < 10
	return sum
	else
	f()
```

### Code

Result: runtime error

```cpp
#include <iostream>

using namespace std;
using ULL = unsigned long long;

ULL func(ULL n)
{
	ULL sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	
	if (sum >= 10)
	{
		func(sum);
	}
	else // sum < 10
	{
		return sum;
	}
}

int main()
{
	ULL n = 0;

	while (cin >> n)
	{
		if (n == 0)
			break;

		int sum = n;
		do
		{
			sum = func(sum);
		} while (sum >= 10);
		cout << sum << endl;
	}
}
```

## Analysis 1-1

我記得考試時我的遞迴版本是範例測資正確，判決錯誤。而現在以上這份整理後的版本是連範例測資都錯誤了。

* **錯誤：函式回傳值**

在 `ULL func(ULL n)` 中：

```cpp
if (sum >= 10)
{
    func(sum);
}
```

我這裡想要讓程式做遞迴，但是我沒有寫、處理回傳值，這會導致「未定義行為」（Undefined Behavior）。

這裡我把程式改成：
```cpp
if (sum >= 10)
{
    return func(sum);
}
```

這才是遞迴寫法的正確寫法。修改後，範例測資的運行就正確了。

* 邏輯架構最佳化

```cpp
do
{
    sum = func(sum);
} while (sum >= 10);
```

在 `main()` 中，這個部分會跑條件為 `sum >= 10` 的迴圈。但是，在 `ULL func(ULL n)` 中：
```cpp
if (sum >= 10)
{
    return func(sum);
}
```

這個部分也在做一樣的事情：`sum >= 10` 就繼續跑，直到 `sum < 10` 回傳。
既然 version 1 要用遞迴的解法，那 `do...while()` 迴圈是可以不用的。因為 `func(sum)` 回傳的值就一定是小於 10 的。

## onClass_v1-2: recursive version

### Code

Result: accepted

```cpp
#include <iostream>

using namespace std;
using ULL = unsigned long long;

ULL func(ULL n)
{
	ULL sum = 0;

	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	
	if (sum >= 10)
	{
		return func(sum);
	}
	else // sum < 10
	{
		return sum;
	}
}

int main()
{
	ULL n = 0;

	while (cin >> n)
	{
		if (n == 0)
			break;

		int sum = func(n);
		cout << sum << endl;
	}
}
```

## onClass_v2: iterative version

### Code

Result: accepted

```cpp
#include <iostream>

using namespace std;
using ULL = unsigned long long;

int digitSum(int n)
{
	int sum = 0;
	while (n > 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main()
{
	ULL n = 0;

	while (cin >> n)
	{
		if (n == 0)
			break;

		int sum = n;
		do
		{
			sum = digitSum(sum);
		} while (sum >= 10);
		cout << sum << endl;
	}
}
```

## Analysis 2

* **資料型態的一致性**

```cpp
int sum = n;
```

應該要改成：

```cpp
ULL sum = n;
```

比較好。

* **$O(1)$ 數學最佳化解法（數字根 Digital Root）**

>這題有一個非常厲害的數學特性！在十進位系統中，一個整數的「各位數總和」最後化簡成的一位數字，其實就等於「這個數字除以 9 的餘數」（這在數學上稱為數字根）。
>
>**運作邏輯：**
>* 如果 $n$ 可以被 9 整除，那麼它的數字根就是 9（例如：$18 \rightarrow 1+8=9$）。
>* 如果 $n$ 不能被 9 整除，那麼數字根就是 $n \div 9$ 的餘數（例如：$11 \rightarrow 1+1=2$，而 $11 \pmod 9 = 2$）。
>
>**公式推導：**
>為了用一行程式碼處理所有情況（包含剛好是 9 的倍數），我們可以使用這個小技巧：
`答案 = (n - 1) % 9 + 1`
>
>**為什麼這樣寫？**
>假設 $n = 18$：`(18 - 1) % 9 + 1` $\rightarrow$ `17 % 9 + 1` $\rightarrow$ `8 + 1` $\rightarrow$ `9`。
>假設 $n = 11$：`(11 - 1) % 9 + 1` $\rightarrow$ `10 % 9 + 1` $\rightarrow$ `1 + 1` $\rightarrow$ `2`。
>這樣就能完美避開餘數為 0 的情況！
>
> written by gemini