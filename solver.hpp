/*
Matt Olson
Implement Board class to hold state of sudoku game.  Game is assumed to have a 
dimensions that are perfect squares, and "unfilled" entries are represented by
a 0.
*/

#pragma once
#include <cassert>
#include <cstdlib>
#include <string>

class Board{
    int N;
    int **grid;

public:

    // Initialize an empty board
    Board(int _N) : N(_N){

        //matrix to keep track of values
        grid = new int*[N];
        for(int i = 0; i < N; i++){
            grid[i] = new int[N];
        }
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                grid[i][j] = 0;

    }
    
    //destructor for board
    ~Board(){
        for(int i = 0; i < N; i++){
            delete [] grid[i];
        }
        delete [] grid;

    }

    // Return the size of the board
    int getSize(){
        return N;
    }

    //Operator overload to assign value to cell
    int& operator() (int x, int y){
        assert(x < N && y < N);
        return grid[x][y];
    }
    
    bool checkPuzzle(); // Check if puzzle is complete
    bool solvePuzzle(); // Solve puzzle in place using backtracking
    void writePuzzle(std::string fname); // write puzzle to csv file

};


bool feasible(Board &b, int row, int col, int val);
bool solve(Board &b, int row, int col);
Board readPuzzle(std::string fname, int n);
Board generatePuzzle(int n, int nobs);
int* genPerm(int N);



