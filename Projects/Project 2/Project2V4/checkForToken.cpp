#include "header.h"

void checkForToken (char board[][10], info currentPlayer, int dropLocation)
{
    int length; 
    int round;
    length = 6;
    round = 0;
    
    do
    {
        if (board[length][dropLocation] != 'X' && board[length][dropLocation] != 'O')
        {
            board[length][dropLocation] = currentPlayer.giveToken();
            round = 1;
        }
        else
        {
            --length;
        }
    }while(round != 1);
}