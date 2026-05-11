#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    // N 節車廂
    int N = 0;

    while (cin >> N && N != 0) // N 不是 0 就繼續執行
    {
        int first_train = 0;

        // 如果數列的第一個數字不是 0，代表這是需要處理的數列
        // 如果數列的第一個數字是 0，處理下一個 case -> 輸入下一個 case 的 N
        while (cin >> first_train && first_train != 0)
        {
            // 期望的目標排序
            // 有 N 節車廂
            vector<int> target(N);
            target.at(0) = first_train;

            // 讀取接下來 N - 1 個數字
            for (int i = 1; i < N; i++)
            {
                cin >> target.at(i);
            }

            stack<int> station;
            int target_index = 0;

            // 目前在 side A 上準備進站的車廂號碼，increasing order
            for (int sideA = 1; sideA <= N; sideA++)
            {
                station.push(sideA);
                while (station.empty() == false && station.top() == target.at(target_index))
                {
                    station.pop();
                    target_index++;
                }
            }

            // 檢查 station 是不是空的
            if (station.empty() == true)
                cout << "Yes" << endl;
            else // station.empty() == false
                cout << "No" << endl;
        }

        // 同一個 N 的測資結束後，要印出一行空行
        cout << endl;
    }
    return 0;
}