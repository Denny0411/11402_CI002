#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int caseNum = 0;
	while (T--)
	{
		caseNum++;
		int size = 0;
		cin >> size;
		// char* field = new char[size];
		// vector<char> field(size, '');
		string field;
		cin >> field;

		/*int dotNum = 0;
		int hashNum = 0;
		int crowNum = 0;
		for (int i = 0; i < size; i++)
		{
			if (field[i] == '.')
				dotNum++;
			else if (field[i] == '#')
				hashNum++;
		}

		if (dotNum > 0 && size <= 3)
		{
			for (int i = 0; i < size; i++)
			{
				if (field.at(i) = '.')
				{
					crowNum++;
					break;
				}
			}
		}
		else if (dotNum > 0 && size > 3)
		{
			int fieldPtr = 0;
			while (fieldPtr < field.size())
			{
				bool isDot = false;
				for (int i = fieldPtr; i < fieldPtr + 3 && i < field.size(); i++)
				{
					if (field.at(i) == '.')
					{
						isDot = true;
						break;
					}
				}
				if (isDot == true)
				{
					crowNum++;
				}
				fieldPtr += 3;
			}
		}*/

		int crowNum = 0;
		int tempDotCount = 0;

		for (int i = 0; i < size; i++)
		{
			if (field.at(i) == '.')
			{
				tempDotCount++;
			}
			else // '#'
			{
				crowNum += ceil(static_cast<double>(tempDotCount) / 3.0);
				tempDotCount = 0;
			}
		}
		if (tempDotCount > 0)
			crowNum += ceil(static_cast<double>(tempDotCount) / 3.0);

		cout << "Case " << caseNum << ": " << crowNum << endl;
	}
}

/*
10
....##..#.
Case 3: 4

1
5
.....
Case 1: 2

10
..#..##...
Case 7: 4 // true ans is 3

# 分區塊

. -> 1
.. -> 1
... -> 1
...# -> 1
...## -> 1
...##. -> 2
.(.).##.(.) -> 2
.(.).##.(.). -> 2
.(.).##.(.).(.) -> 3
.(.).##.(.).(.)## -> 4
*/