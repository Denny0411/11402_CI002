#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int caseCount = 0;
	while (cin >> s && s != "#")
	{
		caseCount++;
		if (s == "HELLO")
		{
			cout << "Case " << caseCount << ": ENGLISH" << endl;
		}
		else if (s == "HOLA")
		{
			cout << "Case " << caseCount << ": SPANISH" << endl;
		}
		else if (s == "HALLO")
		{
			cout << "Case " << caseCount << ": GERMAN" << endl;
		}
		else if (s == "BONJOUR")
		{
			cout << "Case " << caseCount << ": FRENCH" << endl;
		}
		else if (s == "CIAO")
		{
			cout << "Case " << caseCount << ": ITALIAN" << endl;
		}
		else if (s == "ZDRAVSTVUJTE")
		{
			cout << "Case " << caseCount << ": RUSSIAN" << endl;
		}
		else
		{
			cout << "Case " << caseCount << ": UNKNOWN" << endl;
		}
	}
}