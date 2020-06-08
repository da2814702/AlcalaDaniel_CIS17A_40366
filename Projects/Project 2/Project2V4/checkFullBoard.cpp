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