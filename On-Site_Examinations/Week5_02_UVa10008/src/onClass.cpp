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
	//for (int i = 0; i < n; i++)
	//{
	//	cout << input[i] << endl;
	//}

	// 刪掉除了字母以外的字元
	// 將小寫變成大寫
	for (int i = 0; i < n; i++)
	{
		//cout << input[i] << endl;
		for (int j = 0; j < input[i].size(); j++)
		{
			//cout << "input[i].at(j): " << input[i].at(j) << endl;
			//cout << isalpha(input[i].at(j)) << " ";
			if (!isalpha(input[i].at(j)))
			{
				//cout << "erase: " << input[i].at(j) << endl;
				input[i].replace(j, 1, "");
				j--;
			}
			if (islower(input[i].at(j)))
			{
				input[i].at(j) = toupper(input[i].at(j));
			}
		}
		//cout << input[i] << endl;
	}

	unordered_map<char, int> count;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			count[input[i].at(j)]++;
			//cout <<"count[input[i].at(j)]: " << count[input[i].at(j)] << endl;
		}
	}

	for (int i = 0; i < count.size(); i++)
	{
		cout << count[i] << endl;
	}
}