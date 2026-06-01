#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // two strings of lowercase letters
    string a, b;

    while (getline(cin, a) && getline(cin, b))
    {
        map<char, int> mapA, mapB;

        // 統計字母頻率
        for (char c : a)
        {
            // 增加 mapA key 為 c 的值
            // 若尚未存在，則建立 key 為 c
            mapA[c]++;
        }
        for(char c : b)
        {
            mapB[c]++;
        }

        // 尋找交集與最小次數

        // pairA 是 key-value pair
        for (auto pairA : mapA)
        {
            char c = pairA.first;

            // count(key): 回傳該 key 是否存在
            // 回傳 0 不存在 或 1 存在
            if (mapB.count(c))
            {
                // map.at(key): 回傳該 key 對應的 value
                int minCount = min(pairA.second, mapB.at(c));
                for (int i = 0; i < minCount; i++)
                    cout << c;
            }
        }
        cout << endl;
    }
}