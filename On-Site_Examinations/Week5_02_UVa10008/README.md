# UVa 10008

## Problem Information

- **Problem Link:** https://onlinejudge.org/external/100/10008.pdf

## Description

* 將輸入進行 formatting，只保留字母。
* 將小寫字母轉換成大寫字母。
* 將字母進行統計。
* 輸出字母和對應的出現次數，由多到少，遞減數列。
* 如果字母有同樣的出現次數，則根據字母順序進行排列。

## onClass.cpp

Result: wrong answer

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	cin.ignore();
	string* input = new string[n];
	for (int i = 0; i < n; i++)
	{
		getline(cin, input[i]);
	}

	// 刪掉除了字母以外的字元
	// 將小寫變成大寫
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (!isalpha(input[i].at(j)))
			{
				input[i].replace(j, 1, "");
				j--;
			}
			if (islower(input[i].at(j)))
			{
				input[i].at(j) = toupper(input[i].at(j));
			}
		}
	}

	unordered_map<char, int> count;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			count[input[i].at(j)]++;
		}
	}

	for (int i = 0; i < count.size(); i++)
	{
		cout << count[i] << endl;
	}
}
```

## Analysis

* **砍掉重練：** 其實這一題不需要用到 `unorder_map`，這樣是複雜化了。
* 不用對 input 進行 replace 之類的操作，題目要的只是統計數量，在符合條件的 input 出現時增加相對應的次數就行了。

## version2.cpp

Result: accepted

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool compareRule(const pair<char, int>& a, const pair<char, int>& b)
{
    // 規則一：如果兩者的出現次數不同
    if (a.second != b.second)
    {
        // 次數多的排前面 (a.second > b.second 成立時回傳 true)
        return a.second > b.second;
    }
    else // a.second == b.second
    {
        // 字母順序小的排前面 (a.first < b.first 成立時回傳 true)
        return a.first < b.first;
    }
}

int main()
{
	int n = 0;
	cin >> n;
	cin.ignore();
	string* input = new string[n];
	for (int i = 0; i < n; i++)
	{
		getline(cin, input[i]);
	}

    vector<int> count(26);
    vector< pair<char, int> > letterData;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i].at(j)))
			{
                input[i].at(j) = toupper(input[i].at(j));
                count.at(input[i].at(j) - 'A')++;
			}
		}
	}

    for (int i = 0; i < 26; i++)
    {
        if (count.at(i) > 0)
        {
            letterData.push_back(make_pair('A' + i, count.at(i)));
        }
    }

    sort(letterData.begin(), letterData.end(), compareRule);

    for (int i = 0; i < letterData.size(); i++)
    {
        cout << letterData.at(i).first << " " << letterData.at(i).second << endl;
    }
}
```

## Analysis

### Prompt

我已經完成該題程式的撰寫，並且也通過測試。
請詳細說明 `sort(letterData.begin(), letterData.end(), compareRules);` 跟 `compareRules()` 函式，這是我第一次用這樣的寫法。

### Feedback

#### 1. 拆解 `sort` 的呼叫方式

在你程式的第 61 行，你寫了：
```cpp
sort(letterData.begin(), letterData.end(), compareRule);
```

這三個參數分別代表：
* **`letterData.begin()`**：告訴管理員，隊伍從哪裡開始（起點）。
* **`letterData.end()`**：告訴管理員，隊伍到哪裡結束（終點）。
* **`compareRule`**：這就是你遞給管理員的「規則手冊」。

當 `sort` 開始運作時，它會在 `letterData` 這個陣列裡不斷挑選兩個元素出來（我們假設為 `A` 和 `B`），然後去問你的 `compareRule`：「嘿，`A` 應該排在 `B` 前面嗎？」

#### 2. 拆解 `compareRule` 函式（規則手冊）

我們來看看你定義的規則手冊是怎麼回答 `sort` 管理員的：

```cpp
bool compareRule(const pair<char, int>& a, const pair<char, int>& b)
```
* 這個函式接收兩個 `pair` 作為參數（`a` 和 `b`），這就是管理員抓出來比較的兩筆資料。
* 回傳型態是 `bool` (布林值)。
    * 如果你回傳 **`true`**，代表「沒錯，**`a` 應該排在 `b` 的前面**」。
    * 如果你回傳 **`false`**，代表「不對，**`a` 不該排在 `b` 的前面**（可能要對調，或是維持原樣）」。

裡面的邏輯完美對應了題目的要求：

```cpp
// 規則一：如果兩者的出現次數不同
if (a.second != b.second)
{
    // 次數多的排前面 (a.second > b.second 成立時回傳 true)
    return a.second > b.second;
}
```
* 因為題目規定輸出必須按照出現次數由大到小排序（遞減）。
* 所以當次數（`second`）不同時，只要 `a` 的次數大於 `b` 的次數（`a.second > b.second` 為真），就回傳 `true`，確保次數多的排在前面。

```cpp
else // a.second == b.second
{
    // 字母順序小的排前面 (a.first < b.first 成立時回傳 true)
    return a.first < b.first;
}
```
* 題目還有規定，如果兩個字母的頻率相同，那麼在字母表中排在前面的字母必須先輸出。
* 所以當次數相同時，程式會走到 `else`。這時比較的是字母本身（`first`）。因為在 ASCII 碼中，'A' 比 'B' 小，所以只要 `a` 的字母小於 `b` 的字母（`a.first < b.first` 為真），就回傳 `true`，讓字母順序靠前的排在前面。