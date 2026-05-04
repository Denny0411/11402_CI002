#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	int N = -1;
	cin >> N;
	while (N > 0)
	{
		vector<int> block(N);
		bool isEnd = false;
		for (int i = 0; i < N; i++)
		{
			cin >> block.at(i);
			if (i == 0 && block.at(i) == 0)
			{
				isEnd = true;
				break;
			}
		}

		

		cin >> N;
	}
}

/*
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
*/