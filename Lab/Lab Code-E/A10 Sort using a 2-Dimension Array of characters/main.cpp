/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/8/2020
 * Purpose:  Sort using a 2-Dimension Array of characters
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order
void strrep(char [], const char [], const char []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    //if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    
    //Exit
    return 0;
}

//This function reads the array to determine the largest column.
int read(char array[][COLMAX],int &rowDet)
{
    //Variables
    int colDet = 0;
    int length;
    cin.ignore(1024,'\n');
    //Read through each row of the array
    for (int i=0;i<rowDet;i++) 
    {
        cin.getline(array[i], COLMAX);
        length=strlen(array[i]);//determines the length of each column
        if (length>colDet)//copies the biggest element in the array
        {
            colDet=length;
        }
    }
    return colDet; //returns the detemined column number
}

//This function sorts the array using the function strcmp to determine the correct order.
void sort(char array[][COLMAX],int rowIn,int colIn, const char replace[],const char with[])
{
    char temp[COLMAX];
    for (int i=0;i<rowIn; i++)
    {
        for (int j=0;j<rowIn-1;j++)
        {
            if(strcmp(array[j+1],array[j]) > 0)//compares the elements, returns 1 if true
            {
                //These lines swap the elemnt in the array in the correct order.
                strcpy(temp,array[j+1]);
                strcpy(array[j+1],array[j]);
                strcpy(array[j],temp);
            }
        }
    }
}

//This function prints the entire array line by line.
void print(const char array[][COLMAX],int rowIn, int colIn)
{
    for (int i = 0; i < rowIn; i++) 
    {
        cout << array[i];
        cout << endl;
    }
    return;
}

//This function acts as the string compare in the library. It looks through the
//first array and determines whether or not to replace. It then uses the next
//function, strrep, to replace the copy with the new element.
int strcmp(char first[], char second[], const char replace[], const char with[]) 
{
    char firCopy[COLMAX];
    for (int count=0;firCopy[count]=='\0';count++) //creates copy of the first string
    {
        firCopy[count] = first[count];
    }
    char secCopy[COLMAX];
    for (int count=0;secCopy[count]=='\0';count++)//creates copy of the second string
    {
        secCopy[count] = second[count];
    }
    strrep(firCopy, replace, with);
    strrep(secCopy, replace, with);
    return strcmp(firCopy, secCopy);
}

//This function replaces the source char array with the desired array.
void strrep(char source[], const char replace[], const char with[]) 
{
    int sourLen = strlen(source);
    int repLen = strlen(replace);
    for (int count=0;count<sourLen;count++)
    {
        for (int cntr=0;cntr<repLen&&source[count]==replace[cntr];cntr++) 
        {
            if (source[count]==replace[cntr]) 
            {
                source[count]=with[cntr];
            }
        }
    }
}