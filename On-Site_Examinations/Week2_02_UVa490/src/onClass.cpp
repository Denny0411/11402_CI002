#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	//char input[100][100] = {};
	string input[100];
	int row = 0;

	//while (cin.getline(input[row], 100))
	while (getline(cin, input[row]))
	{
		row++;
	}

	//for (int i = 0; i < row; i++)
	//{
	//	cout << input[i] << endl;
	//}

	//// get max charnum
	//int max = 0;
	//for (int i = 0; i < row; i++)
	//{
	//	for (int j = 0; j < 100; j++)
	//	{
	//		if (input[i][j] == '\n')
	//		{
	//			int tempMax = j;
	//			cout << "tempMax: " << tempMax << endl;
	//			if (max < tempMax)
	//			{
	//				swap(max, tempMax);
	//				cout << "max: " << max << endl;
	//			}
	//		}
	//	}
	//}

	int max = 0;
	for (int i = 0; i < 100; i++)
	{
		if (max < input[i].size())
		{
			max = input[i].size();
		}
	}

	for (int i = 0; i < 100; i++)
	{
		input[i].resize(max);
	}

	for (int i = 0; i <= max; i++)
	{
		for (int j = row - 1; j >= 0; j--)
		{
			cout << input[j][i];
		}
		cout << endl;
	}
}