# UVa 10935 - Throwing cards away

## Link

https://onlinejudge.org/external/109/10935.pdf

## onClass

### Thinking Logic and Solution Strategy

```
input until 0

n = 7
1 2 3 4 5 6 7
```

### Code

Result: accepted

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		if (n == 0)
			return 0;

		queue<int> remaining;
		queue<int> discarded;
		for (int i = 1; i <= n; i++)
		{
			remaining.push(i);
		}

		while (remaining.size() != 1)
		{
			int a1 = remaining.front();
			remaining.pop();
			discarded.push(a1);
			int a2 = remaining.front();
			remaining.pop();
			remaining.push(a2);
		}
		
		int size = discarded.size();
		if (size > 0)
		{
			cout << "Discarded cards: ";
			for (int i = 0; i < size - 1; i++)
			{
				cout << discarded.front() << ", ";
				discarded.pop();
			}
			cout << discarded.front() << endl;
		}
		else
			cout << "Discarded cards:" << endl;

		cout << "Remaining card: " << remaining.front() << endl;
	}
}
```