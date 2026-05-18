#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	int l = 0;
	cin >> l;

	while (l--)
	{
		int d = 0, i = 0; // depth and i-th ball
		cin >> d >> i;
        		
		// ball fall
		int currentNode = 1; // node begin with 1
        int remainBall = i;
        for (int depth = 1; depth < d; depth++)
        {
            if (remainBall % 2 == 1) // remainBall is odd
            {
                // left child
                currentNode = currentNode * 2;
                remainBall = (remainBall + 1) / 2;
            }
            else if (remainBall % 2 == 0) // remainBall is even
            {
                // right child
                currentNode = currentNode * 2 + 1;
                remainBall /= 2;
            }
        }

		cout << currentNode << endl;
	}
	int constant = 0;
	cin >> constant;
	return 0;
}