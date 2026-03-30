#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	cin.ignore();
	string* input = new string[n];
	for (int i = 0; i < n; i++)
	{
		getline(cin, input[i]);
	}

    unordered_map<char, int> count;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i].at(j)))
			{
                input[i].at(j) = toupper(input[i].at(j));
                count[input[i].at(j)]++;
			}
		}
	}

	for (int i = 0; i < count.size(); i++)
	{
		cout << count[i] << endl;
	}
}