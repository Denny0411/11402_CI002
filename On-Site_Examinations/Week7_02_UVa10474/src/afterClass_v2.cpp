#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int N = 0; // the number of marbles, N lines
    int Q = 0; // the number of queries Mina would make
    int caseNum = 0;

    cin >> N >> Q;

    while (N != 0 || Q != 0)
    {
        vector<int> marbles;
        vector<int> queries;
        vector<string> result;
        int input;

        caseNum++;

        for (int i = 0; i < N; i++)
        {
            cin >> input;
            marbles.push_back(input);
        }

        sort(marbles.begin(), marbles.end());

        for (int i = 0; i < Q; i++)
        {
            cin >> input;
            queries.push_back(input);
        }

        // compare
        cout << "CASE# " << caseNum << ":" << endl;
        for (int i = 0; i < queries.size(); i++)
        {
            bool isFound = false;
            int foundAt = -1;
            for (int j = 0; j < marbles.size(); j++)
            {
                if (marbles.at(j) == queries.at(i))
                {
                    isFound = true;
                    foundAt = j + 1;
                    break;
                }
            }

            if (isFound == true)
            {
                cout << (to_string(queries.at(i)) + " found at " + to_string(foundAt)) << endl;
            }
            else // isFound == false
            {
                cout << (to_string(queries.at(i)) + " not found") << endl;
            }
        }

        cin >> N >> Q;
    }
}