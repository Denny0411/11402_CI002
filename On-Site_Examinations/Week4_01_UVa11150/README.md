# UVa11150 - Cola

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 11150
- **Problem Title:** Cola
- **Problem Link:** https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=23&page=show_problem&problem=2091
- **Source Code (Fail):** [src/onClass.cpp](./src/onClass.cpp)
- **Source Code (Correct/Accepted):** 
    1. [src/version1.cpp](./src/version1.cpp)
    2. [src/version2.cpp](./src/version2.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- What is the input?
- What is the expected output?
- What are the main rules or constraints?
- What is the core task you must solve?

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

* 有辦法靠一個數學公式算出答案嗎？

### Final Strategy

- What method did you finally use?
- Why does this method work?
- What edge cases did you consider?

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. 
2. 
3. 
4. 
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Fail Code

```cpp
#include <iostream>

using namespace std;

int main()
{
	int full = 0;
	int empty = 0;
	int borrow = 0;

	while (cin >> full)
	{
		int sum = 0;

		if (full % 3 == 2)
		{
			full++;
			borrow = 1;
		}

		while (full >= 3)
		{
			sum += full;
			full /= 3;
		}

		cout << sum << endl;
	}
}
```

**Why it failed:**

- 
- 

### Correct Code

#### Version 1

```cpp
#include <iostream>

using namespace std;

int main()
{
    int N = 0;

    while (cin >> N)
    {
        int sum = N; // 拿到 N 瓶後喝完 N 瓶
        int empty = N; // 喝完 N 瓶後有 N 個空瓶

        while (empty >= 3) // 空瓶有 3 個以上就可以繼續換
        {
            sum += empty / 3;

            // 剛才換的 cola 變成空瓶，加上沒有換出去的空瓶
            empty = empty / 3 + empty % 3;
        }

        // 如果最後空瓶剩下 2 瓶，
        // 可以跟老闆借 1 瓶空瓶，
        // 3 瓶空瓶正好可以換 1 瓶 cola，
        // 把跟老闆借的 1 瓶空瓶還回去。
        if (empty == 2)
        {
            sum++;
        }

        cout << sum << endl;
    }
}
```

#### Version 2

```cpp
#include <iostream>

using namespace std;

int main()
{
    int N = 0;

    while (cin >> N)
    {
        cout << N + N / 2 << endl;
    }
}
```

**Why it works:** 一開始有 N 瓶，喝完變 N 個空瓶，N 個空瓶總計可以換 N / 2 瓶。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic |  |  |
| Edge Cases |  |  |
| Output Handling |  |  |
| Other |  |  |

### Reflection

- What mistake did you make?
- What did you learn from debugging this problem?
- If you solve a similar problem again, what will you do better?