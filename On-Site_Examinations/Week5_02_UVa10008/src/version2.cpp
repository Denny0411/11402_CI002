#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

bool compareRule(const pair<char, int>& a, const pair<char, int>& b)
{
    // 規則一：如果兩者的出現次數不同
    if (a.second != b.second)
    {
        // 次數多的排前面 (a.second > b.second 成立時回傳 true)
        return a.second > b.second;
    }
    else // a.second == b.second
    {
        // 字母順序小的排前面 (a.first < b.first 成立時回傳 true)
        return a.first < b.first;
    }
}

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

    vector<int> count(26);
    vector< pair<char, int> > letterData;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			if (isalpha(input[i].at(j)))
			{
                input[i].at(j) = toupper(input[i].at(j));
                count.at(input[i].at(j) - 'A')++;
			}
		}
	}

    for (int i = 0; i < 26; i++)
    {
        if (count.at(i) > 0)
        {
            letterData.push_back(make_pair('A' + i, count.at(i)));
        }
    }

    sort(letterData.begin(), letterData.end(), compareRule);

    for (int i = 0; i < letterData.size(); i++)
    {
        cout << letterData.at(i).first << " " << letterData.at(i).second << endl;
    }
}