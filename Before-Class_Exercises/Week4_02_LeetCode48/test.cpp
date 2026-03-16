#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3}, 
        {4, 5, 6}, 
        {7, 8, 9}
    };

    // reverse(matrix.at(0).begin(), matrix.at(0).end());
    reverse(matrix.begin(), matrix.end());

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[row].size(); col++)
        {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    return 0;
}