#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int level(int num)
{
	int a = 1;
	while (true)
	{
		if (pow(2, a) <= num)
		{
			a++;
		}
		else
			return a;
	}
}

int main()
{
	int t = 0; //  the number of test cases
	cin >> t;
	while (t--)
	{
		// N is the number of generations,
		// and A and B are brothers with the same parents.
		int n = 0, a = 0, b = 0;
		cin >> n >> a >> b;

		int totalNode = 0;
		for (int i = 1; i <= n; i++)
		{
			totalNode += pow(2, (i - 1));
		}

		// 1. a and b are in the same level
		if (level(a) == level(b))
		{
			int minus = 0;
			for (int i =  1; i <= n - level(a); i++)
			{
				minus += pow(2, i);
			}
			// cout << minus << endl;
			cout << totalNode - minus << endl;
		}
		// 2. a and b are NOT in the same level
		else
		{
			// high level node's ascendor need to be minus
			// a. get high level
			int highLevel = max(level(a), level(b));

			int minus = 0;
			for (int i = 1; i <= n - highLevel; i++)
			{
				minus += pow(2, i);
			}
			// cout << minus << endl;
			cout << totalNode - minus << endl;
		}
	}
}

/*

BST

binary tree
left < root
right > root
depth, height
0, 1-2, 3-6, 7-14 with array
1, 2, 4, 8
with mathematical induction
1. 11615
2. 679

1. you
2. father mother

3 cases
4 4 12
// 4 generations, 4 and 12
4 * 2 == 12 * 2
4 * 2 + 1 == 12 * 2 + 1
two merges
15 - 2 = 13

5 2 3
2 3: brothers
31 - (2 + 4 + 8) or 1 + 2 + 2 + 4 + 8

*/