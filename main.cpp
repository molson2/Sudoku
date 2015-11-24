/*
Matt Olson
Driver file to read in an arbitrary sized sudoku game and solve using
Douglas-Rachford splitting.  Incomplete game should be stored in a csv file
with unfilled entries represented by 0s (see example.csv).  User also needs to
specify the game dimension (9 for standard games).
*/

#include <iostream>
#include <string>
#include "solver.hpp"
#include "altproj.hpp"
using namespace std;

int main(int argc, char* argv[]){
    
    string infile; // path to an unsolved game (see README.md)
    string outfile; // path to write game solution
    int gameDimension; // number of rows

    // parse args
    if( argc < 4){
        cout << "Example Useage: ./main 9 example9.csv solved9.csv" << endl;
        exit(0);
    } else{
        gameDimension = atoi(argv[1]);
        infile = string(argv[2]);
        outfile = string(argv[3]);
        
        // must be a perfect square
        assert(gameDimension == sqrt(pow(gameDimension, 2)));
        
    }

    // read incomplete board
    Board unsolvedBoard = readPuzzle(infile, gameDimension);

    // solve puzzle (there exists an internal solve method, but this external
    // one is more interesting)
    Board solvedBoard = DR(unsolvedBoard);
    
    // check puzzle and write
    if(!solvedBoard.checkPuzzle()){
        cout << "Original problem likely unsolvable.  Solution technique is ";
        cout << "experimental, so not gauranteed to solve!" << endl;
    } else{
        // write board to file
        cout << "Solved puzzle " << infile << " and wrote to ";
        cout << outfile << endl;
        solvedBoard.writePuzzle(outfile);
    }


    return 0;
}

