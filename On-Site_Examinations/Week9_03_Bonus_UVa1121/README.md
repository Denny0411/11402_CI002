# UVa - 1121 Subsequence

## Link

https://onlinejudge.org/external/11/1121.pdf

## onClass

### Thinking Logic and Solution Strategy

```
N positive integers
a positive integer S (S < 100 000 000) are given
the sum of which is greater than or equal to S
minimal length of the subsequence

連續的項要大於等於給定的值，
1: a1, a2, a3...
2: a1+a2, a2+a3 ...
```

在上機考時沒有把程式寫出來。

## afterClass_v1

### Thinking Logic and Solution Strategy

```
輸入
如何找到總和 >= S 的最少連續項？
項數從少到多
i = 1
a0, a1, ...
i = 2
a0 + a1, a1 + a2, ...

0 1 2 3 4
i = 2
起始 index:
0, 1, 2, 3
結束 index:
1, 2, 3, 4 => 0 + 2 - 1, 1 + 2 - 1

如果總和 >= S
    break
輸出當時的 i
```

> ### 步驟說明：如何設定迴圈的邊界
> 
> 你可以想像我們拿著一個固定長度的「框框」在陣列上滑動。
> 
> 1. **觀察規律**：
   > 假設陣列總共有 $N = 5$ 個元素（index 為 0, 1, 2, 3, 4）。
   > * 當長度 `i = 1`，起始 index `j` 可以是 0, 1, 2, 3, **4**。 (最大到 4)
   > * 當長度 `i = 2`，起始 index `j` 可以是 0, 1, 2, **3**。（因為最後一組是 index 3 和 4）。
   > * 當長度 `i = 3`，起始 index `j` 可以是 0, 1, **2**。（因為最後一組是 index 2, 3, 4）。
> 
> 2. **找出公式**：
   > 你有發現嗎？每次 `j` 能走到的最大值，剛好都會是 `N - i`。
> 
> ### 程式碼方向 (虛擬碼)
> 
> 依照上面的邏輯，你可以這樣設定你的迴圈：
> 
> ```cpp
> // 第一層迴圈：i 代表「連續的項數（長度）」
> for (int i = 1; i <= N; i++) 
> {
>     // 第二層迴圈：j 代表「起始 index」
>     // 當長度為 i 時，起始點最多只能走到 N - i，否則會超出陣列範圍
>     for (int j = 0; j <= N - i; j++) 
>     {
>         int sum = 0;
>         
>         // [思考點]：在這裡你需要取得從 index j 開始，連續 i 個元素的總和。
>         // 你打算怎麼算出這個總和呢？(例如：再用一個迴圈？還是有其他做法？)
>         
>         // 如果 sum >= S，因為我們是從小到大枚舉「項數 i」，
>         // 所以第一個符合條件的 i，就會是最小連續項數！
>     }
> }
> ```
>
> written by gemini

### Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    int S = 0;

    while (cin >> N >> S)
    {
        // size = N, initial value = 0
        vector<int> seq(N, 0);

        for (int i = 0; i < N; i++)
            cin >> seq.at(i);

        int termNum = 0;

        for (int i = 1; i <= N; i++) // 項數
        {
            for (int j = 0; j <= N - i; j++) // 起始 index
            {
                int sum = 0;
                for (int k = j; k < j + i; k++) // k 從 j 開始跑 i 個項
                {
                    sum += seq.at(k);
                }
                if (sum >= S)
                {
                    termNum = i;
                    break;
                }
            }
        }

        cout << termNum << endl;
    }
}
```

##　Analysis 1

```cpp
if (sum >= S)
{
    termNum = i;
    break;
}
```
* 沒有成功跳出迴圈並輸出 termNum，為什麼？

> ### 問題盲點：`break` 只能跳出一層迴圈
> 
> 在 C++ 中，`break` 指令只會中斷並跳出**包含它最內層的那一個迴圈**。
> 
> 我們來看看你的結構：
> ```cpp
> for (int i = 1; i <= N; i++) // 【外層】項數迴圈
> {
>     for (int j = 0; j <= N - i; j++) // 【內層】起始 index 迴圈
>     {
>         // ... (略) 計算 sum
>         if (sum >= S)
>         {
>             termNum = i;
>             break; // 這裡只會跳出「內層的 j 迴圈」！
>         }
>     }
> }
> ```
> 
> **情境重現：**
> 1. 當 `i = 2` 時，找到了一組 `sum = 15`。
> 2. 程式執行 `termNum = 2`，然後遇到 `break`，跳出了 `j` 迴圈。
> 3. **但是！外層的 `i` 迴圈並沒有被中斷**，所以程式接著執行 `i = 3`。
> 4. 當 `i = 3` 時，又找到了一組大於等於 15 的總和（例如 3+5+10 = 18），程式又執行了 `termNum = 3`，把原本的 `2` 給覆寫掉了。
> 5. 這樣的過程一直持續，直到 `i = 10`，所以最後印出的結果變成了 `10`。
> 
> ---
> 
> ### 修改方向
> 
> 因為我們是從小到大（`i = 1` 到 `N`）尋找，所以**第一次**找到符合條件的 `i`，必定就是「最短的連續項數」。一旦找到，我們需要把**外層的 `i` 迴圈也一併停下來**。
> 
> 這裡提供你兩個修改的思考方向（選一個你喜歡的即可）：
> 
> 1. **新增檢查條件（Flag / 狀態判斷）**：
   > 我們能不能在外層的 `i` 迴圈裡也加一個判斷？例如，每次準備進入下一個 `i` 之前，檢查一下 `termNum` 是否已經有值了？如果有值，是不是就可以直接 `break` 外層迴圈了呢？
> 
> 2. **使用布林值 (bool) 作為開關**：
   > 在迴圈外面宣告一個 `bool found = false;`。當 `sum >= S` 時，把 `found` 設為 `true`。接著在外層迴圈檢查這個 `found`，如果是 `true` 就讓外層也 `break`。
>
> written by gemini

## afterClass_v2

Result: Time limit exceeded

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    int S = 0;

    while (cin >> N >> S)
    {
        // size = N, initial value = 0
        vector<int> seq(N, 0);

        for (int i = 0; i < N; i++)
            cin >> seq.at(i);

        int termNum = 0;
        bool isFound = false;

        for (int i = 1; i <= N && isFound == false; i++) // 項數
        {
            for (int j = 0; j <= N - i && isFound == false; j++) // 起始 index
            {
                int sum = 0;
                for (int k = j; k < j + i && isFound == false; k++) // k 從 j 開始跑 i 個項
                {
                    sum += seq.at(k);
                }
                if (sum >= S)
                {
                    termNum = i;
                    isFound = true;
                }
            }
        }

        cout << termNum << endl;
    }
}
```

## Analysis 2

> ### 為什麼會超時？(Time Limit Exceeded)
> 
> 問題出在程式需要執行的「次數」太多了。這跟我們之前稍微聊到的「時間複雜度」有關。
> 
> 我們來觀察一下你目前的寫法（三層迴圈）：
> 1. 外層 `i` 決定長度。
> 2. 中層 `j` 決定起點。
> 3. 內層 `k` 把裡面的數字一個一個加起來。
> 
> 根據題目 `1121.pdf` 給的條件，數列長度 $N$ 最大可以逼近 $100,000$。
> 如果 $N$ 是 $100,000$，這三層迴圈在最壞的情況下（例如一直找不到答案時），需要執行的運算次數會是天文數字（大約需要執行數百億次操作）。但一般解題系統一秒鐘大約只能跑 $10^8$（一億）次運算，這就是為什麼程式會跑到超時。
> 
> ---
> 
> ### 修改方向：滑動窗口 (Sliding Window)
> 
> 為了讓程式跑得夠快，我們必須放棄「暴力枚舉所有組合」，改用一個更聰明的技巧：**滑動窗口 (Sliding Window)**，或者稱為**雙指標 (Two Pointers)**。
> 
> 這個概念就像是一隻在陣列上爬行的毛毛蟲，或是你可以想像我們拿著一個「可以自由伸縮長度」的框框。我們準備兩個變數來代表框框的邊界：`left`（左邊界）和 `right`（右邊界）。
> 
> **運作邏輯（紙上推演）：**
> 
> 1. **向右擴張（吃數字）**：
>    一開始 `left` 和 `right` 都在 index 0。我們讓 `right` 不斷往右走，把走過的數字都加進 `sum` 裡面。這就像毛毛蟲的頭一直往前伸，直到吃進肚子的總和 `sum` $\ge S$ 為止。
> 2. **向左收縮（吐數字）**：
>    一旦發現 `sum` $\ge S$，太棒了！我們找到一組候選答案了，先拿個變數把現在的「長度」記下來（如果比之前記錄的更短，就更新它）。
>    接著，我們試著讓毛毛蟲的尾巴往前縮——也就是把 `left` 往右移一格，同時把原本 `left` 位置的數字從 `sum` 裡面扣掉。
> 3. **檢查是否依然符合**：
>    扣掉尾巴的數字後，看看現在的 `sum` 是不是依然 $\ge S$？
>    * **如果是**：太好了，這代表我們找到了一個**更短**的組合！繼續更新最短長度，並繼續把 `left` 往右移。
>    * **如果不是 (sum < S)**：這代表縮得太短了，那我們就切換回步驟 1，讓 `right` 繼續往右走去吃新的數字。
> 
> ### 為什麼這樣會快很多？
> 
> 因為用這種方式，`right` 和 `left` 兩個指標都只需要從頭走到尾「各一次」。不管陣列有多長，程式執行的次數就大約等於陣列的大小 $N$，也就是 $\mathcal{O}(N)$ 的時間複雜度，絕對可以在時間限制內跑完！
> 
> 你可以先拿一張紙，用題目的範例輸入 `10 15` 與數列 `5 1 3 5 10 7 4 9 2 8`，試著用兩根手指頭當作 `left` 和 `right` 跑一次這個邏輯看看。
>
> written by gemini

