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

        for (int i = 0; i < N; i++)
            cin >> seq.at(i);

        while (right < N)
        {
            int tempSum = 0;
            for (int i = left; i <= right; i++)
                tempSum += seq.at(i);

            if (tempSum < S)
            {
                right++;
            }
            else // tempSum >= S
            {
                if (minLength > (right - left + 1))
                    minLength = (right - left + 1);

                left++;
            }
        }

        cout << minLength << endl;
    }
}