# Sudoku Solver #


### Background ##

Code to solve a "generalized" sudoku puzzle with square dimensions.  The solver utilizes Douglas-Rachford splitting as a solution heuristic (a standard backtracking solver is also implemented).  This allows us to tackle larger problems: backtracking has exponential complexity in the problem dimension, so solving "large" problems with standard techniques is infeasible.  We've tested our code for a 100x100 sudoku puzzle with promising results (solve times around 15 minutes).

### Useage ###

* To build solver from source (requires `armadillo` C++ linear algebra library):
```
make sudoku
```

* To solve a puzzle stored in a csv file:
```
./sudoku 9 infile.csv outfile.csv
```
Note: input game is stored as a csv file with missing entries filled in with 0s, and the dimension of the underlying game must be supplied.  In this example, we solve a standard size game, but we can handle any game with square dimensions, i.e. 4, 9, 16, ...

### References ###

Recent Results on Douglas–Rachford Methods for Combinatorial Optimization Problems
