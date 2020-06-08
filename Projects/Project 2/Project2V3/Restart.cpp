#include "header.h"

int players::Restart() const
{
    int num;
    
    cout << "Would you like to restart the game? Yes=1 No=2: ";
    cin >> num;
    if (num == 1)
    {
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