#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string input;
	string country;
	int caseNum = 0;
	while (cin >> input)
	{
		if (input == "#")
			break;

		caseNum++;
		if (input == "HELLO")
			country = "ENGLISH";
		else if (input == "HOLA")
			country = "SPANISH";
		else if (input == "HALLO")
		{
			// country = "GREMAN";
			country = "GERMAN";
		}
		else if (input == "BONJOUR")
			country = "FRENCH";
		else if (input == "CIAO")
			country = "ITALIAN";
		else if (input == "ZDRAVSTVUJTE")
			country = "RUSSIAN";
		else
			country = "UNKNOWN";

		cout << "Case " << caseNum << ": " << country << endl;
	}

	return 0;
}