/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    June 2, 2020
 * Purpose: Connect 4 Game Project 2 V2
 */

#ifndef HEADER_H
#define HEADER_H

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

#endif /* HEADER_H */

