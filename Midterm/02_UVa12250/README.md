# UVa 12250 - Language Detection

## Link

https://onlinejudge.org/external/122/12250.pdf

## onClass_v1

### Thinking Logic and Solution Strategy

```
input
while loop
if input == '#'
	break
case count
switch case
	case ...
	country = ...
	break
```

### Code

Result: wrong answer

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	string country;
	int caseNum = 0;
	while (cin >> input)
	{
		if (input == "#")
			break;

		caseNum++;
		if (input == "HELLO")
			country = "ENGLISH";
		else if (input == "HOLA")
			country = "SPANISH";
		else if (input == "HALLO")
			country = "GREMAN";
		else if (input == "BONJOUR")
			country = "FRENCH";
		else if (input == "CIAO")
			country = "ITALIAN";
		else if (input == "ZDRAVSTVUJTE")
			country = "RUSSIAN";
		else
			country = "UNKNOWN";

		cout << "Case " << caseNum << ": " << country << endl;
	}
	return 0;
}
```

## Analysis 1

version 1 的 output 是輸入一行就輸出一行。

```
HELLO
Case 1: ENGLISH
HOLA
Case 2: SPANISH
```

但是這樣輸出會背叛定為 wrong answer，題目也沒有寫該怎麼輸出，靠通靈跟臨場反應 :(

## onClass_v2

### Code

Result: accepted

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	vector<string> country;

	while (cin >> input)
	{
		if (input == "#")
			break;

		if (input == "HELLO")
			country.push_back("ENGLISH");
		else if (input == "HOLA")
			country.push_back("SPANISH");
		else if (input == "HALLO")
			country.push_back("GERMAN");
		else if (input == "BONJOUR")
			country.push_back("FRENCH");
		else if (input == "CIAO")
			country.push_back("ITALIAN");
		else if (input == "ZDRAVSTVUJTE")
			country.push_back("RUSSIAN");
		else
			country.push_back("UNKNOWN");
	}

	for (int i = 0; i < country.size(); i++)
		cout << "Case " << i + 1 << ": " << country.at(i) << endl;
        
	return 0;
}
```

## Analysis 2

在猜想到判決系統要我等到輸入結束 `#` 再輸出後，我改用 `vector<string> country` 儲存輸出結果。跳出 `while (cin >> input)` 迴圈後，就會進入 `for (int i = 0; i < country.size(); i++)` 迴圈，並把結果 `cout` 出來。

## Analysis 3 真正的錯誤

>這其實是一個美麗的誤會！在大多數的線上解題系統（Online Judge，如 UVa）中，標準輸入 (`cin`) 和標準輸出 (`cout`) 的資料流是獨立且分開的。這代表邊讀取邊輸出（v1），或者全部讀完存起來再輸出（v2），在系統後台對比答案時，產生出來的最終文字結果是完全一模一樣的。
>
>在你的 **v1 (Wrong Answer)** 程式碼中：
>```cpp
>else if (input == "HALLO")
>    country = "GREMAN";
>```
>這裡不小心發生了拼字錯誤，把 `GERMAN` 拼成了 `GREMAN`。
>
>而在你的 **v2 (Accepted)** 程式碼中：
>```cpp
>else if (input == "HALLO")
>	country.push_back("GERMAN");
>```
>你在改寫成 `vector` 版本時，無意間把 `GERMAN` 的拼寫改正確了！
>
>這才是 v2 通過測試，而 v1 沒通過的真正原因喔！這不是因為判決系統需要你等到輸入結束才輸出，單純只是一個小小的拼字錯誤而已。不用靠通靈，你的臨場反應和邏輯本身是沒問題的！
>
>written by gemini

靠北，超低級錯誤。不知道為什麼，當天的 PDF 不能複製文字，我只能手打，結果出了這種低級錯誤，還讓我以為是 output 方式的問題。

## Reflection

程式真的找不到其他問題，程序都很完美的話，請檢查**拼字**。