#include "header.h"

int players::rowToDropIn() const
{
    int dropLocation;
    do
    {
        cout << giveToken << "'s Turn!" << endl;
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