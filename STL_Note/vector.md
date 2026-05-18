# STL vector

```cpp
// size is 5, initialize with 0
vector<int> tree(5, 0);
// 0 0 0 0 0

// need to include <algorithm>
fill(tree.begin(), tree.end(), 1);
// 1 1 1 1 1
```