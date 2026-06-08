# STL vector

- vector 是**類別模板 class template**。

## 基本操作：宣告、初始化、賦值

在使用 vector 前，需要將標頭檔 `<vector>` 包涵進來。

```cpp
// Include the vector library
#include <vector>
```

vector 的宣告：`vector<type> vectorName` 。

`< >`：角括號 angle brackets

```cpp
// Create a vector called cars that will store strings
vector<string> cars;
```

宣告二維 vector 的方法：

```cpp
vector<vector<int>> intVector;
```

如果要在 `vector` 初始化時賦值，請將元素 elements 放在大括號 curly braces `{ }` 中，並使用逗號 `,` 分隔每個元素，編譯器會自動分配相對應的空間。

<aside>
❗

賦值初始化是使用大括號 `{ }`，而不是括弧 `( )`。

</aside>

```cpp
// Create a vector called cars that will store strings
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
```

我們也可以在初始化時指定 vector 的元素數量，就像 `int array[10];` 。

<aside>
❗

初始化並指定元素數量是使用括弧 `( )`。

</aside>

```cpp
vector<int> intVector(10); // 10 個元素，預設會被初始化為 0
vector<string> stringVector(10); // 10 個元素，預設會被初始化為空字串
```

我們也可以指定初始化時的元素。

```cpp
vector<int> intVector(10, 1); // 10 個元素，預設會被初始化為 1
vector<string> stringVector(10, "hi!"); // 10 個元素，預設會被初始化為"hi!"
```

vector 跟 vector 之間可以賦值，但請注意：**型別需一致**。

```cpp
vector<string> vec1 = {"Volvo", "BMW", "Ford", "Mazda"};
vector<string> vec2 = vec1;

for (string element : vec2)
{
    cout << element << " ";
    // Volvo BMW Ford Mazda
}
```

如果要指定 vector 中特定的元素，方法就跟 array 一樣：`vector_name[vector_index]`

```cpp
// Create a vector called cars that will store strings
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

// Get the first element
cout << cars[0];  // Outputs Volvo

// Get the second element
cout << cars[1];  // Outputs BMW
```

### `.assing()`

還記得作業的大數除法，其中的減法函式嗎？

```cpp
// minuend -= subtrahend
// provided that minuend != 0, subtrahend != 0 and minuend >= subtrahend
void subtraction(vector< int >& minuend, vector< int > subtrahend)
{
    if (equal(minuend, subtrahend))
    {
		    // 原本的寫法
        // minuend.resize(1);
        // minuend.at(1) = 0;
        
        // 新的寫法
        minuend.assign(1, 0);
        return;
    }
```

當 `minuend == subtrahend` 時，我們要無視原本的元素跟數量，將 `minuend` 變成只有 1 個元素的 vector，且該元素是 0。

