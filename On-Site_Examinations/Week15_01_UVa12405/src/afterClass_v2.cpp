#include <iostream>
// #include <vector>
#include <string>

using namespace std;

int main()
{
    int T; // the number of test cases
    cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int N;
        cin >> N;
        // vector<char> field(N);
        string field;

        // for (int i = 0; i < N; i++)
        //     cin >> field.at(i);
        cin >> field;

        int i = 0; // index
        int scarecrow = 0;
        while (i < N)
        {
            if (field.at(i) == '#')
            {
                i++;
            }
            else // field.at(i) == '.'
            {
                scarecrow++;
                // if i == 1
                // scarecrow put at 2
                // next check 1 + 3 == 4
                i += 3;
            }
        }

        cout << "Case " << caseNum << ": " << scarecrow << endl;
    }
}