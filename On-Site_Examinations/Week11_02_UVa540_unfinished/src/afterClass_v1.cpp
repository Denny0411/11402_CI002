#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 宣告一個夠大的陣列來記錄每個人的團隊編號
const int MAX_ELEMENTS = 1000000;
int team_id[MAX_ELEMENTS];

int main() {
    // 為了讓 C++ 輸入輸出更快，可以加上這兩行
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // 團隊數量
    int scenario = 1;

    // 不斷讀取有幾個團隊，直到讀到 0 為止
    while (cin >> t && t != 0) {
        // cout 後 secnario 再加 1
        cout << "Scenario #" << scenario++ << "\n";

        // 【重點】：每次新的測試案例，記得要有全新的主佇列和團隊佇列！
        queue<int> main_q;
        queue<int> team_q[1005];

        // 1. 讀取每個團隊的成員，並登記到 team_id 陣列中
        // (這裡交給你用 for 迴圈讀取輸入)
        for (int i = 0; i < t; i++)
        {
            // number of elements belonging to the team
            int elementNum = 0;
            cin >> elementNum;
            for (int j = 0; j < elementNum; j++)
            {
                int person = 0; // 成員編號
                team_id[person] = i;
            }
        }

        string command;
        // 2. 讀取指令，直到遇到 STOP
        while (cin >> command && command != "STOP") {
            if (command == "ENQUEUE") {
                int x;
                cin >> x;
                // 實作上面的 ENQUEUE 邏輯
                
            } else if (command == "DEQUEUE") {
                // 實作上面的 DEQUEUE 邏輯
                
            }
        }
        cout << "\n"; // 每個測試案例後印出空白行
    }
    return 0;
}