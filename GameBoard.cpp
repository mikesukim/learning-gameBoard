#include "GameBoard.h"
//-------------------------------------------------------------------------------------//
    GameBoard :: GameBoard()
    {      
        Rows = 0;
        Cols = 0;
        Empty = 0;
        Board;       
    }
//-------------------------------------------------------------------------------------//
    GameBoard :: ~GameBoard()
    {     
    }
//-------------------------------------------------------------------------------------//
    int GameBoard ::get_rows()
    {
        return Rows;
    }
//-------------------------------------------------------------------------------------//
    int GameBoard :: get_cols()
    {
        return Cols;
    }
//-------------------------------------------------------------------------------------//
    char GameBoard ::get_empty()
    {
        return Empty;
    }
//-------------------------------------------------------------------------------------//
    char GameBoard ::get_board(int row, int col)
    {   
        return Board[row][col];
    }
//-------------------------------------------------------------------------------------// 
    void GameBoard ::set_board(int row, int col)
    {
        Board[row][col] = Value;
    }
//-------------------------------------------------------------------------------------//
    void GameBoard ::print_board()
    {
        cout <<"Number of Rows : "<< Rows << endl;
        cout <<"Number of Cols : "<< Cols << endl;
        cout << "Empty : "<< Empty << endl;
        for(int i = 0; i < Rows; i++)
        { 
            for(int k = 0; k < Cols; k++)
            {   
                cout << get_board(i,k) << " ";          
            }
        cout << endl;
        }
    }
//-------------------------------------------------------------------------------------//
    void GameBoard ::read_board(string filename)
    {
        fstream din;
        din.open(filename.c_str());
        
        //IF FAILED TO READ
        if(din.fail())
        {cout << " OPENING FILE NAME " << filename << " FAILED. " << endl; return;}
        else
        {cout << " OPENING FILE NAME " << filename << " SUCCEEDED. " << endl;}
        
       din >> Rows >> Cols >> Empty;    
       for(int i = 0; i < Rows; i++)
        {
            for(int k = 0; k < Cols; k++)
            {       
                din >> Value;
                set_board(i,k);        
            }
        }
        din.close();
    
    }
//-------------------------------------------------------------------------------------//
    void GameBoard ::write_board(string filename)
    {
        fstream dout;
        dout.open(filename.c_str());
        if(dout.fail())
        {cout << " OPENING OUT FILE NAME " << filename << " FAILED. " << endl;return;}
        else
        {cout << " OPENING OUT FILE NAME " << filename << " SUCCEEDED. " << endl;}
        
        dout <<"Number of Rows : "<< Rows << endl;
        dout <<"Number of Cols : "<< Cols << endl;
        dout << "Empty : "<< Empty << endl;
        for(int i = 0; i < Rows; i++)
        { 
            for(int k = 0; k < Cols; k++)
            {   
                dout << get_board(i,k) << " ";          
            }
            dout << endl;
        }   
        cout << " WRITING TO  FILE NAME " << filename << " SUCCEEDED. " << endl;
    }
//-------------------------------------------------------------------------------------//
    void GameBoard ::initialize_board(int rows, int cols, char empty)
    {   
        //Error Checking
        if((rows > MAX_ROWS)||(cols > MAX_COLS))
        {  
           cout << "Number of Rows and Cols should not be over MAX " << endl; 
           cout << "******Initializing FALIED******" << endl;
           return;
        }
        
        Rows = rows;
        Cols = cols;
        Empty = empty;
        
        Value = empty;
        
        for(int i = 0; i < Rows; i++)
        { 
            for(int k = 0; k < Cols; k++)
            {   set_board(i,k);          
            }
        }        
    }
//-------------------------------------------------------------------------------------//
    void GameBoard ::flood_fill(int row, int col, char number, int irow, int icol)
    {
        Value = number;
        double radius = 7;
        
       // if statement for checking circle boundary
       if(pow((row - irow),2) + pow((col - icol),2) < pow(radius,2))
       {
           //Terminating condition
            if( get_board(row,col) != Empty)
            {
                return;
            }
            else
            {
                set_board(row,col);                 
                flood_fill(row,col+1,number,irow,icol); //Right
                flood_fill(row,col-1,number,irow,icol); //Left
                flood_fill(row+1,col,number,irow,icol); //Top 
                flood_fill(row-1,col,number,irow,icol); //Bottom 
            }       
       }  
    }
//-------------------------------------------------------------------------------------//
