# Link

https://leetcode.com/problems/majority-element/description/

# Note

* 我該怎麼找在 vector 中出現最多次的元素？
  要紀錄每個出現的元素，還有紀錄每個元素出現的次數，最後找出最大的次數以及該元素，是這樣嗎？

> 按照你的想法，我們確實可以把每個元素和它出現的次數記錄下來。在 C++ 裡面，最適合用來做這件事的工具叫做雜湊表（Hash Map），對應的型別是 `std::unordered_map`。

# Version 1

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // key: 陣列裡的數字
        // value: 該數字出現的次數
        unordered_map<int, int> counts;

        // 取得陣列長度，並算出過半的門檻值
        int target = nums.size() / 2;

        for (int num : nums)
        {
            // 將 num 出現的次數 ++
            // 若是還沒有 num，則新增 num
            counts[num]++;

            // 檢查 num 的次數
            if (counts[num] > target)
            {
                return num;
            }
        }

        return 0;
    }
};
```

# Time Complexity

$ O(n) $