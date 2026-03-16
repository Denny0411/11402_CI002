class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;
        else // n >= 1
        {
            while (n != 1)
            {
                if (n % 2 != 0)
                {
                    return false;
                }
                else // n % 2 == 0
                {
                    n /= 2;
                }
            }
            return true;
        }
    }
};