/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    June 3, 2020
 * Purpose: Connect 4 Game Project 2 V
 */
#ifndef HEADER_H
#define HEADER_H

#include <iostream>   //I/O Library
#include <string>     //Strings
#include <fstream>    //File Output/Input
using namespace std;  //Libraries compiled under std

char board[9][10];

class players
{
private:
    string name;
    char token;
public:
    void setName(string na)
    {
        name = na;
    }
    
    void setToken(char to)
    {
        token = to;
    }
    
    string giveName()const
    {
        return name;
    }
    
    char giveToken()const
    {
        return token;
    }
    
    int rowToDropIn() const;
    
    void checkForToken(int choice);
    
    void OutputBoard ();
    
    int checkForWin() const;
    
    int checkFullBoard() const;
    
    void Win();
    
    int Restart() const;
};
//int rowToDropIn (char board[][10], players currentPlayer);
//void checkForToken (char board[][10], players currentPlayer, int dropLocation);
//void OutputBoard (char board[][10]);
//int checkForWin (char board[][10], players currentPlayer);
//int checkFullBoard (char board[][10]);
//void Win (players currentPlayer, char board [][10]);
//int Restart (char board[][10]);

#endif /* HEADER_H */