#include "header.h"

int rowToDropIn (char board[][10], info currentPlayer)
{
    int dropLocation;
    do
    {
        cout << currentPlayer.giveName() << "'s Turn!" << endl;
        cout << "Please enter a column to drop into (1-7): ";
        cin >> dropLocation;
        
        while (board[1][dropLocation] == 'X' || board[1][dropLocation] == 'O')
        {
            cout << "That column is full, please try again: ";
            cin >> dropLocation;
        }
        
    }while (dropLocation < 1 || dropLocation > 7);
    return dropLocation;
}