/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/8/2020
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char []);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    int sizeDet;//Number of characters to be read, check against length
    char array[SIZE];//Actual character array to store inputed values
    int len;//Stores the length of the character array 
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>len;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==len){
        sort(array,len); //Sort the array
        print(array,len);//Print the array
    }else{
        cout<<(sizeDet<len?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

//The purpose of this function is to determine the length of the
//C string length and return that value back to main.
int read(char array [])
{
    cin>>array;//reads char array from inputs given from main
    return strlen(array);//returns the length of the char array
}

//This is a simple bubble sort function. It compares elements of the array
//with elements next to it and swaps if the condition is met.
void sort(char array [] ,int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=i+1;j<len;j++)
        {
            if(array[j]<array[i])
            {
                char temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

//This function simply prints all of the members of the array.
void print(const char array[], int len)
{
    for (int i = 0; i < len; i++) 
    {
        cout << array[i];
    }
    cout << endl;
    return;
}