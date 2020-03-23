/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/22/2020
 * Purpose: 2-D Augment - Dynamic Memory Allocation
 */

//System Level Libraries
#include <iostream>   //I/O Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
int **getData(int &,int &);
void printDat(const int * const *,int,int);
int **augment(const int * const *,int,int);
void destroy(int **,int);

//Execution Begins Here!
int main()
{
    int row,col;
    int **og;
    og=getData(row,col);
    printDat(og,row,col);
    cout << endl;
    ++row;
    ++col;
    og=augment(og,row,col);
    printDat(og,row,col);
    destroy(og,row);
    return 0;
}

//This function takes the inputs of both the columns and rows, and dynamically
//allocates a new array and inputs the user input into that array.
int **getData(int &row,int &col)
{
    cin>>row>>col;
    int** arr = new int*[row];
    for (int i = 0; i < row; ++i)
        arr[i] = new int[col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    return arr;
}

//This function simply prints the entire 2D array according to the correct format.
void printDat(const int * const *og,int row,int col)
{
   int c = 0;
   int r = 0;
   for(int i=0;i<row;i++)
   {
       for(int j=0;j<col;j++)
       {
           cout<<og[i][j];
           c++;
           if (c<col)
           {
               cout << " ";
           }
           else
           {
               c = 0;
           }
       }
       r++;
       if (r < row)
       {
           cout << endl;
       }
       else
       {
           r = 0;
       }
   }
}

//This function augments the original array by creating a new array 1 row and
//column larger, then sets the first row and columns equal to zero, and finally
//inputs the original array into the modified array, leaving the first row and 
//column.
int **augment(const int * const *og,int row,int col)
{
    int** arr = new int*[row];
    for (int i = 0; i < row; ++i)
        arr[i] = new int[col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(i==0)      
            {
                arr[i][j]=0;
            }
            else if(j==0)
            {
                arr[i][j]=0;                  
            }
            else
            {
                arr[i][j]=og[i-1][j-1];
            }
        }
    }
    return arr;
}

//This function deallocates all memory from the array.
void destroy(int **og,int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] og[i];
    }
}