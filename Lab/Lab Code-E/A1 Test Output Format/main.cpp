/* 
 * File:    main.cpp
 * Author:  Daniel Alcala
 * Date:    3/8/2020
 * Purpose: Test Output Format
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
    int firstNumber;//user input number one
    float secondNumber;//user input number two
    
    //Initialize or input data here
    cin >> firstNumber;//read user input for number one
    cin >> secondNumber;//read user input for number two
    //Display initial conditions, headings here
    
    //Process inputs  - map to outputs here

    //Format and display outputs here
    //Output both first and second number with
    //correctly spaced output to follow.
    cout << firstNumber << endl;
    cout << secondNumber << endl;
    cout << setw(16) << left << "Hello World" << endl;
    cout << "\tTab it!" << endl;
    cout << "Compare . . . to space   ";
    
    //Clean up allocated memory here
    
    //Exit stage left
    return 0;
}