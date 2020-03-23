/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/22/2020
 * Purpose: Sum - Dynamic Memory Allocation
 */

//System Level Libraries
#include <iostream>   //I/O Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);             //Return the array size and the array from the inputs
int *sumAry(const int *,int);//Return the array with successive sums
void prntAry(const int *,int);//Print the array

//Execution Begins Here!
int main()
{
    int n;
    int *array = getData(n);
    int *sum = sumAry(array, n);
    prntAry(array, n);
    cout << endl;
    prntAry(sum, n);
    return 0;
}

//This function takes the user input and puts it into an array.
int *getData(int &n)
{
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    return array;
}

//This function sums the array successively, thus increasing further along
//the array.
int *sumAry(const int *array, int n)
{
    int *sum = new int[n];
    sum[0] = array[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + array[i];
    return sum;
}

//This function prints the array in the correct format.
void prntAry(const int *array, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        cout << array[i];
        c++;
        if (c<n)
        {
            cout << " ";
        }
        else
        {
            c=0;
        }
    }
}