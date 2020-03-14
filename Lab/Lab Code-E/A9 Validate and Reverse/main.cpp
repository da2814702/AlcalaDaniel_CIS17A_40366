/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/8/2020
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short
    
    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;
    
    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }
    
    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);
    
    //Output the result
    cout<<snShort<<endl;
    
    //Exit
    return 0;
}


//This function basically checks if the char array has a number that
//can be converted into a short data type.
bool inRange(const char digits[] ,unsigned short &un)
{
    int i;
    int size = strlen(digits);
    if(size > 5)//First check for short data type.
        return false;
    for (i = 0; i< size; i++)
    {
        if(!isdigit(digits[i]))//checks for digits
        return false;
    }
    int j=0;
    int sum =0;
    //this statement sums the array to determine if
    //it is capable for a short data type
    for( i = 0; i<size ; i++)
    {
        sum = (digits[i] - '0')+ (sum * 10);
    }
    if(sum >0 && sum <65535)//if all conditions are met, input could be short data type
        {
        un = sum;
        return true;
    }
}

//This function will reverse the short number based on several conditions.
//It mainly checks the trailing zeros to determine how many zeros need to
//be added to the reversed number.
bool reverse(unsigned short un,signed short &sn)
{
    unsigned short n = un;
    unsigned short reversedNumber;
    int remainder,flag = 1;
    if (n >= 10000)
        flag = 0;
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    //This statement checks for all the diffrent combinations
    //of zeros that a short can contain.
    if (flag)
        if(reversedNumber >= 1000)
        {
            reversedNumber *= 10;
        }
        else if(reversedNumber >= 100)
        {
            reversedNumber *= 100;
        }
        else if(reversedNumber >= 10)
        {
            reversedNumber *= 1000;
        }
        else if(reversedNumber >= 0)
        {
            reversedNumber *= 10000;
        }
    if(reversedNumber > 32767 )
        return false;
    else
    {
        sn = (signed short)reversedNumber;
        return true;
    }
}

//This function subtracts 999 if and only if the subtracted
//value will not be negative, else it just returns the orignal
//value.
short subtrct(signed short snShort, int n)
{
    signed short temp;
    temp = snShort - n;
    if (temp >= -1)
    {
        return temp;
    }
    else
    {
        return snShort;
    }
}