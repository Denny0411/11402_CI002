# [Platform] [Problem ID] - [Problem Title]

Use this template to review your coding performance for each problem. Write clearly and use your own words.

## 1. Problem Information

- **Platform:** LeetCode
- **Problem ID:** 88
- **Problem Title:** Merge Sorted Array 
- **Problem Link:** https://leetcode.com/problems/merge-sorted-array/description/

## 2. Problem Statement in My Own Words

Describe the problem in your own language. Do not copy the original statement.

- What is the input?
- What is the expected output?
- What are the main rules or constraints?
- What is the core task you must solve?

## 3. Thinking Logic and Solution Strategy

Explain how you thought about the problem and how you decided on your final approach.

### Initial Thoughts

- What difficulty did you notice at the beginning?  
    我不知道 merge sort 要怎麼實作。

### Final Strategy

- What method did you finally use?
- Why does this method work?
- What edge cases did you consider?

## 4. Pseudocode

Write the main steps of your solution before showing the actual code.

```text
START
1. 
2. 
3. 
4. 
END
```

## 5. Fail Code vs Correct Code

Show the code that failed first, then show the corrected version.

### Correct Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = nums1.size() - 1;

        // compare nums1[p1] and nums2[p2]
        // the bigger one will be placed at num1[p]
        while (p1 >= 0 && p2 >= 0)
        {
            if (nums1.at(p1) >= nums2.at(p2))
            {
                nums1.at(p) = nums1.at(p1);
                p1--;
                p--;
            }
            else // (nums1.at(p1) < nums2.at(p2))
            {
                nums1.at(p) = nums2.at(p2);
                p2--;
                p--;
            }
        }

        while (p2 >= 0)
        {
            nums1.at(p) = nums2.at(p2);
            p2--;
            p--;
        }
    }
};
```

**Why it works:**

- 
- 



## 6. Difference and Reflection

### Key Differences

| Item | Fail Code | Correct Code |
|---|---|---|
| Logic |  |  |
| Edge Cases |  |  |
| Output Handling |  |  |
| Other |  |  |

### Reflection

- What mistake did you make?
- What did you learn from debugging this problem?
- If you solve a similar problem again, what will you do better?