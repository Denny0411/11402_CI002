# UVa 12503 - Robot Instructions

## 1. Problem Information

- **Platform:** UVa
- **Problem ID:** 12503
- **Problem Title:** Robot Instructions
- **Problem Link:** https://onlinejudge.org/external/125/12503.pdf
- **Source Code (Fail):** [src/onClass.cpp](./src/onClass.cpp)
- **Source Code (Correct/Accepted):** [src/version1.cpp](./src/version1.cpp)

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- What is the input?
- What is the expected output?
- What are the main rules or constraints?
- What is the core task you must solve?

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- What was your first idea?
- What difficulty did you notice at the beginning?

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
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		int position = 0;
		vector<int> sameas;
		cin >> n;
		cin.ignore();
		for (int j = 0; j < n; j++)
		{
			string input = "";
			
			cin.clear();
			getline(cin, input);

			if (input == "LEFT")
			{
				position--;
				sameas.push_back(-1);
			}
			else if (input == "RIGHT")
			{
				position++;
				sameas.push_back(1);
			}
			else // input == "SAME AS XX"
			{
				int count = input.size() - 8;
				string strNum = input.substr(8, count);
				int num = stoi(strNum);
				position += sameas.at(num - 1);
				sameas.push_back(sameas.at(num - 1));
			}
		}
		cout << position << endl;
	}
}
```

**Why it failed:**

問題確實出在「讀取輸入 (Input)」的方式。

### 🚨 潛在的問題點：`getline` 與隱藏字元
在 Online Judge（像是 UVa）的系統中，測試資料的換行符號可能會包含肉眼看不見的隱藏字元（例如 Windows 系統產生的 `\r`）。
當你使用 `getline(cin, input);` 時，它會把整行讀進來，可能會不小心把 `\r` 也讀入字串中。這會導致以下連鎖反應：
1. `input == "LEFT"` 或 `input == "RIGHT"` 會判斷失敗（因為程式看到的是 `"LEFT\r"` 或 `"RIGHT\r"`）。
2. 程式會直接跳到最後的 `else` 區塊，試圖執行 `"SAME AS XX"` 的邏輯。
3. 在 `else` 區塊中，因為字串長度不如預期，`int count = input.size() - 8;` 可能會算出負數，導致接下來的 `substr` 發生超出範圍的錯誤 (Out of Range) 讓程式崩潰。

### 💡 修改方向：讓 `cin` 幫你自動處理
比起一次讀取「整行」再自己辛苦地切割字串，**改用 `cin >>` 逐字讀取單字**會是更安全且簡潔的做法！因為 `cin >>` 在讀取時，會自動幫你忽略掉所有的空格 (Space) 和各種換行符號。

**你可以這樣思考開發步驟：**
1. **先讀第一個單字**：宣告一個字串（例如 `string action;`），然後 `cin >> action;`。
2. **判斷基礎指令**：如果 `action` 是 `"LEFT"` 或是 `"RIGHT"`，就可以直接處理 `position` 和 `sameas` 的更新。[cite: 6]
3. **處理複合指令**：如果 `action` 讀到的是 `"SAME"`，那代表後面一定還跟著一個 `"AS"` 和一個「數字」。這時候，你可以直接再用變數把它們「接」出來，例如：
   ```cpp
   string as_word;
   int num;
   cin >> as_word >> num; 
   ```
   這樣一來，你就直接拿到那個關鍵的 `num` 了，完全不需要用到 `substr` 和 `stoi`！

運用這個方法，你也可以把原本的 `cin.ignore();` 拿掉，因為單純使用 `cin >>` 不會被換行符號卡住。

### Correct Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		int position = 0;
		vector<int> sameas;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			string action;
            cin >> action;

			if (action == "LEFT")
			{
				position--;
				sameas.push_back(-1);
			}
			else if (action == "RIGHT")
			{
				position++;
				sameas.push_back(1);
			}
			else // action == "SAME", read "AS" [num]
			{
                string as_word;
                int num;
                cin >> as_word >> num;

				position += sameas.at(num - 1);
				sameas.push_back(sameas.at(num - 1));
			}
		}
		cout << position << endl;
	}
}
```

**Why it works:**

* 原本的程式邏輯是對的，但對於 input 的處理不是那麼熟悉，導致出現預期之外的 input，程式崩潰。

## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic | same | same |
| Edge Cases |  |  |
| Output Handling |  |  |
| Other |  |  |

### Reflection

- What mistake did you make?  
    在輸入整行的 input 時沒有那麼熟悉。
- What did you learn from debugging this problem?  
    既然 input 還是可預期的，就不一定要用 `getline()` 處理整行 input，可以把他們用 cin 跟多個符合預期型態的變數「接」出來。
- If you solve a similar problem again, what will you do better?  
    需要熟悉 input 的處理。