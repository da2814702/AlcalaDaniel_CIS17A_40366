//This function asks the user if they would like to restart the game.
//If they do, then the board will reset back to the original game state.
//If not, the function will terminate the game.
#include "header.h"

int Restart (char board[][10])
{
    int num;
    
    cout << "Would you like to restart the game? Yes=1 No=2: ";
    cin >> num;
    if (num == 1)
    {
        delete []board;
        for(int r =1; r <= 6; r++)
        {
            for (int c = 1; c <= 7; c++)
            {
                board[r][c] = '*';
                
            }
        }
    }
    else
    {
        cout << "Goodbye!" << endl;
    }
    return num;
}