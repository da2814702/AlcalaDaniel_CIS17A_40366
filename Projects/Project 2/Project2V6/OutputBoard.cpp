//This function outputs the entire board, with the sides. Empty spaces
//are seen as *, while the tokens are X and O for each player.
#include "header.h"

void OutputBoard (char board[][10])
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