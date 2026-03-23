#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		int position = 0;
		vector<int> sameas;
		cin >> n;
		cin.ignore();
		for (int j = 0; j < n; j++)
		{
			string input = "";
			
			cin.clear();
			getline(cin, input);
			//cin.ignore();
			//char input[100];
			//cin.getline(input, 100);

			if (input == "LEFT")
			{
				position--;
				sameas.push_back(-1);
			}
			else if (input == "RIGHT")
			{
				position++;
				sameas.push_back(1);
			}
			else // input == "SAME AS XX"
			{
				int count = input.size() - 8;
				string strNum = input.substr(8, count);
				int num = stoi(strNum);
				//cout << "num: " << num << endl;
				//int count = strlen(input);
				//cout << count;
				position += sameas.at(num - 1);
				sameas.push_back(sameas.at(num - 1));
			}
		}
		//cout << "position: " << position << endl;
		cout << position << endl;
	}
}