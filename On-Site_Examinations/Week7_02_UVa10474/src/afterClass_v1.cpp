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
                result.push_back(to_string(queries.at(i)) + " found at " + to_string(foundAt));
            }
            else // isFound == false
            {
                result.push_back(to_string(queries.at(i)) + " not found");
            }
        }

        // output
        cout << "CASE# " << caseNum << ":" << endl;
        for (int i = 0; i < queries.size(); i++)
        {
            cout << result.at(i) << endl;
        }

        cin >> N >> Q;
    }
}

/*
none of the input numbers are greater than 10000 
and none of them are negative.

if (input > 10000 && input < 0)
    end the program

直接 push string 結果 就好，不用搞一堆 variable
if 有找到
    x found at y
else
    x not found

Raju would place the marbles one after another in ascending order.

query
    found
    not found
*/