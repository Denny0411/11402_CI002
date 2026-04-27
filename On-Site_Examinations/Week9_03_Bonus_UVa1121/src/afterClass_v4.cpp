#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0;
    int S = 0;

    while (cin >> N >> S)
    {
        vector<int> seq(N, 0);
        int right = 0;
        int left = 0;
        int minLength = N;
        bool isFound = false;

        for (int i = 0; i < N; i++)
            cin >> seq.at(i);

        int tempSum = 0;
        while (right < N)
        {

            if (tempSum < S)
            {
                tempSum += seq.at(right);
                right++;
            }
            else // tempSum >= S
            {
                if (minLength > (right - left))
                {
                    minLength = (right - left);
                    isFound = true;
                }
                tempSum -= seq.at(left);
                left++;
            }
        }

        if (isFound == true)
            cout << minLength << endl;
        else
            cout << 0 << endl;
    }
}