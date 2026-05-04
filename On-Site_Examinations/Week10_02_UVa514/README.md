# UVa 514 – Rails

## Link

https://onlinejudge.org/external/5/514.pdf

## onClass

### Thinking Logic and Solution Strategy

```
1 2 3 4 5

A -> B
1 2 3 4 5

A -> station(stack) -> B
5 4 3 2 1

5 // 5 trains
1 2 3 4 5
5 4 1 2 3
0 // end of test case

6 // 6 trains
6 5 4 3 2 1
0 // end of test case

0 // terminate

if stack.top() == target ptr
	stack.pop()
if target ptr == input ptr
	target ptr++
	input ptr++

if target ptr != input ptr
	stack.push(input ptr)
```

這題對我來說是一個挑戰，我在上機考時連 input 都不太確定怎麼處理。