#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    int counter = 0;
    while (t--)
    {
        counter++;
        int n = 0;
        cin >> n;
        vector<char> field(n);
        for (int i = 0; i < n; i++)
            cin >> field.at(i);

        int crow = 0;
        for (int i = 0; i < n; i += 3)
        {
            int j = 0;
            if (i + 2 > n - 1)
                j = n - 1;
            else
                j = i + 2;

            for (int k = i; k <= j; k++)
            {
                if (field.at(k) == '.')
                {
                    crow++;
                    break;
                }
            }
        }
        cout << "Case " << counter << ": " << crow << endl;
    }
}

/*
如果接下來三個有任何一個 '.'
    crow++

12
....#....#..
Case 6: 4
10
..#..##...
Case 7: 4 // 3
13
..#..##....#.
Case 8: 5 // 4
4
####
Case 9: 0
3
.#.
Case 10: 1
*/