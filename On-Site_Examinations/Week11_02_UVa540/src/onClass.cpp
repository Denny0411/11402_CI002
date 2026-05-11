#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int t = 0;
	while (cin >> t)
	{
		if (t == 0)
			return 0;

		vector<int>* input = new vector<int>[t];

		for (int i = 0; i < t; i++)
		{
			int num = 0;
			cin >> num;
			for (int j = 0; j < num; j++)
			{
				int element = 0;
				cin >> element;
				input[i].push_back(element);
			}
		}

		string operation;
		cin >> operation;
		while (operation != "STOP")
		{
			if (operation == "ENQUEUE")
			{
				int element;
				cin >> element;
				for (int i = 0; i < t; i++)
				{
					for (int j = 0; j < input[i].size(); j++)
					{
						if (input[i].at(j) == element)
					}
				}
			}
			else if (operation == "DEQUEUE")
			{

			}
		}
	}
}


/*
重複的元素不用放進 queue


queue 1: team
queue 2: team member

if some of its teammates (elements of the same team) are already in the queue
If yes, it enters the queue right behind them
If not, it enters the queue at the tail and becomes the new last element
for each ‘DEQUEUE’ command, print the element which is dequeued on a single line

2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP

Scenario #1
101
102
103
201
202
203

2
5 259001 259002 259003 259004 259005
6 260001 260002 260003 260004 260005 260006
ENQUEUE 259001
ENQUEUE 260001
ENQUEUE 259002
ENQUEUE 259003
ENQUEUE 259004
ENQUEUE 259005
DEQUEUE
DEQUEUE
ENQUEUE 260002
ENQUEUE 260003
DEQUEUE
DEQUEUE
DEQUEUE
DEQUEUE
STOP

Scenario #2
259001
259002
259003
259004
259005
260001
*/