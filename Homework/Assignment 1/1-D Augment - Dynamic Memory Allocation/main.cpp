/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/22/2020
 * Purpose: 1-D Augment - Dynamic Memory Allocation
 */

//System Level Libraries
#include <iostream>   //I/O Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);
int *augment(const int *,int);
void prntAry(const int *,int);

//Execution Begins Here!
int main() 
{
    int n;
    cin >> n;
    int *arr = getData(n);
    prntAry(arr, n);
    cout << endl;
    arr = augment(arr, n);
    prntAry(arr, n+1);
}

//The purpose of this function is to read and store the user input
//into a dynamically allocated array.
int *getData(int &n) 
{
    int *arr = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

//This function places a 0 in the first element and then shifts the array and
//its elements by 1 index.
int *augment(const int *arr, int n)
{
    int *res = new int[n + 1];
    res[0] = 0;
    for (int i = 0; i<n; i++)
    {
        res[i + 1] = arr[i];
    }
    return res;
}

//This function simply prints the the function according to the correct formating.
void prntAry(const int *arr, int n)
{
    int c = 0;
    for (int i = 0; i<n; i++) 
    {
        cout << arr[i];
        c++;
        if (c<n)
        {
            cout << " ";
        }
    }
}