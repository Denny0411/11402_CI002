#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool rule(const pair<int, int>& a, const pair<int, int>& b)
{
	// 次數由小到大
	if (a.second < b.second)
		return a.second < b.second;
	// 次數一樣，則 asciiNum 由大到小
	else if (a.second == b.second)
		return a.first > b.first;
}

int main()
{
	string input;

	while (getline(cin, input))
	{
		vector < pair<int, int> > freq;
		
		for (int i = 0; i < input.size(); i++)
		{
			int asciiNum = static_cast<int>(input.at(i));
			
			bool exist = false;
			for (int j = 0; j < freq.size(); j++)
			{
				if (freq.at(j).first == asciiNum)
				{
					exist = true;
					freq.at(j).second++;
					break;
				}
			}
			if (exist == false)
			{
				freq.push_back(make_pair(asciiNum, 1));
			}
		}
		//sort(freq.begin(), freq.end(), rule(freq.front(), freq.back()));
		sort(freq.begin(), freq.end(), rule);
		for (int i = 0; i < freq.size(); i++)
		{
			cout << freq.at(i).first << " " << freq.at(i).second << endl;
		}
		cout << endl;
	}
}

/*
1. 輸入字元
2. 將字元轉換成該字元的 ascii code number
3. 統計數量 count pair<int, int> #include <utility>
	* 已經有過
	* 第一次出現
4. cout << count.first << count.second;
*/