#include "header.h"

void players::OutputBoard()
{
    int rows = 6;
    int columns = 7;
    
    for (int r = 1; r <= rows; r++)
    {
        cout << "|";
        for (int c = 1; c <= columns; c++)
        {
            if (board[r][c] != 'X' && board[r][c] != 'O')
            {
                board[r][c] = '*';
            }
            cout << board[r][c];
        }   
        cout << "|" << endl;
    }
}