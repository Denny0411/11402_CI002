#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    int arr[12] = {};

    while (cin >> a)
    {
        int index = 0;
        while (a >= 1)
        {
            index++;
            arr[index] = a % 10;
            a /= 10;
        }

        cout << "index: " << index << endl;

        for (int i = index; i >= 1; i--)
        {
            cout << arr[i];
        }
        cout << endl;
    }
}