/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/22/2020
 * Purpose: 2-D Sum - Dynamic Memory Allocation
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <random>     //Random Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
int **getData(int &,int &);
void prntDat(const int* const *,int,int);
void destroy(int **,int,int);
int sum(const int * const *, int,int);
//Execution Begins Here!
int main()
{
    int **array, n, m;
    array = getData(n, m);
    prntDat(array, n, m);
    cout << sum(array, n, m);
    destroy(array, n, m);
    return 0;
}

//This function gathers input from the user and inputs it into a 
//dynamically allocated array.
int **getData(int &n, int &m)
{
    cin >> n >> m;
    int **array = new int *[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> array[i][j];
    }
    return array;
}

//This function simply prints the array according to the correct format.
void prntDat(const int *const *array, int n, int m)
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << array[i][j];
            c++;
            if (c<m)
            {
                cout << " ";
            }
            else
            {
                c=0;
            }
        }
        cout << endl;
    }
}

//This function deletes the array from memory.
void destroy(int **array, int n, int m)
{
    for (int i = 0; i < n; i++)
        delete[] array[i];
    delete array;
}

//This function sums up the entire 2-D array.
int sum(const int *const *array, int n, int m)
{
    int Sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Sum += array[i][j];
    return Sum;
}