/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/22/2020
 * Purpose: Median - Dynamic Memory Allocation
 */

//System Level Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);
void prntDat(int *,int);
void prntMed(float *,int);
float *median (int* numbers, int size);

//Execution Begins Here!
int main()
{
    //Variable Declarations
    int actualSize = 0;
    int *numbers = getData(actualSize);//array of original inputed data
    float * m = median(numbers, actualSize);//median-calculated array
    prntDat(numbers, actualSize);
    cout << endl;
    prntMed(m, actualSize);
    return 0;
}

//This function will take the input of the user into an array
int* getData(int& size)
{
    int n;
    cin>>n;
    int *num = new int[n];
    for(int i=0; i<n; ++i)
        cin>>num[i];
    size = n;
    return num;
}

//This function will print the array according to the correct format
void prntDat (int *arr, int n )
{
    int c = 0;
    for(int i=0; i<n; ++i)
    {
        cout<< arr[i];
        c++;
        if(c < n)
        {
            cout << " ";
        }
        else
        {
            c=0;
        }    
    }
}

//This function calculates the median of the inputed array
float *median(int* numbers, int size)
{
    float *arr = new float[size+2];
    for(int i=2;i<size+2;++i)
    {
        arr[i] = 1.0*numbers[i-2];
    }
    arr[0] = size+2;
    if(size % 2 != 0)
    {
        float median = *(numbers + (size/2));
        arr[1] = median;
    }
    else
    {
        int index1 = (size / 2)-1;
        int index2 = size / 2;
        float median = (*(numbers + index1) + *(numbers +index2))/ 2.0;
        arr[1] = median;
    }
    return arr;
}

//This function will print the median array in correct format
void prntMed (float *arr, int n )
{
    int c = 0;
    cout << arr[0] <<" ";
    for(int i=1; i<n+2; ++i)
    {
        cout<<fixed<<setprecision(2)<<arr[i];
        c++;
        if (c<=n)
        {
            cout << " ";
        }
        else
        {
            c=0;
        }
    }
}