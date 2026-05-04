# UVa 673 – Parentheses Balance

## Link

https://onlinejudge.org/external/6/673.pdf

## Thinking Logic and Solution Strategy

```
the maximum string length is 128
stk is empty?
	yes: push
	no:
	~~stk top == input at i?~~
    top == ( or [ and input.at(i) == ) or ]
		yes: pop
		no: push
```

## onClass_v1

Result: 無法編譯

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	while (n--)
	{
		string input;
		cin >> input;
		if (input.size() > 128)
		{
			cout << "No" << endl;
			break;
		}
		vector<string> stk;
		for (int i = 0; i < input.size(); i++)
		{
			if (stk.empty() == true)
			{
				stk.push_back(&input.at(i));
			}
			else // stk is not empty
			{
				if (stk.at(stk.size() - 1) == input.at(i))
			}
		}
	}
}
```

## Analysis 1

```cpp
if (input.size() > 128)
{
    cout << "No" << endl;
    break;
}
```

這裡不能用 break，要用 continue 才對。

```cpp
if (stk.at(stk.size() - 1) == input.at(i))
```

報錯：`no operator "==" matches these operands`

宣告：`vector<string> stk;`，`stk.at(stk.size() - 1)` 會是 `string`。
宣告：`string input;`，`input.at(i)` 會是 `string` 中的其中一個 `char`。
`string` 跟 `char` 不能直接用 `==` 比較！

最後，這裡也不應該用 `==` 比較。如果 `stk.at(stk.size() - 1)` 是 `(` 或 `[`，我們應該是要找到相配的 `)` 或 `]`，而不是同樣的 `(` 或 `[`。

## onClass_v2

Result: accepted

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	cin.ignore();

	for (int caseNum = 0; caseNum < n; caseNum++)
	{
		string input;
		getline(cin, input);
		if (input.size() > 128)
		{
			cout << "No" << endl;
			continue;
		}
		else if (input.empty() == true)
		{
			cout << "Yes" << endl;
			continue;
		}
		stack<char> stk;
		for (int i = 0; i < input.size(); i++)
		{
			if (stk.empty() == true)
			{
				stk.push(input.at(i));
			}
			else // stk is not empty
			{
				if ((stk.top() == '[' && input.at(i) == ']') || (stk.top() == '(' && input.at(i) == ')'))
				{
					stk.pop();
				}
				else
				{
					stk.push(input.at(i));
				}
			}
		}
		if (stk.empty() == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}
```

## Problem on the test

在考試時，我一直無法正確使用 STL stack，導致我撞牆花了蠻多時間的。

## afterClass

Result: runtime error

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    cin.ignore(); // 在 getline 前要用 ignore()

    while (n--)
    {
        string input;
        getline(cin, input);

        if (input.size() > 128)
        {
            cout << "No" << endl;
            continue;
        }
        else if (input.size() == 0)
        {
            cout << "Yes" << endl;
            continue;
        }

        stack<char> stk;
        // 走訪 input 每個字元
        for (int i = 0; i < input.size(); i++)
        {
            // case '(' and case '['
            if (input.at(i) == '(' || input.at(i) == '[')
            {
                stk.push(input.at(i));
            }
            else if ((stk.top() == '(' && input.at(i) == ')') || (stk.top() == '[' && input.at(i) == ']'))
            {
                stk.pop();
            }
        }

        if (stk.empty() == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
```

為什麼目前的程式在第二筆測資 `(([()])))` 時會有 runtime error？

> 對一個空的 stack 呼叫 .top() 或 .pop() 會導致未定義行為 (Undefined Behavior) by gemini

其實在 stack 是空的還要繼續比對的情況時，就代表輸出要是 No 了。

---

Result: accepted

```cpp
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    cin.ignore(); // 在 getline 前要用 ignore()

    while (n--)
    {
        string input;
        getline(cin, input);

        if (input.size() > 128)
        {
            cout << "No" << endl;
            continue;
        }

        stack<char> stk;
        // 走訪 input 每個字元
        for (int i = 0; i < input.size(); i++)
        {
            // case '(' and case '['
            if (input.at(i) == '(' || input.at(i) == '[')
            {
                stk.push(input.at(i));
            }
            else if (stk.empty() == true)
            {
                stk.push(input.at(i));
                break;
            }
            else if ((stk.top() == '(' && input.at(i) == ')') || (stk.top() == '[' && input.at(i) == ']'))
            {
                stk.pop();
            }
        }

        if (stk.empty() == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
```