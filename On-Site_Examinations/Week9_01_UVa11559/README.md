# UVa - 11559 EventPlanning

## Link

https://onlinejudge.org/external/115/11559.pdf

## onClass

### Thinking Logic and Solution Strategy

```
N: the number of participants 人數
B: budget
H: the number of hotels to consider
W: the number of weeks you can choose between

P:  the price for one person staying the weekend at the hotel
A:  the number of available beds for each weekend at the hotel

Output:
minimum cost of the stay
or "stay home"

** All participants must stay at the same hotel **
```

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
	int B = 0;
	int H = 0;
	int W = 0;

	while (cin >> N >> B >> H >> W)
	{
		vector<int> P(H);
		vector<vector<int>> A;
		A.resize(H);
		for (int i = 0; i < H; i++)
			A.at(i).resize(W);

		for (int i = 0; i < H; i++)
		{
			cin >> P.at(i);
			for (int j = 0; j < W; j++)
			{
				cin >> A.at(i).at(j);
			}
		}

		// count min price
		// 1. 看哪個旅館能夠住，床數夠多
		// 2. 都夠就比較價格
		vector<int> price;
		int min = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (A.at(i).at(j) >= N && N * P.at(i) < B)
				{
					// 計算價格並 push
					price.push_back(N * P.at(i));
					//cout << N * P.at(i) << endl;
				}
			}
		}

		sort(price.begin(), price.end());
		if (price.size() == 0)
			cout << "stay home" << endl;
		else
			cout << price.at(0) << endl;
	}
}
```

## Analysis 1

* 這題的難點是變數很多，要搞清楚題意
* 我對 `vector` 做二維陣列輸入不是很熟悉，相關的細節應整理成 [vector.md](/STL_Note/vector.md)

> ### 1. 正確性 (Correctness)
> 你的邏輯大方向完全正確，但在預算條件的判斷上有一點小瑕疵。題目中提到「The total cost of the trip must be within budget」。這代表總花費是可以「等於」預算的。
> * **修改方向**：你的程式碼寫了 `N * P.at(i) < B`，如果把它改成 `<=` 會更符合題意。雖然這題的測資可能剛好沒有卡到這個邊界，但精確翻譯題意能避免未來在其他題目中遇到隱藏 Bug。
> 
> ### 2. 邊界條件 (Boundary Conditions)
> 這部分你處理得很棒！根據題目，人數上限是 200，價格上限是 10000。最極端的總花費是 2,000,000，這完全在 C++ `int` 型別的安全範圍內，所以不會有整數溢位 (overflow) 的問題。
> 
> ### 3. 可讀性、命名與結構 (Readability, Naming & Structure)
> * **變數命名**：你使用了與題目說明完全一致的 `N`、`B`、`H`、`W`，這在解演算法題目時是很直覺且好懂的做法。
> * **Vector 初始化**：你目前使用了迴圈搭配 `resize` 來建立二維的 `vector`。
> * **修改方向**：其實 C++ 的 `vector` 可以在宣告時直接定義大小。你可以嘗試用一行程式碼完成二維陣列的初始化，這會讓程式碼看起來更簡潔。
> 
> ### 4. 演算法合理性 (Algorithm Rationality)
> 目前你的程式碼會把「所有符合條件的週末總花費」都塞進一個 `vector<int> price` 裡面，最後再透過 `sort` 排序來找出最小值並印出。
> * **修改方向**：同一家旅館每個週末的價格都是一樣的。也就是說，如果某家旅館有 3 個週末都有空床，你的程式碼會把同一個價格 push 進 `price` 陣列 3 次，這是多餘的操作。
> 
> ---
> 
> ### 最需要優先修改的地方：即時處理與空間最佳化
> 
> 你最需要優先挑戰的，是**拔除 `vector<int> price` 以及 `sort` 排序**！
> 
> 我們其實不需要記住「所有」能住的價格，我們只關心「最便宜」的那個。你可以宣告一個變數（例如 `min_cost`）來隨時記錄目前找到的最低價格，並在讀取資料的過程中不斷更新它。
> 
> 更進階一點，因為這題我們只需要找到符合預算的最便宜價格，我們甚至可以在 `while` 迴圈讀取輸入資料的當下就順便做判斷，**完全不需要使用二維陣列儲存旅館的床位資料**喔！
>
> written by gemini

### 二維 vector

> 在 C++ 中，二維的 `vector` 概念上就是「裝著 `vector` 的 `vector`」。我們可以利用 `vector` 內建的建構函數 (Constructor) 來一次設定好大小和初始值。
> 
> #### 一行初始化的程式碼
> 
> 要在宣告的同時建立一個大小為 `H` 乘 `W` 的二維 `vector`，你可以這樣寫：
> 
> ```cpp
> vector<vector<int>> A(H, vector<int>(W, 0));
> ```
> 
> ---
> 
> #### 逐步語法拆解與說明
> 
> 讓我們把這行程式碼像洋蔥一樣，由外而內剝開來理解：
> 
> 1. **`vector<vector<int>> A`**
   > 這部分跟你原本寫的一樣，我們宣告了一個名為 `A` 的變數，它的型態是「裝著整數 `vector` 的 `vector`」（也就是二維陣列）。
> 
> 2. **`(H, ...)`**
   > 這是外層 `vector` 的初始化設定。括號裡的第一個參數 `H`，代表外層要先建立幾個元素。在你的專案情境中，這代表我們建立了 `H` 列（Row），對應到 `H` 家旅館。
> 
> 3. **`vector<int>(W, 0)`**
   > 這是括號裡的第二個參數，用來決定外層那 `H` 個元素「裡面要裝什麼東西」。
   > * 我們告訴程式：「請在每一列裡面，都放入一個大小為 `W` 的一維 `vector<int>`」。
   > * 後面的 `, 0` 代表將這 `W` 個元素的初始值全部設為 `0`。在你的情境中，這對應到 `W` 個週末的床位數。*(註：如果不寫 `, 0`，C++ 的 `vector<int>` 預設也會自動補 0，但明確寫出來可以讓閱讀程式碼的人更清楚你的意圖！)*
> 
> ---
> 
> #### 寫法大比拚
> 
> 你可以對比一下這兩種寫法，就能體會一行初始化的威力：
> 
> **你原本的寫法（需要 4 行，並動用迴圈）：**
> ```cpp
> vector<vector<int>> A;
> A.resize(H);
> for (int i = 0; i < H; i++)
    > A.at(i).resize(W);
> ```
> 
> **優化後的寫法（只要 1 行，乾淨俐落）：**
> ```cpp
> vector<vector<int>> A(H, vector<int>(W)); 
> ```
>
> written by gemini