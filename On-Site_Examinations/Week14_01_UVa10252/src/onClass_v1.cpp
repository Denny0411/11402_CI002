#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		//vector<char> s1Char, s2Char; // characters no repeat

		//for (int i = 0; i < s1.size(); i++)
		//{
		//	bool isRepeat = false;
		//	for (int j = 0; j < s1Char.size(); j++)
		//	{
		//		if (s1.at(i) == s1Char.at(j))
		//		{
		//			isRepeat = true;
		//			break;
		//		}
		//	}
		//	if (isRepeat == false)
		//		s1Char.push_back(s1.at(i));
		//}

		//for (int i = 0; i < s2.size(); i++)
		//{
		//	bool isRepeat = false;
		//	for (int j = 0; j < s2Char.size(); j++)
		//	{
		//		if (s2.at(i) == s2Char.at(j))
		//		{
		//			isRepeat = true;
		//			break;
		//		}
		//	}
		//	if (isRepeat == false)
		//		s2Char.push_back(s2.at(i));
		//}

		vector<char> repeat;
		//for (int i = 0; i < s1Char.size(); i++)
		//{
		//	for (int j = 0; j < s2Char.size(); j++)
		//	{
		//		if (s1Char.at(i) == s2Char.at(j))
		//		{
		//			repeat.push_back(s1Char.at(i));
		//		}
		//	}
		//}



		for (int i = 0; i < repeat.size(); i++)
			cout << repeat.at(i);
		cout << endl;
	}
}