//This function mainly outputs the board to a .dat file and who won that game
//board.
#include "header.h"

void Win1 (Player p1, Player p2, char board[][10])
{
    cout << endl << p1.giveName() << " has connected 4! Game Over!" << endl;
    
    ofstream FinalBoard;
    FinalBoard.open("game.dat", ios::out|ios::binary);
    int rows = 6;
    int columns = 7;
    if (!FinalBoard)
    {
        cout << "Error opening file!" << endl;
    }
    else
    {
        FinalBoard << "Player " << p1.giveName() << ", with token " << p1.giveToken() <<  ", has won with this board!" << endl;
        FinalBoard << "Final Score!" << endl;
        FinalBoard << "------------" << endl;
        FinalBoard << p1.giveName() << "'s Score: " << p1.giveWins() << endl;
        FinalBoard << p2.giveName() << "'s Score: " << p2.giveWins() << endl;
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
    cout << "The final board state, score, and who was won will be output to the game.dat file!" << endl;
}