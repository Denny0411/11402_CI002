# UVa 10062 – Tell me the frequencies

## Link

https://onlinejudge.org/external/100/10062.pdf

## Thinking Logic and Solution Strategy

1. 輸入字元
2. 將字元轉換成該字元的 ascii code number
3. 統計數量 `count pair<int, int> #include <utility>`
	* 已經有過
	* 第一次出現
4. `cout << count.first << count.second;`

## onClass: wrong answer

```cpp
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool rule(const pair<int, int>& a, const pair<int, int>& b)
{
	// 次數由小到大
	if (a.second < b.second)
		return a.second < b.second;
	// 次數一樣，則 asciiNum 由大到小
	else if (a.second == b.second)
		return a.first > b.first;
}

int main()
{
	string input;

	while (getline(cin, input))
	{
		vector < pair<int, int> > freq;
		
		for (int i = 0; i < input.size(); i++)
		{
			int asciiNum = static_cast<int>(input.at(i));
			
			bool exist = false;
			for (int j = 0; j < freq.size(); j++)
			{
				if (freq.at(j).first == asciiNum)
				{
					exist = true;
					freq.at(j).second++;
					break;
				}
			}
			if (exist == false)
			{
				freq.push_back(make_pair(asciiNum, 1));
			}
		}
		//sort(freq.begin(), freq.end(), rule(freq.front(), freq.back()));
		sort(freq.begin(), freq.end(), rule);
		for (int i = 0; i < freq.size(); i++)
		{
			cout << freq.at(i).first << " " << freq.at(i).second << endl;
		}
		cout << endl;
	}
}
```

## Analysis 1-1

「輸入字元、將字元轉換成該字元的 ascii code number、統計數量」都已經完成，但是我卡在 `std::sort`。

* 首先，在上機考的大部分時間，我都把自訂 sort 的部分寫成：
    ```cpp
    sort(freq.begin(), freq.end(), rule());
    ```
    但其實這樣寫是錯誤的，應該是：
    ```cpp
    sort(freq.begin(), freq.end(), rule);
    ```

* 其次，就算我在考完試後把 `rule()` 改成 `rule`，我的 `bool rule()` function 也還是錯的，無法正確排序。

* 在這題後，我應該要能夠確實使用 `std::sort` 來處理之後遇到的自訂排序題目。

* 我感覺在上機考時只差一點點就 AC，但可惜那一點點的解法並不在我當時的腦海中。

## Review

