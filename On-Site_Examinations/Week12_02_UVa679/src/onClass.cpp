#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using LL = long long;

int main()
{
	int l = 0;
	cin >> l;

	int nodeNum = 0;
	for (int i = 1; i <= 20; i++)
	{
		nodeNum += pow(2, (i - 1));
	}
	vector<int> tree(nodeNum + 1, 0); // initial with 0, use 1 to nodeNum

	while (l--)
	{
		int d = 0, i = 0; // depth and i-th ball
		cin >> d >> i;
		
		// ball fall
		
		LL output = 0;
		for (int ball = 1; ball <= i; ball++)
		{
			LL currentNode = 1;
			for (int depth = 1; depth < d; depth++)
			{
				// 1. tree.at(currentNode) == 0
				//    let node become 1
				//	  go left -> modify currentNode
				if (tree.at(currentNode) == 0)
				{
					tree.at(currentNode) = 1;
					currentNode = currentNode * 2;
				}
				// 2. tree.at(currentNode) == 1
				//    let node become 0
				//	  go right -> modify currentNode
				else
				{
					tree.at(currentNode) = 0;
					currentNode = currentNode * 2 + 1;
				}
				if (depth == (d - 1))
					output = currentNode;
				//cout << "currentNode: " << currentNode << endl;
			}
		}
		cout << output << endl;
	}
	int constant = 0;
	cin >> constant;
	return 0;
}

/*

5 // test cases
...
-1 // end of input

root = 1
left = root * 2
right = ...

path, reverse path

*/