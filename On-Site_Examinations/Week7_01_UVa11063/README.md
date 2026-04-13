# UVa 11063 - B2-Sequence

## Link

https://onlinejudge.org/external/110/11063.pdf

## onClass_v1

### Thinking Logic and Solution Strategy

```
1. 輸入
	有幾個數字
	每個數字
2. b1 + b2, b2 + b3 ...
3. 2 個數列是否有相同的項？
```

Result: Wrong Answer

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0; //  the number of elements in the sequence
	int casesNum = 0;

	while (cin >> N)
	{
		casesNum++;
		vector<int> input(N);
		for (int i = 0; i < N; i++)
		{
			cin >> input.at(i);
		}

		vector <int> pairwiseSums(N - 1);
		for (int i = 0; i < N - 1; i++)
		{
			pairwiseSums.at(i) = input.at(i) + input.at(i + 1);
		}

		// compare two seq
		// if there is overlap
		// set isB2Seq to false
		bool isB2Seq = true;

		for (int i = 0; i < N; i++) // iterate input
		{
			for (int j = 0; j < N - 1; j++) // iterate pairwiseSums
			{
				if (input.at(i) == pairwiseSums.at(j)) // there is overlap
				{
					isB2Seq = false;
					break;
				}
			}
		}

		if (isB2Seq == true)
		{
			cout << "Case #" << casesNum << ": It is a B2-Sequence." << endl;
		}
		else // isB2Seq == false
		{
			cout << "Case #" << casesNum << ": It is not a B2-Sequence." << endl;
		}

		cout << endl;
	}
}
```

## Analysis 1

我一開始認知的 B2-Sequence 是錯誤的。

舉例來說，如果數列是：
```
1 2 4 8
```

可以得到該數列的 pairwise sum sequence：
```
1+2 2+4 4+8
=> 3 6 12
```
如果 2 個數列的項有重疊的話，該數列就不是 B2-Sequence。
反之，如果 2 個數列的項沒有重疊的話，該數列就是 B2-Sequence。

因此：
```
1 2 4 8
=> 3 6 12
```
是 B2-Sequence。

```
3 7 10 14
=> 10 17 24
```
不是 B2-Sequence。

但是，這裡對 B2-Sequence 的理解錯了，以上對 B2-Sequence 的理解是錯誤的。

## onClass_v2

### Thinking Logic and Solution Strategy

```
1. 輸入
	有幾個數字？
2. for i from 0 to end of the sequence
       for j from 0 to i
           bi + bj
3. bi + bj 是否有相同的項？

比較
bi + bj
跟之前的結果有相同？
沒有
	push_back
有
	isB2Seq = false
	break
```

Result: Accepted

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isOverlap(vector<int> pairwise, int currentTerm)
{
	for (int i = 0; i < pairwise.size(); i++)
	{
		if (pairwise.at(i) == currentTerm)
			return true;
	}
	return false;
}

int main()
{
	int N = 0; //  the number of elements in the sequence
	int casesNum = 0;

	while (cin >> N)
	{
		bool isB2Seq = true;
		casesNum++;
		vector<int> input(N);
		for (int i = 0; i < N; i++)
		{
			cin >> input.at(i);
			if (input.at(i) < 1)
				isB2Seq = false;
			for (int j = 0; j < i; j++)
			{
				if (input.at(i) <= input.at(j)) // input.at(i) > input.at(j)
				{
					isB2Seq = false;
				}
			}
		}
		sort(input.begin(), input.end());

		// compare two seq
		// if there is overlap
		// set isB2Seq to false

		vector<int> pairwise;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				int currentTerm = input.at(i) + input.at(j);
				if (isOverlap(pairwise, currentTerm) == true)
				{
					isB2Seq = false;
					break;
				}
				else // isOverlap(pairwise, currentTerm) == false
				{
					pairwise.push_back(currentTerm);
					sort(pairwise.begin(), pairwise.end());
				}
			}
		}

		if (isB2Seq == true)
		{
			cout << "Case #" << casesNum << ": It is a B2-Sequence." << endl;
		}
		else // isB2Seq == false
		{
			cout << "Case #" << casesNum << ": It is not a B2-Sequence." << endl;
		}

		cout << endl;
	}
}
```

