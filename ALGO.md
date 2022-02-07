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
*(commit 69b77f53344da05aa268db5ec234f3f0cb8da76c)*

We push in B until we have only three elements left in A. We sort A. As long as B is not empty, we look for the element of B that will require the least number of instructions to reach A (in the right place). We rotate A and B (r{a/b/r}, rr{a/b/r} according to the shortest) to place the element in question on top of B and to be able to push it.
At the end we rotate A (ra or rra according to the shortest) to put the smallest element on top.

```
Stack size 5 (goal : 12 OK):
	worst	: 12
	average	: 8
	best	: 0
Stack size 100 (goal : 700 KO):
	worst	: 706
	average	: 609
	best	: 503
Stack size 500 (goal : 5500 KO):
	worst	: 5943
	average	: 5488
	best	: 5207
```
