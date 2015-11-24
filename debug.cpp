/*
Matt Olson
Test code to try out reading, writing, and solving puzzle ... unittesting would
be better
*/

#include <iostream>
#include <cstdlib>
#include "solver.hpp"
#include "altproj.hpp"
using namespace std;
using namespace arma;


int SIZE = 9;
int main(int argc, char **argv){
    // generate random puzzle
    Board gen_board = generatePuzzle(SIZE, 10);
    
    // write unsolved puzle
    gen_board.writePuzzle("unsolved.csv");
    
    // solve puzzle
    bool solved = gen_board.solvePuzzle();
    if( !solved ){
        perror("Failed to solve puzzle!\n");
        exit(0);
    }
    
    // print solved puzzle
    gen_board.writePuzzle("solved.csv");
    
    // read previous unsolved puzzle
    Board old_puzzle = readPuzzle("unsolved.csv", SIZE);
    
    // solve using DR
    Board solved_puzzle = DR(old_puzzle);
    
    // check to make sure solution is valid
    solved = solved_puzzle.checkPuzzle();
    if( !solved ){
        perror("Failed to solve puzzle!\n");
        exit(0);
    }
    
    
    // print solved puzzle
    solved_puzzle.writePuzzle("solvedDR.csv");

    return 0;
}
