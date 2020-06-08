#include "header.h"

void checkForToken (char board[][10], players currentPlayer, int dropLocation)
{
    int length; 
    int round;
    length = 6;
    round = 0;
    
    do
    {
        if (board[length][dropLocation] != 'X' && board[length][dropLocation] != 'O')
        {
            board[length][dropLocation] = currentPlayer.token;
            round = 1;
        }
        else
        {
            --length;
        }
    }while(round != 1);
}