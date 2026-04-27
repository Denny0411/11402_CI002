#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    int S = 0;

    while (cin >> N >> S)
    {
        // size = N, initial value = 0
        vector<int> seq(N, 0);

        for (int i = 0; i < N; i++)
            cin >> seq.at(i);

        int termNum = 0;

        for (int i = 1; i <= N; i++) // 項數
        {
            for (int j = 0; j <= N - i; j++) // 起始 index
            {
                int sum = 0;
                for (int k = j; k < j + i; k++) // k 從 j 開始跑 i 個項
                {
                    sum += seq.at(k);
                    cout << "sum: " << sum << endl;
                }
                if (sum >= S)
                {
                    termNum = i;
                    break;
                }
                cout << endl;
            }
        }

        cout << termNum << endl;
    }
}