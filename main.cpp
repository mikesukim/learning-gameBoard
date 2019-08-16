
#include "GameBoard.h"

int main() 
{
    GameBoard gameboard;
    
    //READING FILE
    cout << "========Welcome to flood_fill simulation=========" << endl;
    gameboard.read_board("input.txt");
    gameboard.print_board();
    
    //FLOODDING OCCURING
    cout << "First flood occurred at (12,32)." << endl;
    gameboard.flood_fill(12,32,'1',12,32);
    cout << "Second flood occurred at (6,13)." << endl;
    gameboard.flood_fill(6,13,'2',6,13);
    cout << "Thrid flood occurred at (33,7)." << endl;
    gameboard.flood_fill(33,7,'3',33,7);
    cout << "Fourth flood occurred at (24,10)." << endl;
    gameboard.flood_fill(24,10,'4',24,10);
    cout << "Fifth flood occurred at (35,21)." << endl;
    gameboard.flood_fill(35,21,'5',35,21);
    gameboard.print_board();   
    
    //WRITING FILE
    gameboard.write_board("output.txt");
    
    //INITIALIZING PROCESS
    bool choice;
    int row,col;
    char symbol;
    cout << "How Many new Rows for initializing? (Between 0 , 100)" << endl;
    cin >> row;
    cout << "How Many new Cols for initializing? (Between 0 , 100)" << endl; 
    cin >> col;
    cout << "What symbol prefer for empty initializing?" << endl; 
    cin >> symbol;
    gameboard.initialize_board(row,col,symbol);  
    gameboard.print_board();
   
    
    cout << "FINISHING Flood_fill simulation....." << endl;
    cout << "THANK YOU !" << endl;
    gameboard.~GameBoard();
  
    return 0;
}

