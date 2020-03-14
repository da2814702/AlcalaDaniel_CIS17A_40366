/* 
 * File:   main.cpp
 * Author: Daniel ALcala
 * Created on 3/8/2020
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int  stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

//This function reads the input and outputs the information according to the correct format.
void read(int array[],int sizeIn)
{
    for(int i=0;i<sizeIn;++i)
    {
        
        cin>>array[i];
        cout<<"a["<<i<<"]"<<" = " << array[i];
        cout << endl;
    }
}

//This function determines the max, min, and sum of the array. The function goes through
//each member of the element to keep a additive list while alse determining the lowest
//number in the array.
int stat(const int array[],int sizeIn,int &max,int &min)
{
    min = 1000000;
    max = -100000;
    int sum = 0;
    for(int i=0 ; i<sizeIn ; ++i)
    {
        sum = sum + array[i];
        if(max < array[i])
            max = array[i];
        if(min > array[i])
            min = array[i];
    }
    return sum;
}

//This function simply prints out all the data found.
void print(const int array[],int sizeIn,int sum,int max,int min)
{
    cout<<"Min  = "<<min<<endl;
    cout<<"Max  = "<<max<<endl;
    cout<<"Sum  = "<<sum<<endl;
}