## Analysis 2

### 重新理解題目

什麼是 B2-sequence？再仔細看題目的敘述：
> A B2-Sequence is a sequence of positive integers $1 ≤ b_1 < b_2 < b_3 ...$ such that all pairwise sums $b_i+b_j$, where $i ≤ j$, are different.

以  `1 2 4 8` 為例：
```
index: 0 1 2 3
value: 1 2 4 8

i: 0, j: 0 to 0
1+1

i: 1, j: 0 to 1
2+1 2+2

i: 2, j: 0 to 2
4+1 4+2 4+4

i: 3, j: 0 to 3
8+1 8+2 8+4 8+8
```

我們可以得到這些數字：
```
2
3 4
5 6 8
9 10 12 16
```

這些數字沒有重複，都不一樣，因此 `1 2 4 8` 是 B2-sequence。

再看 `3 7 10 14`：
```
6
10 14
13 17 20
17 21 24 28
```
可以看到 17 重複了，所以 `3 7 10 14` 不是 B2-sequence。

這才是正確的判斷方式與理解。

### 那些可以先做的判斷

照理來說，我應該可以過了阿？
但沒有，我還是被卡住。

重新回到題目：
> A B2-Sequence is a sequence of positive integers $1 ≤ b_1 < b_2 < b_3 ...$ such that all pairwise sums $b_i+b_j$, where $i ≤ j$, are different.

其實還隱藏著其他訊息。

1. $1 ≤ b_1 < b_2 < b_3 ...$，所有數列的項都需要大於等於 1。如果其中有項小於 1，那該數列應該直接被判定為 `It is not a B2-Sequence.`。

我起先並沒有做以上判斷，導致有些部分項小於 0 的數列還是被判定為 B2-Sequence。

因此我補上以下程式碼：
```cpp
if (input.at(i) < 1)
	isB2Seq = false;
```

2. $1 ≤ b_1 < b_2 < b_3 ...$，數列的項**必須**由小到大排列。以 `1 2 4 8` 為例，如果它像現在這樣排列，那它會是 B2-Sequence。但如果是 `2 1 4 8`，它**不會**是 B2-Sequence。

我起先也沒有做以上判斷，導致像是 `2 1 4 8` 的數列還是被判定為 B2-Sequence。

因此我補上以下程式碼：
```cpp
if (input.at(i) <= input.at(j)) // input.at(i) > input.at(j)
	isB2Seq = false;
```

### 下次可以做的事與改進 written with gemini

1. 仔細拆解題目的「數學定義」與「邊界限制」
下次可以這樣做：在開始寫核心演算法前，先把題目給的限制條件一條一條列出來，並直接轉換成程式碼中的 `if` 判斷式。

2. 建立「提早排除 (Early Exit)」的防禦性思維
下次可以這樣做：養成習慣，把輸入資料的合法性檢查放在程式的最前面。只要一發現不符合前提條件（例如發現 `input.at(i) < 1`），就立刻標記失敗。

3. 不要預設輸入資料都是「乖巧」的
你注意到了 `2 1 4 8` 這種不合規定的數列也可能會被輸入進來。解題系統的測試資料（測資）常常會包含各種刁鑽的陷阱，來測試你的程式夠不夠嚴謹。
下次可以這樣做：在構思解法時，可以先問自己幾個極端問題來設計自己的測試案例：
    * 如果輸入包含負數或 0 怎麼辦？
    * 如果輸入完全沒有按照順序怎麼辦？
    * 如果輸入有重複的數字怎麼辦？