## First algo
*(commit 2d66d3d6bb4dd82c62eef5a393723a448c8efe13)*

We push in B until we have only three elements left in A. We sort A. We find the future position of the first element of B then we rotate A (ra or rra according to the shortest) then we push B. At the end we rotate A (ra or rra according to the shortest) to put the smallest element on top.

```
Stack size 5 (goal : 12 OK):
	worst	: 12
	average	: 8
	best	: 0
Stack size 100 (goal : 700 KO):
	worst	: 1686
	average	: 1457
	best	: 1210
Stack size 500 (goal : 5500 KO):
	worst	: 34467
	average	: 32307
	best	: 29337
```


## Second algo
*(commit xx)*

To explain

```
Stack size 5 (goal : 12 OK):
	worst	: 12
	average	: 8
	best	: 0
Stack size 100 (goal : 700 OK):
	worst	: 689
	average	: 607
	best	: 519
Stack size 500 (goal : 5500 KO):
	worst	: 5812
	average	: 5478
	best	: 5143
```
