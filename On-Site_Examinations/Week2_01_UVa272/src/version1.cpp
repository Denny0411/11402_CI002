#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input;
	//char* input[1000];
    int pair = 0;

	while (getline(cin, input))
	{
		//cout << input << endl;
        //cout << input.size() << endl;
		for (int i = 0; i < input.size(); i++)
		{
            if (input.at(i) == '"' && pair % 2 == 0)
            {
                cout << "``";
                pair++;
            }
            else if (input.at(i) == '"' && pair % 2 == 1)
            {
                cout << "''";
                pair++;
            }
            else
            {
                cout << input.at(i);
            }
		}
        cout << endl;
	}
}