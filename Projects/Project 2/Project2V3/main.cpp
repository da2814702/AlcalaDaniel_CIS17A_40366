/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    June 3, 2020
 * Purpose: Connect 4 Game Project 2 V3
 *          Version 3 Info: This version attempts to create a class that can be
 *          used for all functions. THIS VERSION DOES NOT WORK! It does not run,
 *          and will not work. This version was only meant for testing purposes. 
 */

//System Level Libraries
#include "header.h"

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    //Variable Declarations
    players playerOne, playerTwo;
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
    getline(cin, toupper(token));
    while (token != 'X' && token != 'O')
    {
        cout << "Incorrect token choice! Try again: ";
        getline(cin, toupper(token));
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
    
    playerOne.OutputBoard();
    do
    {
        choice = playerOne.rowToDropIn();
        playerOne.checkForToken(choice);
        
        //Display Outputs
        playerOne.OutputBoard();
        win = playerOne.checkForWin();
        if (win == 1)
        {
            playerOne.Win();
            //Clean Up
            repeat = playerOne.Restart();
            if (repeat == 2)
            {
                break;
            }
        }
        
        choice = playerTwo.rowToDropIn();
        playerTwo.checkForToken(choice);
        
        //Display Outputs
        playerTwo.OutputBoard(board);
        win = playerTwo.checkForWin();
        if (win == 1)
        {
            playerTwo.Win();
            //Clean Up
            repeat = playerTwo.Restart();
            if (repeat == 2)
            {
                break;
            }
        }
        
        max = playerTwo.checkFullBoard();
        if (max == 7)
        {
            cout << "The board has been completely filled up! The game is a draw!" << endl;
            repeat = playerTwo.Restart();
        }
    }while (repeat != 2);
    
    //Exit stage right!
    return 0;
}