#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	cin.ignore();

	for (int caseNum = 0; caseNum < n; caseNum++)
	{
		string input;
		getline(cin, input);
		if (input.size() > 128)
		{
			cout << "No" << endl;
			continue;
		}
		else if (input.empty() == true)
		{
			cout << "Yes" << endl;
			continue;
		}
		stack<char> stk;
		for (int i = 0; i < input.size(); i++)
		{
			if (stk.empty() == true)
			{
				stk.push(input.at(i));
			}
			else // stk is not empty
			{
				if ((stk.top() == '[' && input.at(i) == ']') || (stk.top() == '(' && input.at(i) == ')'))
				{
					stk.pop();
				}
				else
				{
					stk.push(input.at(i));
				}
			}
		}
		if (stk.empty() == true)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}