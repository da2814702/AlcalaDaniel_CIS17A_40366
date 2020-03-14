/* 
 * File:   main.cpp
 * Author: Daniel Alcala
 * Created on 3/8/2020
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}

//The srch1 function will look for a pattern in the sentence. If it
//it has found one, it will return the index number, else it will return
//a -1, which is disregarded in other functions.
int srch1(const char sentence[],const char pattern[],int start_index)
{
    int patternLength = strlen(pattern);
    int sentenceLength = strlen(sentence);
    int j;
    for ( j = 0; j < sentenceLength; j++)
    {
        if (sentence[start_index + j] != pattern[j])
        break;
    }
    if (j == patternLength)
    {
        return start_index;
    }
    else
    return -1;
}

//The srchAll function will look through the sentence for the pattern.
//If it will also search for the index of a matching pattern,
//and it will put that into an index array.
void srchAll(const char sentence[],const char pattern[],int array[81])//Search for all occurrences
{
   int patternLength = strlen(pattern);
   int sentenceLength = strlen(sentence);
   int cnt=0;
   for(int i=0;i<sentenceLength-patternLength;i++)
   {
       int index=srch1(sentence,pattern,i);
       if(index!=-1)
       {
            array[cnt++]=index;
       }
   }
}

//This function will print the sentence that has been input.
void print(const char array[])
{
    int i=0;
    while(array[i]!=-1)
    {
        cout<<array[i];
        i++;
    }
    cout << endl;
}

//This function will print the indexes of any patterns matching the sentence.
void print(const int array[])
{
    int i=0;
    while(array[i]!=-1)
    {
        cout<<array[i]<<" ";
        i++;
    }
}