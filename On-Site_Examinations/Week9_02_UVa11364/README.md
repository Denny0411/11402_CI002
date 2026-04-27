# UVa - 11364 Optimal Parking

## Link

https://onlinejudge.org/external/113/11364.pdf

## onClass

### Code

Result: accepted

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int store = 0;
		cin >> store;
		vector<int> position;
		for (int j = 0; j < store; j++)
		{
			int x = 0;
			cin >> x;
			position.push_back(x);
		}

		sort(position.begin(), position.end());
		cout << (position.back() - position.front()) * 2 << endl;
	}
}
```

## Analysis

* 這題很簡單，在輸入完成後，只要計算 `距離 * 2 == (最後面的位置 - 最前面的位置) * 2` 就好
* 把輸入做 `sort`，最小值就是最前面的位置，最大值就是最後面的位置，因此距離就是 `position.back() - position.front()`

> ### 1. 正確性與邊界條件 (Correctness & Boundary Conditions)
> * **正確性**：你的邏輯完全正確！這題的距離計算確實就是 `(最大位置 - 最小位置) * 2`。
> * **邊界條件**：題目提到商店數量範圍是 $1\le n\le20$。當 `n = 1` 時，迴圈只會讀取一個位置，排序後最大值和最小值相同，計算出的距離為 `0`，這完全符合預期。資料範圍 $0\le x_{i}\le99$ 也非常小，使用 `int` 不會有溢位（Overflow）的風險。
> 
> ### 2. 演算法合理性 (Algorithmic Reasonability)
> * **目前做法**：你使用了 `std::sort` 來對所有位置進行排序，然後取頭尾的值。排序的時間複雜度是 $O(n \log n)$。
> * **優化空間**：雖然 $n$ 最大只有 20，對於效能的影響微乎其微，但從演算法的角度來看，我們其實**只需要找到最大值和最小值**，不需要對「所有」元素進行完整的排序。尋找最大最小值的時間複雜度只需要 $O(n)$。
> 
> ### 3. 可讀性、命名與結構 (Readability, Naming, & Structure)
> * **變數命名**：
    > * `N` 通常用來表示資料的數量。但在這題的輸入格式中，第一個數字代表的是「測試資料的組數（Test cases）」。將 `N` 改名為 `testCases` 或 `T` 會更直覺。
    > * `store` 這個變數儲存的是「商店的數量」，改名為 `numStores` 或直接用題目習慣的 `n` 會更精確。
> * **結構**：程式碼縮排和結構都很整齊，非常容易閱讀！
> 
> ---
> 
> ### 最需要優先修改的地方與方向
> 
> **優先修改目標：拔除 `vector` 與 `sort`，邊讀邊找最大/最小值。**
> 
> 既然我們只需要知道這群位置中的「最大值」與「最小值」，其實我們甚至不需要把所有的位置用 `vector` 儲存起來。
> 
> **你可以嘗試這樣修改：**
> 1.  **移除** `vector<int> position;` 以及 `sort(...)`。
> 2.  在讀取每一間商店位置的 `for` 迴圈**外面**（但在測試資料的迴圈內），宣告兩個變數，例如 `min_pos` 和 `max_pos`。
> 3.  給予這兩個變數適當的初始值。（提示：思考一下 $0\le x_{i}\le99$ 這個條件，`min_pos` 的初始值應該要足夠大，`max_pos` 的初始值應該要足夠小）。
> 4.  在讀取位置的 `for` 迴圈**裡面**，每當你讀入一個 `x` 時，立刻拿它與 `min_pos` 和 `max_pos` 比較，並隨時更新這兩個變數的值。
> 5.  最後輸出的時候，直接使用 `(max_pos - min_pos) * 2`。
> 
> 這樣一來，你不只省下了記憶體空間（不需要陣列），還把時間複雜度降到了最低。
>
> written by gemini