[Wiki - acm/course/Vector](https://wiki.csie.ncku.edu.tw/acm/course/Vector)

使用 `.assign()` 對 vector 賦值的話會將 vector 內原有的所有資料覆蓋。

`.assign()` 的用法與宣告時類似，但沒有只給一個參數 (amount) 的用法。

```cpp
vector<int> intVector;
intVector.assign(3, 8); // 三個元素，元素是 8

for (int element : intVector)
    cout << element << " "; // 8 8 8
cout << endl;

vector<string> stringVector;
stringVector.assign(5, "Hi"); // 5 elements, element is "Hi"

for (string element : stringVector)
    cout << element << " "; // Hi Hi Hi Hi Hi
cout << endl;
```

## `.front()`, `.back()`, `.at()`

使用成員函式 member function `.front()` 跟 `.back()` 指定 vector 中最前跟最後的元素。

```cpp
// Create a vector called cars that will store strings
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

// Get the first element
cout << cars.front(); // Volve

// Get the last element
cout << cars.back(); // Mazda
```

成員函式 `vector_name.at(vector_index)` 跟 `vector_name[vector_index]` 很像，但 `.at()` 在指定不存在或超出範圍 out of range 的元素時，會回傳錯誤訊息 error message。

```cpp
// Create a vector called cars that will store strings
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

// same output
cout << cars[0] << endl;
cout << cars.at(0) << endl;

// Try to access an element that does not exist
cout << cars[6] << endl; // output nothing, newline and continue
cout << cars.at(6) << endl; // throws an error message, program stop
```

更改 vector 中的元素：

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

cout << cars[0] << endl; // Volvo

// Change the value of the first element
cars[0] = "Opel";

cout << cars[0] << endl; // Opel
```

也可以使用 `.at()` 更改元素，這是更安全的方法。

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

cout << cars.at(0) << endl; // Volvo

// Change the value of the first element
cars.at(0) = "Opel";

cout << cars.at(0) << endl; // Opel
```

## `.push_back()` and `.pop_back()`

接下來是跟 array 不同的地方，vector 類別有很多好用的成員函式。

首先是 `vector_name.push_back(new_element)` ，它會在該 vector 最後面放進新的元素。

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

// add "Tesla" at the end of vector "cars"
cars.push_back("Tesla");

// 遍歷 cars 中的元素
for (string car : cars)
{
    cout << car << " ";
    // Volvo BMW Ford Mazda Tesla
}
```

![](assets/C++%20Vector/file-20251116192001201.png)

接下來是 `vector_name.pop_back()`，它會刪除該 vector 最後面的元素。

```cpp
    vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    // delete last element in vector "cars", that is "Mazda"
    cars.pop_back();

    // 遍歷 cars 中的元素
    for (string car : cars)
    {
        cout << car << " ";
        // Volvo BMW Ford
    }
```

![](assets/C++%20Vector/file-20251116192008584.png)

## `.size()`, `.resize()` and `.empty()`

使用 `vector_name.size()` 查看該 vector 的元素個數。

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
cout << cars.size(); // 4
```

使用 `vector_name.resize(number)` 重新指定該 vector 的大小。

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};
cars.resize(2);

for(string element : cars)
{
    cout << element << " ";
    // Volvo BMW
}
```

使用 `vector_name.empty()` 查看該 vector 是否為空（沒有元素）：
沒有元素：`return 1`
有元素：`return 0`

```cpp
vector<string> vec1;
vector<string> vec2 = {"Volvo", "BMW", "Ford", "Mazda"};
cout << vec1.empty() << endl; // 1
cout << vec2.empty() << endl; // 0
```

## 遍歷 vector 元素的方法

我們可以使用 `vector_name.size()` 搭配 for 迴圈以達成對 vector 的遍歷。

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

for (int i = 0; i < cars.size(); i++) // cars.size() == 4
{
    cout << cars[i] << " ";
    // Volvo BMW Ford Mazda
}
```

或是使用 for-each loop 的方式。

```cpp
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

for (string car : cars)
{
    cout << car << " ";
    // Volvo BMW Ford Mazda
}
```

### 範例：印出二維 vector

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<vector<int>> intVector = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34}
    };

    for (int row = 0; row < intVector.size(); row++)
    {
        for (int column = 0; column < intVector[row].size(); column++)
        {
            cout << intVector[row][column] << " ";
        }
        cout << endl;
    }
}
```

```
11 12 13 14 
21 22 23 24
31 32 33 34
```

使用 `.at()` 的方法

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<vector<int>> intVector = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34}
    };

    for (int row = 0; row < intVector.size(); row++)
    {
        for (int column = 0; column < intVector.at(row).size(); column++)
        {
            cout << intVector.at(row).at(column) << " ";
        }
        cout << endl;
    }
}
```

```
11 12 13 14 
21 22 23 24
31 32 33 34
```

## 將 vector 的資料指定為同一個值

```cpp
// size is 5, initialize with 0
vector<int> tree(5, 0);
// 0 0 0 0 0

// need to include <algorithm>
fill(tree.begin(), tree.end(), 1);
// 1 1 1 1 1
```