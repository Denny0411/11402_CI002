#include <iostream>

using namespace std;
using LL = long long;

//LL f(LL wall)
//{
//	// end condition
//	if (wall == 1)
//		return 1;
//	else if (wall == 2)
//		return 2;
//
//	// recursive condition
//	return (f(wall - 1) + f(wall - 2));
//}

int main()
{
	LL wall = 0;
	LL arr[51];
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= 50; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	while (cin >> wall)
	{
		if (wall == 0)
			break;

		//cout << f(wall) << endl;
		cout << arr[wall] << endl;
	}
}