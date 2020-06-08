#include "header.h"

void players::checkForToken (int choice)
{
    int length; 
    int round;
    length = 6;
    round = 0;
    
    do
    {
        if (board[length][choice] != 'X' && board[length][choice] != 'O')
        {
            board[length][choice] = giveToken;
            round = 1;
        }
        else
        {
            --length;
        }
    }while(round != 1);
}