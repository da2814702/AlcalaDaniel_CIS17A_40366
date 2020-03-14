/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    3/8/2020
 * Purpose: More Test Output Format
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed
    
    //Declare variables or constants here
    //7 characters or less
    double numOne;//value number one
    double numTwo;//value number two
    double numThree;//value number three
    double numFour;//value number four
    
    //Initialize or input data here
    cin >> numOne;//ask user to inputer number one
    cin >> numTwo;//ask user to inputer number two
    cin >> numThree;//ask user to inputer number three
    cin >> numFour;//ask user to inputer number four
    
    //Display initial conditions, headings here
    //Displays input one in correct format
    cout << setw(9) << numOne;
    cout << setw(10) << setprecision(2) << showpoint << numOne;
    cout << setw(10) << setprecision(3) << showpoint << numOne << endl;
    
    //Displays input two in correct format
    cout << setw(9) << setprecision(0) << noshowpoint << numTwo;
    cout << setw(10) << setprecision(2) << showpoint << numTwo;
    cout << setw(10) << setprecision(3) << showpoint << numTwo << endl;
    
    //Displays input three in correct format
    cout << setw(9) << setprecision(0) << noshowpoint << numThree;
    cout << setw(10) << setprecision(2) << showpoint << numThree;
    cout << setw(10) << setprecision(3) << showpoint << numThree << endl;
    
    //Displays input four in correct format
    cout << setw(9) << setprecision(0) << noshowpoint << numFour;
    cout << setw(10) << setprecision(2) << showpoint << numFour;
    cout << setw(10) << setprecision(3) << showpoint << numFour;
    
    //Process inputs  - map to outputs here
    
    //Format and display outputs here
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}