## afterClass_v3


### Code

Result: Wrong answer

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    int S = 0;

    while (cin >> N >> S)
    {
        vector<int> seq(N, 0);
        int right = 0;
        int left = 0;
        int minLength = N;

        for (int i = 0; i < N; i++)
            cin >> seq.at(i);

        while (right < N)
        {
            int tempSum = 0;
            for (int i = left; i <= right; i++)
                tempSum += seq.at(i);

            if (tempSum < S)
            {
                right++;
            }
            else // tempSum >= S
            {
                if (minLength > (right - left + 1))
                    minLength = (right - left + 1);

                left++;
            }
        }

        cout << minLength << endl;
    }
}
```

## Analysis 3

> 我們來思考一個情境：如果題目給的 $S$ 非常非常大（例如 $S = 100000$），但陣列裡所有的數字加起來都還不到這個 $S$，會發生什麼事？
> 
> 1. 你的程式初始化了 `int minLength = N;`。
> 2. 因為 `tempSum` 永遠小於 $S$，所以程式永遠不會進入 `else` 區塊去更新 `minLength`。
> 3. 最後程式會輸出 `N`。
> 
> **思考點**：
> 如果連把整個陣列（長度為 $N$）加起來都不夠，代表「根本找不到」符合條件的子數列。在這種情況下，UVa 系統通常預期你要輸出 `0`。
> * **修改方向**：我們可以把 `minLength` 一開始設定為一個「不可能達到的巨大數值」（例如 `N + 1` 或是 `1000000`）。等到迴圈結束後，我們再來檢查：如果 `minLength` 還是這個巨大的數值，代表我們從頭到尾都沒找到答案，這時候就輸出 `0`；否則才輸出 `minLength`。
> 
> ---
> 
> ### 問題二：毛毛蟲每次都在重新吃葉子？（失去滑動窗口的加速效果）
> 
> 我們來看看你計算 `tempSum` 的這段程式碼：
> ```cpp
> int tempSum = 0;
> for (int i = left; i <= right; i++)
>     tempSum += seq.at(i);
> ```
> 
> **思考點**：
> 雖然你的外層有了 `left` 和 `right`，但你每次都用一個 `for` 迴圈「從頭到尾」把數字重新加過一遍！
> 想像一下毛毛蟲吃葉子：當牠的頭往前伸一格（`right++`），牠其實只需要把「新碰到的那一格」吃進去（加進總和）就好了；當牠的尾巴往前縮一格（`left++`），只需要把「尾巴原本那格」大便排出來（從總和扣掉）就好了。完全不需要每次都把肚子裡的食物吐出來重新吃一遍呀！
> 
> 如果保留這個內部的 `for` 迴圈，程式的時間複雜度又會退化回 $\mathcal{O}(N^2)$，這樣在 Online Judge 上很容易又會遇到超時 (TLE) 喔。
> 
> * **修改方向**：
>     1. 把 `int tempSum = 0;` 移到 `while` 迴圈的**外面**（讓它變成一個持續記錄肚子裡食物總和的變數）。
>     2. 移除裡面的 `for` 迴圈。
>     3. 當 `right` 要往右移時，就把 `seq.at(right)` **加**到 `tempSum` 裡。
>     4. 當 `left` 要往右移時，就把 `seq.at(left)` 從 `tempSum` 裡**扣掉**。
>
> written by gemini

## afterClass_v4

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
    int S = 0;

    while (cin >> N >> S)
    {
        vector<int> seq(N, 0);
        int right = 0;
        int left = 0;
        int minLength = N;
        bool isFound = false;

        for (int i = 0; i < N; i++)
            cin >> seq.at(i);

        int tempSum = 0;
        while (right < N)
        {

            if (tempSum < S)
            {
                tempSum += seq.at(right);
                right++;
            }
            else // tempSum >= S
            {
                if (minLength > (right - left))
                {
                    minLength = (right - left);
                    isFound = true;
                }
                tempSum -= seq.at(left);
                left++;
            }
        }

        if (isFound == true)
            cout << minLength << endl;
        else
            cout << 0 << endl;
    }
}
```