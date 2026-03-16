#include <iostream>

using namespace std;

int main()
{
    int inputA = 0, inputB = 0;

    while (cin >> inputA >> inputB)
    {
        if (inputA == 0 && inputB == 0)
            break;

        // use 1 ~ 10
        int arrA[11] = {};
        int arrB[11] = {};

        // use 1 ~ 11
        int carry[12] = {};
        int sum[12] = {};
        int indexA = 0, indexB = 0;

        // 將輸入轉換成陣列形式，從 index 1 開始儲存
        while (inputA >= 1)
        {
            indexA++;
            arrA[indexA] = inputA % 10;
            inputA /= 10;
        }
        while (inputB >= 1)
        {
            indexB++;
            arrB[indexB] = inputB % 10;
            inputB /= 10;
        }

        // 進行加法
        for (int i = 1; i <= 10; i++)
        {
            sum[i] = arrA[i] + arrB[i] + carry[i];
            if (sum[i] >= 10)
            {
                carry[i + 1]++;
                sum[i] -= 10;
            }
        }

        // 計算進位總數
        int sumCarry = 0;
        for (int i = 0; i < 12; i++)
            sumCarry += carry[i];

        if (sumCarry == 0)
            cout << "No carry operation." << endl;
        else if (sumCarry == 1)
            cout << "1 carry operation." << endl;
        else
            cout << sumCarry << " carry operations." << endl;
    }
}