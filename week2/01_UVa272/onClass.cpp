#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	//char* input[1000];

	while (cin.getline(input, ))
	{
		//cout << input << endl;
		for (int i = 0; i < input.size(); i++)
		{
			int pair = 0;
			if (input.at(i) == '\'' && input.at(i - 1) == '\'' && pair % 2 == 0)
			{
				input.at(i) = '`';
				input.at(i - 1) = '`';
				pair++;
			}
			else if (input.at(i) == '\'' && input.at(i - 1) == '\'' && pair % 2 == 1)
			{
				input.at(i) = '\'';
				input.at(i - 1) = '\'';
				pair++;
			}
		}
		cout << input << endl;
	}
}