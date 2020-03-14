/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/8/2020
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

//This function takes the user input and reads it into the vector.
void read(vector<int> &even, vector<int> &odd)
{
    //Variables
    int n;
    int temp; 
    cout<<"Input the number of integers to input."<<endl;
    cin>>n;//Reads the user's input.
    cout<<"Input each number."<<endl; 
    for(int i=0;i<n;i++)//This statement fills in the even and odd vectors.
    {
        cin>>temp;
        if(temp%2==0)
        {
            even.push_back(temp); 
        }
        else 
        {
            odd.push_back(temp); 
        }
    }
}

//The main purpose of this function is to copy the vector to a 2-D array.
void copy(vector<int> even, vector<int> odd,int arr[][COLMAX])
{
    //Variables
    int size_even=even.size();
    int size_odd=odd.size();
    int i=0;
    int j=0;
    while(i<size_even)//This statement copies all even vector inputs to the array.
    {
        arr[i][0]=even[i];
        i++;
    }
    while(j<size_odd)//This statement copies all odd vector inputs to the array.
    {
        arr[j][1]=odd[j];
        j++;
    }
}

//This functions prints the vector with the values inputted.
void prntVec(vector<int> even, vector<int> odd,int width)
{
    //Variables
    int size_even=even.size();
    int size_odd=odd.size();
    int i=0;
    int j=0;
    cout<<setw(width)<<"Vector"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl;
    while(i<size_even && j<size_odd)
    {
        cout<<setw(width*2)<<even[i]<<setw(width)<<odd[j]<<endl; 
        i++; 
        j++; 
    }
    while(i<size_even)
    {
        cout<<setw(width*2)<<even[i]<<endl; 
        i++; 
        }
    while(j<size_odd) 
    {
        cout<<setw(width*3)<<odd[j]<<endl; 
        j++; 
    }
}

//This function inputs the entire array with the coppied vector elements.
void prntAry(const int arr[][COLMAX],int size_even,int size_odd,int width)
{
    int i=0;
    int j=0;
    //Outputs header.
    cout<<setw(width)<<"Array"<<setw(width)<<"Even"<<setw(width)<<"Odd"<<endl;
    while(i<size_even && j<size_odd)//Outputs all the values with correct setw().
    {
        cout<<setw(width*2)<<arr[i][0]<<setw(width)<<arr[j][1]<<endl;
        i++;
        j++;
    }
    while(i<size_even)
    {
        cout<<setw(width*2)<<arr[i][0]<<endl;
        i++;
    }
    while(j<size_odd)
    {
        cout<<setw(width*3)<<arr[j][1]<<endl;
    j++;
    }
}