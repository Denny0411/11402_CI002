#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	vector<string> country;

	while (cin >> input)
	{
		if (input == "#")
			break;

		if (input == "HELLO")
			country.push_back("ENGLISH");
		else if (input == "HOLA")
			country.push_back("SPANISH");
		else if (input == "HALLO")
			country.push_back("GERMAN");
		else if (input == "BONJOUR")
			country.push_back("FRENCH");
		else if (input == "CIAO")
			country.push_back("ITALIAN");
		else if (input == "ZDRAVSTVUJTE")
			country.push_back("RUSSIAN");
		else
			country.push_back("UNKNOWN");
	}

	for (int i = 0; i < country.size(); i++)
		cout << "Case " << i + 1 << ": " << country.at(i) << endl;
        
	return 0;
}