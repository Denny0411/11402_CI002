#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int wall = 0;
	// long double arr[251];
	vector<long double> arr(251);
	//vector<string> str(251);
	//arr[0] = 1;
	//arr[1] = 1;
	//arr[2] = 3;
	//str.at(0) = "1";
	//str.at(1) = "1";
	//str.at(2) = "3";
	arr.at(0) = 1;
	arr.at(1) = 1;
	arr.at(2) = 3;
	for (int i = 3; i <= 250; i++)
	{
		// arr[i] = 2 * arr[i - 2] + arr[i - 1];
		arr.at(i) = 2 * arr.at(i - 2) + arr.at(i - 1);
		//str.at(i) = to_string(arr.at(i));
		//str.at(i) = to_string(2 * stoi(str.at(i - 2)) + stoi(str.at(i - 1)));
	}

	while (cin >> wall)
	{
		//cout << str.at(wall) << endl;
		cout << arr.at(wall) << endl;
	}
}