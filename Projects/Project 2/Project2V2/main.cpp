/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    June 2, 2020
 * Purpose: Connect 4 Game Project 2 V2
 *          Version 2 Info: With this version, I aimed to get all functions in
 *          their own separate files. Yet again, not changing any of the program.
 *          The reason for doing this clean-up is to allow for more efficent
 *          programming in the future.
 */

//System Level Libraries
#include "header.h"

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