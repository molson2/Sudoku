# Sudoku Solver #


### Background ##

Code to solve a "generalized" sudoku puzzle with square dimensions.  The solver Utilizes Douglas-Rachford splitting as a solution heuristic (standard backtracking also implemented).  This allows us to tackel larger problems: backtracking has exponential complexity in the problem dimension, so solving "large" problems with standard techniques is infeasible.  We've tested our code for a 100x100 sudoku game with good results (solution within 15 minutes, while backtracking failed to solve even 25x25 games over a few hour time period).

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

"Recent Results on Douglas–Rachford Methods for Combinatorial Optimization Problems"
