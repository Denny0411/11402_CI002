#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	string s1, s2;

	while (cin >> s1 >> s2)
	{
		map<char, int> map1;
		for (int i = 0; i < s1.size(); i++)
		{
			auto search = map1.find(s1.at(i));
			if (search == map1.end()) // not found
			{
				map1[s1.at(i)] = 1;
			}
			else
			{
				map1[s1.at(i)]++;
			}
		}

		map<char, int> map2;
		for (int i = 0; i < s2.size(); i++)
		{
			auto search = map2.find(s2.at(i));
			if (search == map2.end()) // not found
			{
				map2[s2.at(i)] = 1;
			}
			else
			{
				map2[s2.at(i)]++;
			}
		}

		if (map1.size() <= map2.size())
		{
			for (int i = 0; i < map1.size(); i++)
			{
				map2.find(map1.at(i)->first);
			}
		}
		else
		{

		}
	}
}

/*
input
計算每個字元出現的次數
如果兩者皆有
	取較少的那一方
*/