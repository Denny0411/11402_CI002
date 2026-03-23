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
		for (int j = 0; j < n; j++)
		{
			string action;
            cin >> action;

			if (action == "LEFT")
			{
				position--;
				sameas.push_back(-1);
			}
			else if (action == "RIGHT")
			{
				position++;
				sameas.push_back(1);
			}
			else // action == "SAME", read "AS" [num]
			{
                string as_word;
                int num;
                cin >> as_word >> num;

				position += sameas.at(num - 1);
				sameas.push_back(sameas.at(num - 1));
			}
		}
		cout << position << endl;
	}
}