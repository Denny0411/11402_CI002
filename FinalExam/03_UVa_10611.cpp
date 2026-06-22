#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, q;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
	}
	cin >> q;
	vector<int> b(q);
	for (int i = 0; i < q; i++)
	{
		cin >> b.at(i);
	}

	for (int caseNum = 0; caseNum < q; caseNum++)
	{
		int shorter = -1;
		int taller = b.at(caseNum);
		for (int i = 0; i < a.size(); i++)
		{
			// ¸G¡A³Ì°ª
			if (a.at(i) < b.at(caseNum))
			{
				if (shorter < a.at(i))
					shorter = a.at(i);
			}
			else if (a.at(i) > b.at(caseNum))
			{
				if (taller > a.at(i))
					taller = a.at(i);
			}
		}

		if (shorter != -1)
			cout << shorter << " ";
		else
			cout << "X ";
		if (taller != -1)
			cout << taller << endl;
		else
			cout << "X" << endl;
	}
}