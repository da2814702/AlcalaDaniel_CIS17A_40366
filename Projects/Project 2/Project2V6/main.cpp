/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    June 7, 2020
 * Purpose: Connect 4 Game Project 2 V6
 *          Version 6 Info: This is the final version of the game.
 */

//System Level Libraries
#include "header.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    //Variable Declarations
    Player playerOne,playerTwo;
    char board[9][10];
    string name;
    char token;
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
    getline(cin, name);
    playerOne.setName(name);
    cout << "Enter the token you wish to play as(X or O): ";
    cin >> token;
    cin.ignore();
    token = toupper(token);
    while (token != 'X' && token != 'O')
    {
        cout << "Incorrect token choice! Try again: ";
        cin >> token;
        cin.ignore();
    }
    playerOne.setToken(token);
    
    cout << "Enter player 2's name: ";
    getline(cin, name);
    playerTwo.setName(name);
    if (token == 'X')
    {
        token = 'O';
        playerTwo.setToken(token);
    }
    else if (token == 'O')
    {
        token = 'X';
        playerTwo.setToken(token);
    }
    
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
            playerOne.win();
            Win1(playerOne, playerTwo, board);
            cout << playerOne.giveName() << "'s Score: " << playerOne.giveWins() << endl;
            cout << playerTwo.giveName() << "'s Score: " << playerTwo.giveWins() << endl;
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
            playerTwo.win();
            Win2(playerOne, playerTwo, board);
            cout << playerOne.giveName() << "'s Score: " << playerOne.giveWins() << endl;
            cout << playerTwo.giveName() << "'s Score: " << playerTwo.giveWins() << endl;
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