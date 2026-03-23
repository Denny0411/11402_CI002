#include <iostream>

using namespace std;

int main()
{
    int N = 0;

    while (cin >> N)
    {
        int sum = N; // 拿到 N 瓶後喝完 N 瓶
        int empty = N; // 喝完 N 瓶後有 N 個空瓶

        while (empty >= 3) // 空瓶有 3 個以上就可以繼續換
        {
            sum += empty / 3;

            // 剛才換的 cola 變成空瓶，加上沒有換出去的空瓶
            empty = empty / 3 + empty % 3;
        }

        // 如果最後空瓶剩下 2 瓶，
        // 可以跟老闆借 1 瓶空瓶，
        // 3 瓶空瓶正好可以換 1 瓶 cola，
        // 把跟老闆借的 1 瓶空瓶還回去。
        if (empty == 2)
        {
            sum++;
        }

        cout << sum << endl;
    }
}