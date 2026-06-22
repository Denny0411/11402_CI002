# UVa 410 – Station Balance

## Link

https://onlinejudge.org/external/4/410.pdf

## onClass

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int c; // the number of chambers in the centrifuge 離心機
	int s; // the number of specimens 樣本
	int count = 0;
	while (cin >> c >> s)
	{
		count++;
		vector<int> specimen(s);
		for (int i = 0; i < s; i++)
		{
			cin >> specimen.at(i);
		}
		sort(specimen.begin(), specimen.end());
		vector<vector<int>> ans()
		// case 1: s % c == 1

		// case 2: s % c == 0

		// IMBALANCE
	}
}
```

## Analysis

* no chamber contains more than 2 specimens
* IMBALANCE is minimized

```
2 3
6 3 8

3 specimens -> 2, 1

Set #1
0: 6 3
1: 8
IMBALANCE = 1.00000

3 5
51 19 27 14 33
Set #2
0: 51
1: 19 27
2: 14 33
IMBALANCE = 6.00000

5 9
1 2 3 5 7 11 13 17 19
Set #3
0: 1 17
1: 2 13
2: 3 11
3: 5 7
4: 19
IMBALANCE = 11.60000
```

如果輸入是：
```
2 3
6 3 8
```
我會先把 6 3 8 排序成 3 6 8，然後 3 跟 6 一個 chamber，8 自己一個 chamber。

如果輸入是：
```
3 5
51 19 27 14 33
```
我會先把 51 19 27 14 33 排序成 14 19 27 33 51，然後
```
14 33
19 27
51
```
問題是這樣排序後，該如何照原本的輸入排序，輸出
```
0: 51
1: 19 27
2: 14 33
```

## afterClass

result: accepted

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int c; // the number of chambers in the centrifuge 離心機
    int s; // the number of specimens 樣本
    int count = 0;

    while (cin >> c >> s)
    {
        count++;
        double AM = 0; // Average Mass of the chambers
        vector<int> specimen(s);
        for (int i = 0; i < s; i++)
        {
            cin >> specimen.at(i);
            AM += specimen.at(i);
        }
        AM /= c;

        // 補零技巧 (Dummy Specimens)
        while (specimen.size() < 2 * c)
            specimen.push_back(0);

        sort(specimen.begin(), specimen.end());

        // 配對與計算 IMBALANCE
        double CM = 0; // Chamber Mass of chamber i
        double imbalance = 0;

        cout << "Set #" << count << endl;
        for (int i = 0; i < c; i++)
        {
            int s1 = specimen.at(i);
            int s2 = specimen.at(specimen.size() - 1 - i);
            CM = s1 + s2;
            imbalance += fabs(CM - AM); // abs for float
            // cout << " " << i << ":";
            // if (s1 == 0 && s2 != 0)
            //     cout << " " << s2 << endl;
            // else if (s2 == 0 && s1 != 0)
            //     cout << " " << s1 << endl;
            // else if (s1 == 0 && s2 == 0)
            //     cout << endl;
            // else
            //     cout << " " << s1 << " " << s2 << endl;
            cout << " " << i << ":";
            if (s1 != 0) cout << " " << s1;
            if (s2 != 0) cout << " " << s2;
            cout << endl;
        }
        cout << "IMBALANCE = " << fixed << setprecision(5) << imbalance << endl << endl;
    }
}
```