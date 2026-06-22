#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
	string s, s1, s2;
	unordered_map<string, string> dic;
	while (getline(cin, s) && s != "")
	{
		stringstream ss(s);
		ss >> s1 >> s2;
		dic.insert({ s2, s1 });
	}

	while (getline(cin, s) && s != "")
	{
		auto search = dic.find(s);
		if (search != dic.end())
		{
			cout << search->second << endl;
		}
		else
		{
			cout << "eh" << endl;
		}
	}
}

//int main()
//{
//	string s1, s2, s;
//	vector<pair<string, string>> dic;
//	while (getline(cin, s) && s != "")
//	{
//		stringstream ss(s);
//		ss >> s1 >> s2;
//		dic.push_back(make_pair(s1, s2));
//	}
//
//	while (getline(cin, s) && s != "")
//	{
//		//if (s == "")
//		//	break;
//		int index = -1;
//		for (int i = 0; i < dic.size(); i++)
//		{
//			if (dic.at(i).second == s)
//			{
//				index = i;
//				break;
//			}
//		}
//		if (index != -1)
//		{
//			cout << dic.at(index).first << endl;
//		}
//		else
//		{
//			cout << "eh" << endl;
//		}
//	}
//}