過了一個星期再回來看當初寫的程式碼，已經看不太懂了 :(

假設 input 是 "AAABBC"：

```cpp
for (int j = 0; j < freq.size(); j++)
```

* 最一開始，`freq.size() == 0`，代表 `vector < pair<int, int> > freq` 還沒有任何 pair 在 vector。
* `(j < freq.size()) == false`，程式不會執行 for 迴圈。
* 因為 `bool exist` 還是 `false`，程式會執行：
    ```cpp
    if (exist == false)
        freq.push_back(make_pair(asciiNum, 1));
    ```
    建立對應到該 ascii code 的 pair。

現在 `i == 1`，代表開始處理第 2 個 'A'。

```cpp
if (freq.at(j).first == asciiNum)
{
    exist = true;
    freq.at(j).second++;
    break;
}
```

* 'A' 的 pair 存在，`exist = true`
* 'A' 的次數++
* 不用再去檢查之後的 pair，直接 `break`

之後執行到 'B' 時，又會到：

```cpp
if (freq.at(j).first == asciiNum)
{
    exist = true;
    freq.at(j).second++;
    break;
}
```
建立對應到該 ascii code 的新 pair。

## Analysis 1-2

現在回到 `bool rule()`。

當 `a.second > b.second` （數量較大）時，程式跑進了 `else`，但我們不應該在那裡去比較 ASCII 值。我們只應該在「數量完全相等」的時候，才去比較 ASCII 值。

建議你可以將排序邏輯分成兩個明確的層次來寫：

1. 首要條件：如果兩者的「次數」不相等
    * 直接回傳次數比較的結果（次數小的排前面）。

2. 次要條件：如果兩者的「次數」相等
    * 這時候才去回傳 ASCII 比較的結果（ASCII 大的排前面）。

## Version 1

Presentation Error (格式錯誤)

有更動的部分：

```cpp
bool rule(const pair<int, int>& a, const pair<int, int>& b)
{
    // 首要條件：如果兩者的「次數」不相等
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    // 次要條件：如果兩者的「次數」相等
    else // a.second == b.second
    {
        // ASCII 大的排前面
        return a.first > b.first;
    }
}
```

## Analysis 2

什麼是 Presentation error？我還是第一次遇到。

### 什麼是 Presentation Error？by Gemini

在 UVa 等線上解題系統中，**Presentation Error (格式錯誤)** 代表一個非常重要的里程碑：**你的核心運算邏輯和答案是 100% 正確的！** 系統已經認可了你的計算結果，唯一的問題在於「輸出的排版格式」沒有完全符合系統的龜毛要求。通常是因為：
* 多印或少印了空格。
* 多印或少印了換行符號（`\n` 或 `endl`）。

### 為什麼這題會拿到 PE？

還記得我們上一回提到的「空白行陷阱」嗎？題目明確要求：「A blank line should separate each set of output.」（每組輸出**之間**應該用空白行隔開）。

我們來看看你目前的程式碼最後面：

```cpp
for (int i = 0; i < freq.size(); i++)
{
    cout << freq.at(i).first << " " << freq.at(i).second << endl;
}
cout << endl; // 👈 問題出在這裡！
```

你的寫法是「每一組測資印完答案後，都跟著印一個空白行」。
假設系統餵給你 3 組測試資料，你的程式會輸出：
> (第 1 組答案)
> (空白行)
> (第 2 組答案)
> (空白行)
> (第 3 組答案)
> **(空白行)** 👈 這個是系統不想要的！

UVa 系統看到最後面多出了這個空白行，就會判定為格式錯誤。

## Version 2

Accepted

```cpp
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool rule(const pair<int, int>& a, const pair<int, int>& b)
{
    // 首要條件：如果兩者的「次數」不相等
    if (a.second != b.second)
    {
        return a.second < b.second;

    }
    // 次要條件：如果兩者的「次數」相等
    else // a.second == b.second
    {
        // ASCII 大的排前面
        return a.first > b.first;
    }
}

int main()
{
	string input;
    bool isFirstOutput = true; // 處理 output 要求的空白行

	while (getline(cin, input))
	{
		vector < pair<int, int> > freq;
		
		for (int i = 0; i < input.size(); i++)
		{
			int asciiNum = static_cast<int>(input.at(i));

            // 代表還沒有任何 pair 在 vector
            // 或是該 asciiNum 還沒有對應的 pair
			bool exist = false; 

			for (int j = 0; j < freq.size(); j++)
			{
				if (freq.at(j).first == asciiNum)
				{
					exist = true;
					freq.at(j).second++;
					break;
				}
			}
			if (exist == false)
			{
				freq.push_back(make_pair(asciiNum, 1));
			}
		}

        sort(freq.begin(), freq.end(), rule);

        if (isFirstOutput == false)
            cout << endl;

        isFirstOutput = false;

		for (int i = 0; i < freq.size(); i++)
		{
			cout << freq.at(i).first << " " << freq.at(i).second << endl;
		}
	}
}
```

## Analysis 3: `std::sort` 的自訂排序

最後，詳細分析 `std::sort` 的自訂排序。

```cpp
bool rule(const pair<int, int>& a, const pair<int, int>& b)
{
    // 首要條件：如果兩者的「次數」不相等
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    // 次要條件：如果兩者的「次數」相等
    else // a.second == b.second
    {
        // ASCII 大的排前面
        return a.first > b.first;
    }
}
```

focus 在這一段：

```cpp
if (a.second != b.second)
{
    return a.second < b.second;
}
```

2 種情況：`a.second < b.second` 和 `a.second > b.second`：

1. `a.second < b.second`
If `a.second < b.second`, `rule()` will return 'true', pair a and pair b won't swap.
如果 a 的次數小於 b 的次數，`(a.second < b.second) == true`，`rule()` 會回傳 'true'，a 跟 b 不會對調。

2. `a.second > b.second`
If `a.second > b.second`, `rule()` will return 'false', pair a and pair b will swap.
如果 a 的次數大於 b 的次數，`(a.second < b.second) == false`，`rule()` 會回傳 'false'，a 跟 b 會對調。

最後的結果就是次數小的會在前面。

Gemini 建議修改成這樣：

> 用「swap (對調)」來思考，通常是來自於對「氣泡排序法 (Bubble Sort)」的印象（每次比較相鄰的兩個元素，錯了就對調）。但實際上，C++ 的 std::sort 底層使用的是更複雜、更快速的演算法（混合了快速排序等）。它不一定只比較「相鄰」的元素，所以用「會不會 swap」來理解有時候會不太精準。

> 把 `rule(a, b)` 想成是系統在問你：「**在排好序的結果中，`a` 是否應該排在 `b` 的前面？**」
> 
> 1. 當 `a.second < b.second` 時：
> 條件成立，回傳 `true`。代表告訴系統：「**對，`a` 應該排在 `b` 前面**」。
> 
> 2. 當 `a.second > b.second` 時：
> 條件不成立，回傳 `false`。代表告訴系統：「**不對，`a` 不應該排在 `b` 前面**」（系統就會把 `b` 安排在前面）。