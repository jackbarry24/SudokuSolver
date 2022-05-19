#include "../include/sudoku.h"

int main( const int argc, const char* argv [] ){
    
    VECTOR< VECTOR<int> > sudoku(ROWS, VECTOR<int>(COLS));

    if(argc != 3){
        COUT << "Invalid command line arguments" << ENDL;
        return 1;
    }
    
    IFSTREAM sudoku_infile(argv[1]);
    
    OFSTREAM sudoku_outfile(argv[2]);
    
    populate_puzzle(sudoku_infile, sudoku);
    
    print_greeting();

    if(recursive_solver(sudoku, 0, 0)){
        COUT << "Solution:" << ENDL;
    }else{
        COUT << "No Solution: " << ENDL;
    }
   
    print_puzzle(sudoku);
    print_puzzle_to_file(sudoku_outfile, sudoku);
    
}
