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
*(commit 2a06d15cd4778c58b24a75a18988bd6f8ec9cb97)*

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


83 66 -88 99 -62 -50 8 -18 -12 17 13 -99 -7 -10 74 -1 -79 86 72 -2 47 15 94 69 75 -65 42 40 -3 49 -52 10 97 -28 12 5 73 -87 27 -89 51 -22 -41 67 3 37 -91 78 -82 -14 -76 -49 33 21 34 -98 38 50 89 98 -63 -38 -71 -56 52 -4 14 -93 22 31 -68 -95 -58 82 -29 11 43 -48 -77 -20 -34 -54 -37 -86 24 88 0 -26 54 7 95 -96 58 -75 35 84 -21 -36 -51 92

avec actuel : +700
avec nouveau : 635
