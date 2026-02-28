#include <iostream>
#include <algorithm>

using namespace std;

int getCycleLength(unsigned int n)
{
    int len = 1; // 包含原本的數字本身，所以從 1 開始

    // 使用 long long 防止計算 3n+1 時溢位，雖然題目說 32-bit 足夠，但在其他類似題目這是好習慣
    long long tempN = n; 

    while (tempN > 1)
    {
        if (tempN % 2 == 1) // 如果是奇數
        {
            tempN = 3 * tempN + 1;
        }
        else // 如果是偶數
        {
            tempN /= 2;
        }
        len++;
    }
    return len;
}

int main()
{
    int i, j;

	while (cin >> i >> j)
	{
		cout << i << " " << j << " ";
        
        int startNode = min(i, j);
        int endNode = max(i, j);

        int maxLen = 0;

		for (int k = startNode; k <= endNode; k++)
		{
			int currentLen = getCycleLength(k);
            maxLen = max(currentLen, maxLen);
		}

		cout << maxLen << endl;
	}
}