# UVa 514 – Rails

## Link

https://onlinejudge.org/external/5/514.pdf

## Translation

在 PopPush 城市裡有一個著名的火車站。那個國家的地形非常崎嶇。這個車站建於上個世紀。不幸的是，當時的資金極度有限。只能建立一條地面軌道。此外，結果這個車站只能是一個死胡同（見圖），而且由於缺乏可用空間，它只能有一條軌道。

當地的傳統是，每列從方向 A 抵達的火車，其車廂會以某種方式重新排列後，繼續往方向 B 行駛。假設從方向 A 抵達的火車有 $N\le1000$ 節車廂，按遞增順序編號為 $1, 2,..., N$。負責火車重組的站長必須知道，是否有可能將繼續開往方向 B 的車廂排列成 $a_{1}.a_{2},...,a_{N}$ 的順序。請幫助他寫一個程式，判斷是否能得到所需的車廂順序。

你可以假設單節車廂在進入車站前可以與列車斷開連接，並且它們可以自行移動，直到它們位於前往方向 B 的軌道上。你也可以假設在任何時候，車站內都可以停放所需數量的車廂。但是，一旦車廂進入車站，就不能返回方向 A 的軌道；同樣地，一旦它離開車站前往方向 B，就不能再返回車站。

輸入 

輸入檔包含多個區塊的行。除了最後一個區塊外，每個區塊描述一列火車，以及可能多個關於其重組的要求。在區塊的第一行包含上述的整數 N。在該區塊接下來的每一行中，有一個 $1,2,...,N$ 的排列，該區塊的最後一行只包含 '0'。最後一個區塊只包含一行 '0'。

輸出 

輸出檔包含對應於輸入檔中排列行的行。如果可以按照輸入檔對應行所需的順序排列車廂，則輸出檔的該行包含 'Yes' 。否則它包含 'No'。此外，在對應於輸入檔一個區塊的行之後，有一行空行。輸出檔中沒有對應於輸入檔最後一個「空」區塊的行。

## onClass

### Thinking Logic and Solution Strategy

```
1 2 3 4 5

A -> B
1 2 3 4 5

A -> station(stack) -> B
5 4 3 2 1

5 // 5 trains
1 2 3 4 5
5 4 1 2 3
0 // end of test case

6 // 6 trains
6 5 4 3 2 1
0 // end of test case

0 // terminate

if stack.top() == target ptr
	stack.pop()
if target ptr == input ptr
	target ptr++
	input ptr++

if target ptr != input ptr
	stack.push(input ptr)
```

這題對我來說是一個挑戰，我在上機考時連 input 都不太確定怎麼處理。

## afterClass

### Thinking Logic and Solution Strategy

```
--- Input ---
5 // 火車車廂的總數
1 2 3 4 5 // 如果數列的第一個數字不是 0，代表這是需要處理的數列。
5 4 1 2 3 // 如果數列的第一個數字不是 0，代表這是需要處理的數列。
0 // 如果數列的第一個數字是 0，處理下一個 case。

6 // 火車車廂的總數
6 5 4 3 2 1 // 如果數列的第一個數字不是 0，代表這是需要處理的數列。
0 // 如果數列的第一個數字是 0，處理下一個 case。

0 // 火車車廂的總數，如果是 0，代表程式結束。

--- Output ---
Yes
No

Yes
```

* 車廂進站的順序是 increasing order $1, 2, ..., N$。
* $1, 2, ..., N$ 經過處理後能不能變成輸入（期望）的數列？
* `1 2 3 4 5` <- `1 2 3 4 5`：火車不需要進入車站調整，就可以直接出站。

```
input: 1 2 3 4 5

current: 1
A: 1 2 3 4 5
station: 

```

### Code

Result: accepted

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // N 節車廂
    int N = 0;

    while (cin >> N && N != 0) // N 不是 0 就繼續執行
    {
        int first_train = 0;

        // 如果數列的第一個數字不是 0，代表這是需要處理的數列
        // 如果數列的第一個數字是 0，處理下一個 case -> 輸入下一個 case 的 N
        while (cin >> first_train && first_train != 0)
        {
            // 期望的目標排序
            // 有 N 節車廂
            vector<int> target(N);
            target.at(0) = first_train;

            // 讀取接下來 N - 1 個數字
            for (int i = 1; i < N; i++)
            {
                cin >> target.at(i);
            }

            stack<int> station;
            int target_index = 0;

            // 目前在 side A 上準備進站的車廂號碼，increasing order
            for (int sideA = 1; sideA <= N; sideA++)
            {
                station.push(sideA);
                while (station.empty() == false && station.top() == target.at(target_index))
                {
                    station.pop();
                    target_index++;
                }
            }

            // 檢查 station 是不是空的
            if (station.empty() == true)
                cout << "Yes" << endl;
            else // station.empty() == false
                cout << "No" << endl;
        }

        // 同一個 N 的測資結束後，要印出一行空行
        cout << endl;
    }
    return 0;
}
```