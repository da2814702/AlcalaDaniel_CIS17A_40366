#include "header.h"

void players::Win()
{
    cout << endl << giveName << " has connected 4! Game Over!" << endl;
    
    ofstream FinalBoard;
    FinalBoard.open("game.dat");
    int rows = 6;
    int columns = 7;
    if (!FinalBoard)
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        FinalBoard << "Player " << giveName << ", with token " << giveToken <<  ", has won with this board!" << endl;
        for (int r = 1; r <= rows; r++)
        {
            FinalBoard << "|";
            for (int c = 1; c <= columns; c++)
            {
                if (board[r][c] != 'X' && board[r][c] != 'O')
                {
                    board[r][c] = '*';
                }
                FinalBoard.write((char*)&board[r][c], sizeof(char));
            }
            FinalBoard << "|" << endl;
        }
    }
    FinalBoard.close();
    cout << "The final board state and who was won will be output to the game.dat file!" << endl;
}