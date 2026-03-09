#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input[101];
	int row = 0;

	while (getline(cin, input[row]))
	{
		row++;
	}

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
		input[i].resize(max, ' ');
	}

	for (int i = 0; i < max; i++)
	{
		for (int j = row - 1; j >= 0; j--)
		{
			cout << input[j][i];
		}
		cout << endl;
	}
}