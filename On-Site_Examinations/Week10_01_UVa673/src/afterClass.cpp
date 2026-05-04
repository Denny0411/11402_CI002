#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    cin.ignore(); // 在 getline 前要用 ignore()

    while (n--)
    {
        string input;
        getline(cin, input);

        if (input.size() > 128)
        {
            cout << "No" << endl;
            continue;
        }
        else if (input.size() == 0)
        {
            cout << "Yes" << endl;
            continue;
        }

        stack<char> stk;
        // 走訪 input 每個字元
        for (int i = 0; i < input.size(); i++)
        {
            // case '(' and case '['
            if (input.at(i) == '(' || input.at(i) == '[')
            {
                stk.push(input.at(i));
            }
            else if (stk.empty() == true)
            {
                stk.push(input.at(i));
                break;
            }
            else if ((stk.top() == '(' && input.at(i) == ')') || (stk.top() == '[' && input.at(i) == ']'))
            {
                stk.pop();
            }
        }

        if (stk.empty() == true)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

/*
empty string -> correct
the maximum string length is 128
*/