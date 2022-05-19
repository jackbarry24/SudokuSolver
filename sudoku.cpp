#include "../include/sudoku.h"

void print_greeting( void ){
    COUT << "Welcome to Sudoku Solver!" << ENDL;
}

void populate_puzzle( IFSTREAM& sudoku_infile, VECTOR< VECTOR<int> >& sudoku ){

    int temp;
    int row = 0;
    int col = 0;

    while(sudoku_infile >> temp){
        
        if(temp != ' ' && temp != '\n'){

            sudoku[row][col] = temp;
            //update_puzzle(sudoku, temp, row, col);
            col++;

            if(col == 9){
                row++;
                col = 0;
            }
        }  
    }
   
    sudoku_infile.close();
}

void update_puzzle( VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row,  long unsigned int col ){

    sudoku[row][col] = value;

}

bool check_guess( const VECTOR< VECTOR<int> >& sudoku, int value, long unsigned int row, long unsigned int col ){

    int rows = ROWS;
    int cols = COLS;
    int i, j;

    if(sudoku[row][col] != 0) return false;

    for(i = 0; i < rows; i++){
        if(sudoku[row][i] == value) return false;
    }

    for(i = 0; i < cols; i++){
        if(sudoku[i][col] == value) return false;
    }
    
    long unsigned int boxRow = row - row%3;
    long unsigned int boxCol = col - col%3;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(sudoku[boxRow + i][boxCol + j] == value) return false;
        }
    }

    return true;
}

bool check_puzzle( const VECTOR< VECTOR<int> >& sudoku){
    long unsigned int rows = ROWS;
    long unsigned int cols = COLS;
    long unsigned int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            if(sudoku[i][j] == 0) return false;
        }
    }

    return true;
}

bool recursive_solver( VECTOR< VECTOR<int> >& sudoku, long unsigned int row, long unsigned int col ){

   

    while(true){
        if(sudoku[row][col] == 0) break;

        col++;
        if(col == 9){
            col = 0;
            row++;
            if(row == 9) break;
        }
    }

    if(row == 9) return true;

    int num;
    for(num = 1; num < 10; num++){
        bool complete = check_guess(sudoku, num, row, col);
        update_puzzle(sudoku, num, row, col);
        if(complete && recursive_solver(sudoku, row, col)) return true;
        update_puzzle(sudoku, 0, row, col);
    }
    return false;
}

void print_puzzle( const VECTOR< VECTOR<int> >& sudoku ){
    int rows = ROWS;
    int cols = COLS;
    int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            COUT << sudoku[i][j] << " ";
        }
        COUT << ENDL;
    }
}

void print_puzzle_to_file( OFSTREAM& sudoku_outfile, const VECTOR< VECTOR<int> >& sudoku ){

    int rows = ROWS;
    int cols = COLS;
    int i, j;

    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            sudoku_outfile << sudoku[i][j] << " ";
        }
        sudoku_outfile << ENDL;
    }

    sudoku_outfile.close();
}
