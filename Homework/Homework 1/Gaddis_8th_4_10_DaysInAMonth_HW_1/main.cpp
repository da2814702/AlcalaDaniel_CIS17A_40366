/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on February 23, 2020, 5:00 PM
 * Purpose: Hello World Program
 */

//System Level Libraries
#include <iostream>   //I/O Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Random Number Seed Set Here
    
    //Variable Declarations
    int year, 
        month;
    //Variable Initialization
    
    //Mapping Process Inputs to Outputs
    
    //Display Outputs
    cout << endl;
    cout << "Enter the month (1 - 12): "; cin >> month;
    cout << "Enter the year (up to 9000): "; cin >> year;
    cout << endl; // Error check for valid year if (year >= 0 && year <= 9000)
    {
        // Decision statement for month
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                cout << "31 days";
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                cout << "30 days";
                break;

            case 2:
                // Decision statement for leap year
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                        cout << "29 days" << endl;
                    else
                        cout << "28 days" << endl;
                }
                else if (year % 100 != 0)
                {
                    if (year % 4 == 0)
                        cout << "29 days" << endl;
                    else
                        cout << "28 days" << endl;
                }
                break;

            default:
                cout << "Invalid month. Rerun program. Try again." << endl;
        }
    }
    return 0;
}