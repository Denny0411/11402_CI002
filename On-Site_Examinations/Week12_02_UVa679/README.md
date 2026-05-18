# UVa 679 - Dropping Balls

## Link

## onClass

Result: Time limit exceeded

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using LL = long long;

int main()
{
	int l = 0;
	cin >> l;

	int nodeNum = 0;
	for (int i = 1; i <= 20; i++)
	{
		nodeNum += pow(2, (i - 1));
	}
	vector<int> tree(nodeNum + 1, 0); // initial with 0, use 1 to nodeNum

	while (l--)
	{
		int d = 0, i = 0; // depth and i-th ball
		cin >> d >> i;
		
		// ball fall
		LL output = 0;
		for (int ball = 1; ball <= i; ball++)
		{
			LL currentNode = 1;
			for (int depth = 1; depth < d; depth++)
			{
				// 1. tree.at(currentNode) == 0
				//    let node become 1
				//	  go left -> modify currentNode
				if (tree.at(currentNode) == 0)
				{
					tree.at(currentNode) = 1;
					currentNode = currentNode * 2;
				}
				// 2. tree.at(currentNode) == 1
				//    let node become 0
				//	  go right -> modify currentNode
				else
				{
					tree.at(currentNode) = 0;
					currentNode = currentNode * 2 + 1;
				}
				if (depth == (d - 1))
					output = currentNode;
				//cout << "currentNode: " << currentNode << endl;
			}
		}
		cout << output << endl;
	}
	int constant = 0;
	cin >> constant;
	return 0;
}
```

## Analysis 1

* $2 \le D \le 20, 1 \le I \le 524288$
* 目前做法的複雜度是 $O(DI)$，**一個 test case** 最差情況跑 $10,000,000$ 次。
* 測資可能有幾百個 test cases，需要進行破億次計算。
    > * 通常 1 秒內大約只能處理 $10^8$ 次運算。by gemini

`vector<int> tree` 的問題：

* `vector<int> tree` 在每執行完一次 test case 後應該要進行初始化，否則會導致錯誤。
* 在 `while (l--)` 加入 `fill(tree.begin(), tree.end(), 0);` 初始化 `tree` 的值。

對節點 1 來說：
```
start with 0 (left)

1st ball:
go left
0 -> 1 (right)

2nd ball:
go right
1 -> 0 (left)

3rd ball:
go left
0 -> 1

4th ball:
go right
1 -> 0
```
假設共有 n 顆球經過節點 1
* 如果 n 是偶數，節點的值最後會是 0，節點 $1 \times 2 = 2$ 有 $n / 2$ 顆球。
* 如果 n 是奇數，節點的值最後會是 1，節點 $1 \times 2 + 1 = 3$ 有 $n / 2$ 顆球。

對節點 i 來說，假設共有 n 顆球經過節點 i
* 如果 n 是偶數，節點的值最後會是 0，left child $2i$ 有 $n / 2$ 顆球，right child $2i + 1$ 有 $n / 2$ 顆球。
* 如果 n 是奇數，節點的值最後會是 1，left child $2i$ 有 $(n + 1) / 2$ 顆球，right child $2i + 1$ 有 $n / 2$ 顆球。

假設只看第 I 顆球：
```
if I is odd
    go left
    there are (I + 1) / 2 balls go left
if I is even
    go right
    there are I / 2 balls go right
```

## afterClass_v1

Result: accepted

```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int l = 0;
	cin >> l;

	while (l--)
	{
		int d = 0, i = 0; // depth and i-th ball
		cin >> d >> i;
        		
		// ball fall
		int currentNode = 1; // node begin with 1
        int remainBall = i;
        for (int depth = 1; depth < d; depth++)
        {
            if (remainBall % 2 == 1) // remainBall is odd
            {
                // left child
                currentNode = currentNode * 2;
                remainBall = (remainBall + 1) / 2;
            }
            else if (remainBall % 2 == 0) // remainBall is even
            {
                // right child
                currentNode = currentNode * 2 + 1;
                remainBall /= 2;
            }
        }

		cout << currentNode << endl;
	}
	int constant = 0;
	cin >> constant;
	return 0;
}
```