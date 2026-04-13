# UVa 10474 - Where is the Marble?

## Link

https://onlinejudge.org/external/104/10474.pdf

## afterClass_v1

### Thinking Logic and Solution Strategy

```
if (input > 10000 && input < 0)
    end the program

直接 push string 結果 就好，不用搞一堆 variable

if 有找到
    x found at y
else
    x not found

Raju would place the marbles one after another in ascending order.

query
    found
    not found
```

### Code

Result: accepted

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0; // the number of marbles, N lines
    int Q = 0; // the number of queries Mina would make
    int caseNum = 0;

    cin >> N >> Q;

    while (N != 0 || Q != 0)
    {
        vector<int> marbles;
        vector<int> queries;
        vector<string> result;
        int input;

        caseNum++;

        for (int i = 0; i < N; i++)
        {
            cin >> input;
            marbles.push_back(input);
        }

        sort(marbles.begin(), marbles.end());

        for (int i = 0; i < Q; i++)
        {
            cin >> input;
            queries.push_back(input);
        }

        // compare
        for (int i = 0; i < queries.size(); i++)
        {
            bool isFound = false;
            int foundAt = -1;
            for (int j = 0; j < marbles.size(); j++)
            {
                if (marbles.at(j) == queries.at(i))
                {
                    isFound = true;
                    foundAt = j + 1;
                    break;
                }
            }

            if (isFound == true)
            {
                result.push_back(to_string(queries.at(i)) + " found at " + to_string(foundAt));
            }
            else // isFound == false
            {
                result.push_back(to_string(queries.at(i)) + " not found");
            }
        }

        // output
        cout << "CASE# " << caseNum << ":" << endl;
        for (int i = 0; i < queries.size(); i++)
        {
            cout << result.at(i) << endl;
        }

        cin >> N >> Q;
    }
}
```

## Analysis 1

### stringstream

原本是想要把 int output、string output 都輸入到一個 stringstream 整合，最後把整個 stringstream 輸出，結果實現起來有問題。

* 我對 stringstream 不熟悉。

> 問題點：C++ 的 `std::stringstream` 是一種特殊的串流物件，它不允許被複製。因此當你嘗試 `result.push_back(output)`; 時，編譯器會報錯。 by gemini

### `to_string()`

> 在 C++ 中，我們可以使用加號 `+` 來把多個字串（`string`）「黏」在一起。但是，因為你的陣列裡面存的是「整數（`int`）」，C++ 不允許直接把整數跟字串用加號連起來，所以我們需要一個翻譯官：`std::to_string()`。
> 1. 什麼是 `std::to_string()`？
這是一個 C++ 內建的函數，功能非常單純：把數字變成文字。
> * 例如你有一個整數 `int x = 5`;
> * 使用 `to_string(x)` 後，它就會變成文字的 "5"。
> 2. 如何使用加號 `+` 串接字串？
一旦數字變成了文字，你就可以像玩積木一樣，用 `+` 號把它們和你的提示文字拼在一起。 by gemini

* 程式中使用 `to_string()` 跟 `+` 的部分

```cpp
if (isFound == true)
    result.push_back(to_string(queries.at(i)) + " found at " + to_string(foundAt));
else // isFound == false
    result.push_back(to_string(queries.at(i)) + " not found");
```

### 初始化

```cpp
bool isFound = false;
int foundAt = -1;
```

需要注意變數的位置，原本放在迴圈外面，導致沒有被初始化。

### 沒有注意到的部分

* ascending order

題目：
> Raju would place the marbles one after another in ascending order.

```cpp
for (int i = 0; i < N; i++)
{
    cin >> input;
    marbles.push_back(input);
}
```

這個部分做完後應該要 `sort()`。

```cpp
sort(marbles.begin(), marbles.end());
```

* `foundAt`

```cpp
if (marbles.at(j) == queries.at(i))
{
    isFound = true;
    foundAt = j + 1;
    break;
}
```

output 的位置索引需要 + 1。

## afterClass_v2

Result: accepted

就是把迴圈整合一下。