#include "header.h"

int checkForWin (char board[][10], players currentPlayer)
{
    char token;
    int win;
    
    token = currentPlayer.token;
    win = 0;
    
    for(int r = 8; r >= 1; --r)
    {
        for(int c = 9; c >= 1; --c)
        {
            if(board[r][c] == token &&
               board[r-1][c-1] == token &&
               board[r-2][c-2] == token &&
               board[r-3][c-3] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r][c-1] == token &&
               board[r][c-2] == token &&
               board[r][c-3] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r-1][c] == token &&
               board[r-2][c] == token &&
               board[r-3][c] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r-1][c+1] == token &&
               board[r-2][c+2] == token &&
               board[r-3][c+3] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r][c+1] == token &&
               board[r][c+2] == token &&
               board[r][c+3] == token)
            {
                win = 1;
            }
        }
    }
    return win;
}