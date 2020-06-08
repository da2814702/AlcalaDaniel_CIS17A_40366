/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    May 29, 2020
 * Purpose: Connect 4 Game Project 2 V1
 *          Version 1 Info: This version is a base version of the original game
 *          from project 1. It has no changes to the code and it purely meant for
 *          testing the original version of the game.
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <string>     //Strings
#include <fstream>    //File Output/Input
using namespace std;  //Libraries compiled under std

struct players
{
    string name;
    char token;
};

int rowToDropIn (char board[][10], players currentPlayer);
void checkForToken (char board[][10], players currentPlayer, int dropLocation);
void OutputBoard (char board[][10]);
int checkForWin (char board[][10], players currentPlayer);
int checkFullBoard (char board[][10]);
void Win (players currentPlayer, char board [][10]);
int Restart (char board[][10]);


//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    //Variable Declarations
    players playerOne, playerTwo;
    char board[9][10];
    int choice,
        max,
        repeat,
        win;
    
    //Variable Initialization
    max = 0;
    repeat = 0;
    win = 0;
    
    //Output To Gather Information
    cout << "Connect 4 Game!" << endl;
    cout << "Enter player 1's name: ";
    getline(cin,playerOne.name);
    playerOne.token = 'X';
    
    cout << "Enter player 2's name: ";
    getline(cin,playerTwo.name);
    playerTwo.token = 'O';
    
    OutputBoard(board);
    do
    {
        choice = rowToDropIn(board, playerOne);
        checkForToken(board, playerOne, choice);
        
        //Display Outputs
        OutputBoard(board);
        win = checkForWin(board, playerOne);
        if (win == 1)
        {
            Win(playerOne, board);
            //Clean Up
            repeat = Restart(board);
            if (repeat == 2)
            {
                break;
            }
        }
        
        choice = rowToDropIn(board, playerTwo);
        checkForToken(board, playerTwo, choice);
        
        //Display Outputs
        OutputBoard(board);
        win = checkForWin(board, playerTwo);
        if (win == 1)
        {
            Win(playerTwo, board);
            //Clean Up
            repeat = Restart(board);
            if (repeat == 2)
            {
                break;
            }
        }
        
        max = checkFullBoard(board);
        if (max == 7)
        {
            cout << "The board has been completely filled up! The game is a draw!" << endl;
            repeat = Restart(board);
        }
    }while (repeat != 2);
    
    //Exit stage right!
    return 0;
}

int rowToDropIn (char board[][10], players currentPlayer)
{
    int dropLocation;
    do
    {
        cout << currentPlayer.name << "'s Turn!" << endl;
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

void checkForToken (char board[][10], players currentPlayer, int dropLocation)
{
    int length; 
    int round;
    length = 6;
    round = 0;
    
    do
    {
        if (board[length][dropLocation] != 'X' && board[length][dropLocation] != 'O')
        {
            board[length][dropLocation] = currentPlayer.token;
            round = 1;
        }
        else
        {
            --length;
        }
    }while(round != 1);
}

void OutputBoard (char board[][10])
{
    int rows = 6;
    int columns = 7;
    
    for (int r = 1; r <= rows; r++)
    {
        cout << "|";
        for (int c = 1; c <= columns; c++)
        {
            if (board[r][c] != 'X' && board[r][c] != 'O')
            {
                board[r][c] = '*';
            }
            cout << board[r][c];
        }   
        cout << "|" << endl;
    }
}

int checkForWin (char board[][10], players currentPlayer)
{
    char token;
    int win;
    
    token = currentPlayer.token;
    win = 0;
    
    for(int r = 8; r >= 1; --r)
    {
        for(int c = 9; c >= 1; --c)
        {
            if(board[r][c] == token &&
               board[r-1][c-1] == token &&
               board[r-2][c-2] == token &&
               board[r-3][c-3] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r][c-1] == token &&
               board[r][c-2] == token &&
               board[r][c-3] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r-1][c] == token &&
               board[r-2][c] == token &&
               board[r-3][c] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r-1][c+1] == token &&
               board[r-2][c+2] == token &&
               board[r-3][c+3] == token)
            {
                win = 1;
            }
            if(board[r][c] == token &&
               board[r][c+1] == token &&
               board[r][c+2] == token &&
               board[r][c+3] == token)
            {
                win = 1;
            }
        }
    }
    return win;
}

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

void Win (players currentPlayer, char board[][10])
{
    cout << endl << currentPlayer.name << " has connected 4! Game Over!" << endl;
    
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
        FinalBoard << "Player " << currentPlayer.name << ", with token " << currentPlayer.token <<  ", has won with this board!" << endl;
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

int Restart (char board[][10])
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