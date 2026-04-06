# CI002 A3

此 repo 用於紀錄 1142 CI002 程式設計實習 的解題紀錄與筆記。

姓名：花偉喆  
學號：S1131557  
系級：資訊工程學系 2B

我的 Github Pages：https://denny0411.github.io

---

## 📖 目錄 (Table of Contents)

### 📌 課前練習 (Before-Class Exercises)

| 週次 | 題目 | 使用的 Library / 解題技巧與筆記 |
| :--- | :--- | :--- |
| **Week 3** | [LeetCode 231 - Power of Two](./Before-Class_Exercises/Week3_01_LeetCode231/) | **解題技巧**：使用迴圈搭配取餘數 (`% 2`) 與除法，判斷數字是否為 2 的次方。 |
| **Week 4** | [LeetCode 169 - Majority Element](./Before-Class_Exercises/Week4_01_LeetCode169/) | **Library**：`<unordered_map>`<br>**解題技巧**：使用 Hash Map (雜湊表) 紀錄陣列中每個數字出現的次數，找出過半的元素。 |
| **Week 4** | [LeetCode 48 - Rotate Image](./Before-Class_Exercises/Week4_02_LeetCode48/) | **Library**：`<algorithm>`<br>**解題技巧**：先使用 `std::reverse` 將矩陣上下翻轉，再利用迴圈與 `std::swap` 沿左上至右下對角線進行元素交換。 |
| **Week 5** | [LeetCode 88 - Merge Sorted Array](./Before-Class_Exercises/Week5_01_LeetCode88/) | **解題技巧**：使用雙指標 (Two Pointers)，從兩個陣列的尾端開始比較大小並從後往前填入，避免覆蓋掉尚未處理的資料。 |

### 💻 上機考 (On-Site Examinations)

| 週次 | 題目 | 使用的 Library / 解題技巧與筆記 |
| :--- | :--- | :--- |
| **Week 1** | [UVa 100 - The 3n + 1 problem](./On-Site_Examinations/Week1_01_UVa100/) | **解題技巧**：處理範圍時需注意 $i > j$ 的情況並使用 `swap` 修正；考量整數溢位問題，變數需宣告為 `unsigned int` 或 `long long`。 |
| **Week 1** | [UVa 10035 - Primary Arithmetic](./On-Site_Examinations/Week1_02_UVa10035/) | **解題技巧**：利用陣列儲存各個位數，並模擬直式加法的進位操作 (Carry operation) 來計算進位總數。 |
| **Week 2** | [UVa 272 - TEX Quotes](./On-Site_Examinations/Week2_01_UVa272/) | **Library**：`<string>`<br>**解題技巧**：使用 `getline` 讀取整行字串，並利用一個狀態變數 (parity) 輪流替換左右雙引號 (` `` ` 與 ` '' `)。 |
| **Week 2** | [UVa 490 - Rotating Sentences](./On-Site_Examinations/Week2_02_UVa490/) | **Library**：`<string>`<br>**解題技巧**：將輸入存入字串陣列，找出最大長度後，利用 `string::resize(max, ' ')` 將所有字串補齊長度並填入空白，最後由下往上、由左至右輸出。 |
| **Week 3** | [UVa 10783 - Odd Sum](./On-Site_Examinations/Week3_01_UVa10783/) | **解題技巧**：迴圈遍歷範圍內的數字，利用 `% 2 == 1` 判斷奇數並將其加總。 |
| **Week 3** | [UVa 10170 - The Hotel with Infinite Rooms](./On-Site_Examinations/Week3_02_UVa10170/) | **解題技巧**：注意資料型態溢位 (Overflow)，由於測資極大，需將變數宣告為 `unsigned long long int` (或 `ULL`)，以避免發生 TLE 或是無窮迴圈。 |
| **Week 4** | [UVa 11150 - Cola](./On-Site_Examinations/Week4_01_UVa11150/) | **解題技巧**：利用迴圈模擬空瓶兌換可樂的機制（並考量向老闆借空瓶的邊界條件），或直接套用數學規律推導 `N + N / 2` 快速求解。 |
| **Week 4** | [UVa 12503 - Robot Instructions](./On-Site_Examinations/Week4_02_UVa12503/) | **Library**：`<vector>`, `<string>`<br>**解題技巧**：改用 `cin >>` 逐字讀取以避免 `getline` 讀到隱藏換行字元 (`\r`) 的地雷；使用 `std::vector` 紀錄歷史指令來計算相對位置。 |
| **Week 5** | [UVa 299 - Train Swapping](./On-Site_Examinations/Week5_01_UVa299/) | **Library**：`<vector>`, `<algorithm>`<br>**解題技巧**：捨棄手動 `new/delete` 動態陣列，改用 `std::vector` 安全管理記憶體；實作氣泡排序 (Bubble Sort) 模擬相鄰車廂交換並計算總次數。 |
| **Week 5** | [UVa 10008 - What's Cryptanalysis?](./On-Site_Examinations/Week5_02_UVa10008/) | **Library**：`<algorithm>`, `<vector>`, `<utility>`, `<cctype>`<br>**解題技巧**：使用 `std::vector<pair<char, int>>` 紀錄字母與次數，並**撰寫自訂排序規則 (`compareRule`)** 結合 `std::sort`：次數不同時由大到小排，次數相同時依 ASCII 字母順序排。 |
| **Week 6** | [UVa 10931 - Parity](./On-Site_Examinations/Week6_01_UVa10931/) | **Library**：`<vector>`<br>**解題技巧**：十進位轉二進位，利用除以 2 與取餘數計算位元數與 1 的總數（未來可進階學習位元運算子 `&` 與 `>>` 來優化）。 |
| **Week 6** | [UVa 10062 - Tell me the frequencies!](./On-Site_Examinations/Week6_02_UVa10062/) | **Library**：`<algorithm>`, `<vector>`, `<utility>`<br>**解題技巧**：用 `std::pair` 統計 ASCII 出現次數，結合 `std::sort` 自訂規則（次數小排前面，次數相同 ASCII 大排前面）；**特別注意處理格式錯誤 (Presentation Error)**，確保最後一組測資不輸出多餘的空白行。 |