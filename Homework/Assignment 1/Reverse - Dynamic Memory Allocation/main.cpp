/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/22/2020
 * Purpose: Reverse - Dynamic Memory Allocation
 */

//System Level Libraries
#include <iostream>   //I/O Library
using namespace std;  //Libraries compiled under std

//User Level Libraries

//Global Constants - Science/Math Related
//Conversions, Higher Dimensions

//Function Prototypes
int *getData(int &);//Fill the array
int *sort(int *,int);//Sort smallest to largest
int reverse(int *,int);//Sort in reverse order
void prntDat(const int *,int);//Print the array
//Execution Begins Here!
int main()
{
   //Variable Declarations
   int size;
   cin>>size;
   int *a = getData(size);
   sort(a,size);
   prntDat(a,size);
   reverse(a,size);
   cout<<endl;
   prntDat(a,size);
}

//This function stores the input into the array
int *getData(int& size)
{
   int *arr = new int [size];
   for(int i=0;i<size;i++)
   {
       cin>>arr[i];
   }
   return arr;
}

//This is a simple sort function
int *sort(int *a,int size) 
{
   int n=size;
   for(int i=n-1;i>=0;i--)
   {
       for(int j=0;j<i;j++)
       {
           if(a[j]>a[j+1])
           {
               int temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
   }
}

//This is also a simple sort function, but in reverse
int reverse(int *a,int size)
{
   int n=size;
   for(int i=n-1;i>=0;i--)
   {
       for(int j=0;j<i;j++)
       {
           if(a[j]<a[j+1])
           {
               int temp=a[j];
               a[j]=a[j+1];
               a[j+1]=temp;
           }
       }
   }
}

//This function simply prints the entire array in correct format
void prntDat(const int *a,int size)
{
    int c = 0;
    for(int i=0;i<size;i++)
    {
        cout<<a[i];
        c++;
        if (c<size)
        {
            cout << " ";
        }
        else
        {
            c = 0;
        }
    }
}

//This function sums up an entire array
int sumAry(int *a,int size)
{
   int sum=0;
   for(int i=0;i<size;i++)
   {
       sum+=a[i];
   }
   return sum;
};