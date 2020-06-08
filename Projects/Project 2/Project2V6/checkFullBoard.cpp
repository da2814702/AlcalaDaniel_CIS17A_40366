//This function checks to see if all rows are full or not.
#include "header.h"

int checkFullBoard (char board[][10])
{
    int max;
    max = 0;
    for (int r = 1; r <= 7; ++r)
    {
        if (board[1][r] != '*')
        {
            ++max;
        }
    }
    return max;
}