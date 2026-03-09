# Version 1

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
    int pair = 0;

	while (getline(cin, input))
	{
		for (int i = 0; i < input.size(); i++)
		{
			if (input.at(i) == '\'' && input.at(i - 1) == '\'' && pair % 2 == 0)
			{
				input.at(i) = '`';
				input.at(i - 1) = '`';
				pair++;
			}
			else if (input.at(i) == '\'' && input.at(i - 1) == '\'' && pair % 2 == 1)
			{
				input.at(i) = '\'';
				input.at(i - 1) = '\'';
				pair++;
			}
		}
		cout << input << endl;
	}
}
```
input:
```
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
```

output:
```
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
```

currect output:
```
``To be or not to be,'' quoth the Bard, ``that
is the question''.
The programming contestant replied: ``I must disagree.
To `C' or not to `C', that is The Question!''
```

目前的程式並沒有改變字元。

## Analysis

* 輸入的是雙引號，並不是兩個單引號。
* 將輸入的雙引號一個字元改成兩個字元，不如直接每個字元遍歷輸出，遇到雙引號再根據 pair 更改輸出。

# Version 2

```cpp
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
    int pair = 0;

	while (getline(cin, input))
	{
		for (int i = 0; i < input.size(); i++)
		{
            if (input.at(i) == '"' && pair % 2 == 0)
            {
                cout << "``";
                pair++;
            }
            else if (input.at(i) == '"' && pair % 2 == 1)
            {
                cout << "''";
                pair++;
            }
            else
            {
                cout << input.at(i);
            }
		}
        cout << endl;
	}
}
```

input:
```
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"
```

output:
```
``To be or not to be,'' quoth the Bard, ``that
is the question''.
The programming contestant replied: ``I must disagree.
To `C' or not to `C', that is The Question!''
```

## Result

Accepted