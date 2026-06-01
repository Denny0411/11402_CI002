# UVa 10252 - Common Permutation

## Link

https://onlinejudge.org/external/102/10252.pdf

## Thinking Logic and Solution Strategy

* 使用 `<map>` 解題

## afterClass_v1

Result: accepted

```cpp
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // two strings of lowercase letters
    string a, b;

    while (getline(cin, a) && getline(cin, b))
    {
        map<char, int> mapA, mapB;

        // 統計字母頻率
        for (char c : a)
        {
            // 增加 mapA key 為 c 的值
            // 若尚未存在，則建立 key 為 c
            mapA[c]++;
        }
        for(char c : b)
        {
            mapB[c]++;
        }

        // 尋找交集與最小次數

        // pairA 是 key-value pair
        for (auto pairA : mapA)
        {
            char c = pairA.first;

            // count(key): 回傳該 key 是否存在
            // 回傳 0 不存在 或 1 存在
            if (mapB.count(c))
            {
                // map.at(key): 回傳該 key 對應的 value
                int minCount = min(pairA.second, mapB.at(c));
                for (int i = 0; i < minCount; i++)
                    cout << c;
            }
        }
        cout << endl;
    }
}
```
## Analysis

```cpp
mapA[c]++;
mapB.at(c)++;
```

> ### 觀念釐清：`.at()` vs `[]`
> 
> 這兩個符號都可以用來存取 `map` 裡面的值，但面對「不存在的 Key」時，它們的反應截然不同：
> 
> * **`.at(key)`（非常嚴格）：**
> 它只會去尋找「已經存在字典裡」的 Key。如果它發現字典裡根本沒有這個字母，它**不會**幫你建立，而是會直接引發一個名為 `out_of_range` 的例外（Exception），導致程式瞬間崩潰。這就是你遇到 Runtime Error 的元凶！因為一開始 `map` 是空的，讀取第一個字母時就直接報錯了。
> * **`[key]`（自動建立）：**
> 這就是我們上一篇提到的「魔法」。當使用中括號時，如果它發現字典裡沒有這個字母，它會**自動幫你建立這個 Key**，並將 Value 預設為 0，接著你就可以順利地進行 `++`（加一）的操作。
>
> written by gemini