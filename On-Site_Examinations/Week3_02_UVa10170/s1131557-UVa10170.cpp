#include <iostream>

using namespace std;
using ULL = unsigned long long int;

bool judge(ULL begin, ULL end, ULL D)
{
	if (begin <= D && D <= end)
		return false;
	else
		return true;
}

int main()
{
	ULL S; // denotes the initial size of the group
	ULL D;

	while (cin >> S >> D)
	{
		ULL peopleNum = S;
		ULL beginDay = 1;
		ULL endDay = S;

		// if beginDay <= D && D <= endDay, output peopleNum
		while (judge(beginDay, endDay, D))
		{
			beginDay += peopleNum;
			endDay = beginDay + peopleNum;
			peopleNum++;
		}
		cout << peopleNum << endl;
	}
}