#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard
{
public:
    //Con,Destructor
    GameBoard();
    ~GameBoard();
    //get functions
    int get_rows();
    int get_cols();
    char get_empty();
    char get_board(int row, int col);
    void set_board(int row, int col);
    
    void print_board();
    void read_board(string filename);
    void write_board(string filename);
    void initialize_board(int rows, int cols, char empty);
    void flood_fill(int row, int col,char number,int irow, int rcol);
      
private:
    static const int MAX_ROWS = 100;
    static const int MAX_COLS = 100;
    int Rows;
    int Cols;
    char Empty;
    char Value;
    char Board[MAX_ROWS][MAX_COLS];

};
#endif 

