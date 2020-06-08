/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    June 7, 2020
 * Purpose: Connect 4 Game Project 2 V6
 */

#ifndef HEADER_H
#define HEADER_H

#include <iostream>   //I/O Library
#include <iomanip>
#include <string>     //Strings
#include <fstream>    //File Output/Input
using namespace std;  //Libraries compiled under std

class info
{
private:
    string name;
    char token;
public:
    info(string n, char t)
    {
        name = n;
        char = t;
    }
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
    void operator delete[](void* ptr)
    {
        cout << "Now deleting the board and refilling!";
        free(ptr);
    }
};

class Player : public info
{
protected:
    int wins = 0;
public:
    void win()
    {
        wins++;
    }
    
    int giveWins() const
    {
        return wins;
    }
};

int rowToDropIn (char board[][10], info currentPlayer);
void checkForToken (char board[][10], info currentPlayer, int dropLocation);
void OutputBoard (char board[][10]);
int checkForWin (char board[][10], info currentPlayer);
int checkFullBoard (char board[][10]);
void Win1 (Player p1, Player p2, char board [][10]);
void Win2 (Player p1, Player p2, char board [][10]);
int Restart (char board[][10]);

#endif /* HEADER_H */