# Link

https://leetcode.com/problems/rotate-image/

# Note

* 我發現可以先將矩陣上下翻轉，再將矩陣沿著左上到右下的對角線翻轉，就能得到目標矩陣。

> C++ 的 <algorithm> 函式庫提供了一個非常強大的工具 std::reverse。我們只需要傳入起點和終點的迭代器 (iterator)，它就能幫我們把整個容器的元素順序反轉。

```cpp
reverse(matrix.begin(), matrix.end());
```

> 對角線翻轉的意思是，我們要將座標 `[i][j]` 的元素，與座標 `[j][i]` 的元素進行交換。
在 C++ 中，我們可以利用內建的 swap() 函式來輕鬆交換兩個變數：

```cpp
swap(matrix[i][j], matrix[j][i]);
```

### 認識 `std::reverse`

在使用它之前，記得要在程式碼最上方引入 `<algorithm>` 函式庫。

它的基本功用是「將一段區間內的元素順序顛倒」。它需要接收兩個參數：

1. **起點 (begin)**：告訴它從哪裡開始反轉。
2. **終點 (end)**：告訴它到哪裡結束。

**一維陣列的簡單例子：**
假設你有一個一維陣列 `vector<int> nums = {1, 2, 3, 4, 5};`
如果你寫：

```cpp
reverse(nums.begin(), nums.end());
```

`nums` 就會直接變成 `{5, 4, 3, 2, 1}`。

---

### 把 `std::reverse` 用在 2D 矩陣上

在 C++ 中，`vector<vector<int>> matrix` 其實是一個**「裝著很多一維陣列（也就是列 row）的陣列」**。

你可以把 `matrix` 想像成一個大抽屜，裡面放了三個小盒子：

* 第一個小盒子 (第一列)：`[1, 2, 3]`
* 第二個小盒子 (第二列)：`[4, 5, 6]`
* 第三個小盒子 (第三列)：`[7, 8, 9]`

當我們對這個 2D 矩陣呼叫 `reverse(matrix.begin(), matrix.end())` 時，`std::reverse` 看待它的方式是去**交換這些「小盒子」的順序**，而不會去動到小盒子裡面的數字。

* `matrix.begin()` 指向第一個小盒子。
* `matrix.end()` 指向最後一個小盒子的後面。

所以它會把第一個小盒子跟最後一個小盒子交換位置：

```text
原始：
第一列 -> [1, 2, 3]
第二列 -> [4, 5, 6]
第三列 -> [7, 8, 9]

執行 reverse 後：
第一列變成 -> [7, 8, 9] (原本的最後一列跑到最上面了)
第二列還是 -> [4, 5, 6]
第三列變成 -> [1, 2, 3] (原本的第一列跑到最下面了)

```

這就完美達成了我們剛剛說的第一步：**「上下翻轉矩陣」**！而且只用了一行程式碼就搞定了。

## std::reverse Example

```cpp
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    reverse(matrix.begin(), matrix.end());

    // output matrix...
}
```

Output:
```
7 8 9 
4 5 6 
1 2 3 
```

---

```cpp
int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    reverse(matrix.at(0).begin(), matrix.at(0).end());

    // output matrix...
}
```

Output:
```
3 2 1 
4 5 6 
7 8 9 
```

# Solution

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 1. 上下翻轉
        reverse(matrix.begin(), matrix.end());

        // 2. 沿左上至右下對角線翻轉
        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < row; col++)
            {
                swap(matrix[row][col], matrix[col][row]);
            }
        }
    }
};
```

* 沿左上至右下對角線翻轉時，不可以寫 `for (int col = 0; col < matrix[row].size(); col++)`，這樣會重複做交換，最後的結果是等同於只做外層迴圈。