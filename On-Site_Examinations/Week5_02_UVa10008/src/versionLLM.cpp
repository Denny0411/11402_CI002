#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <cctype> // 引入 isalpha 和 toupper 的標準函式庫

using namespace std;

// 自訂排序規則
bool compareRule(const pair<char, int>& a, const pair<char, int>& b) {
    if (a.second != b.second) {
        return a.second > b.second; // 次數多的排前面
    } else {
        return a.first < b.first;   // 次數相同，字母順序小的排前面
    }
}

int main() {
    int n = 0;
    // 讀取行數 n [cite: 7]
    if (!(cin >> n)) return 0; 
    cin.ignore(); // 清除換行字元

    vector<int> count(26, 0); // 預設 26 個字母的出現次數皆為 0

    // 讀取 n 行並即時處理，不需要開大陣列儲存所有字串
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        
        // 使用範圍 for 迴圈走訪字串中的每個字元
        for (char c : line) {
            if (isalpha(c)) { // 判斷是否為英文字母 
                // 轉為大寫並計算次數 
                count[toupper(c) - 'A']++;
            }
        }
    }

    vector< pair<char, int> > letterData;

    // 將有出現的字母存入 vector
    for (int i = 0; i < 26; i++) {
        if (count.at(i) > 0) {
            letterData.push_back(make_pair('A' + i, count.at(i)));
        }
    }

    // 進行排序
    sort(letterData.begin(), letterData.end(), compareRule);

    // 輸出結果
    for (int i = 0; i < letterData.size(); i++) {
        cout << letterData.at(i).first << " " << letterData.at(i).second << "\n";
    }

    return 0;
}