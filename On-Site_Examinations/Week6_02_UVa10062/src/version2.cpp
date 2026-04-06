#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool rule(const pair<int, int>& a, const pair<int, int>& b)
{
    // 首要條件：如果兩者的「次數」不相等
    if (a.second != b.second)
    {
        return a.second < b.second;
        // if a.second > b.second,
        // rule() will return 'false',
        // pair a and pair b will swap.
        // else if a.second < b.second,
        // rule() will return 'true',
        // pair a and pair b won't swap.
        // this's how std::sort work.
    }
    // 次要條件：如果兩者的「次數」相等
    else // a.second == b.second
    {
        // ASCII 大的排前面
        return a.first > b.first;
    }
}

int main()
{
	string input;
    bool isFirstOutput = true; // 處理 output 要求的空白行

	while (getline(cin, input))
	{
		vector < pair<int, int> > freq;
		
		for (int i = 0; i < input.size(); i++)
		{
			int asciiNum = static_cast<int>(input.at(i));

            // 代表還沒有任何 pair 在 vector
            // 或是該 asciiNum 還沒有對應的 pair
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

        sort(freq.begin(), freq.end(), rule);

        if (isFirstOutput == false)
            cout << endl;

        isFirstOutput = false;

		for (int i = 0; i < freq.size(); i++)
		{
			cout << freq.at(i).first << " " << freq.at(i).second << endl;
		}
	}
}