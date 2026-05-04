#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	while (n--)
	{
		string input;
		cin >> input;
		if (input.size() > 128)
		{
			cout << "No" << endl;
			break;
		}
		vector<string> stk;
		for (int i = 0; i < input.size(); i++)
		{
			if (stk.empty() == true)
			{
				stk.push_back(&input.at(i));
				//cout << stk.at(stk.size() - 1) << endl;
			}
			else // stk is not empty
			{
				if (stk.at(stk.size() - 1) == input.at(i))
			}
		}
	}
}

/*
the maximum string length is 128
stk is empty?
	yes: push
	no:
	stk top == input at i?
		yes: pop
		no: push
*/