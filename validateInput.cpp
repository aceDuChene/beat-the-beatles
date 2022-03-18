/************************************************************************
 * Function name: validateInput
 * Author: Danielle DuChene
 * Date: 12-10-2019
 * Description: Takes in a min and max integer and checks user input
 *    to see if it is an integer and is between those values. Also has
 *    functions to check for various char inputs.
 * *********************************************************************/
#include "validateInput.hpp"

/************************************************************************
* validateInteger: Re-prompts the user if the input is not in between
*    the passed integer parameters.
*************************************************************************/
const int validateInteger(int min, int max){
    int newInt;
    cout << "Enter an integer between " << min << " and " << max << ": ";

    //this is used from http://www.cplusplus.com/forum/beginner/52588/
    while((cin >> newInt).fail() || cin.peek() != '\n' || newInt < min || newInt > max){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please input a valid number: ";
    }

    return newInt;
}

/************************************************************************
* validateChar: Checks if user has inputted y/Y/n/N. Takes in a bool
*   as the clear/ignore cycle will only be needed if it is not the 
*   first prompt.
*************************************************************************/
char validateChar(bool start){
    char answerChar;
    string answerString;

    if(start){
    }
    else{
        cin.clear();
        cin.ignore();
    }
    getline(cin, answerString);
    answerChar = toupper(answerString[0]);
    while(answerString.length() != 1 || (answerChar != 'Y' && answerChar != 'N')){
        cout << "Please input only one valid letter: ";
        getline(cin, answerString);
        answerChar = toupper(answerString[0]);
    }

    return answerChar; //will return Y or N
}

/************************************************************************
* validateAlpha: Makes sure the user has input a single alpha character.
*************************************************************************/
char validateAlpha(){
    char answerChar;
    string answerString;

    cin.clear();

    getline(cin, answerString);
    answerChar = toupper(answerString[0]);
    while(answerString.length() != 1 || !isalpha(answerChar)){
        cout << "Please input only one valid letter: ";
        getline(cin, answerString);
        answerChar = toupper(answerString[0]);
    }

    return answerChar;  
}

/************************************************************************
* validateABC: Ensures the user inputs either A B or C.
*************************************************************************/
char validateABC(){
    char answerChar;
    string answerString;

    cin.clear();
    cin.ignore();

    getline(cin, answerString);
    answerChar = toupper(answerString[0]);
    while(answerString.length() != 1 || (answerChar != 'A' && answerChar != 'B' &&
        answerChar != 'C')){
        cout << "Please input only one valid letter: ";
        getline(cin, answerString);
        answerChar = toupper(answerString[0]);
    }
    

    return answerChar;  
}

/************************************************************************
* validateABCD: Ensures the user inputs either A B C or D.
*************************************************************************/
char validateABCD(){
    char answerChar;
    string answerString;

    cin.clear();

    getline(cin, answerString);
    answerChar = toupper(answerString[0]);
    while(answerString.length() != 1 || (answerChar != 'A' && answerChar != 'B' &&
        answerChar != 'C' && answerChar != 'D')){
        cout << "Please input only one valid letter: ";
        getline(cin, answerString);
        answerChar = toupper(answerString[0]);
    }

    return answerChar; //will return A B C or D
}

/************************************************************************
* readFile: Takes in a file name and prints it to the screen.
*************************************************************************/
void readFile(string inName){
    ifstream inFile;
    string nextString;
    cin.clear();
    inFile.open(inName);

    if(!inFile){
        cout << "Error opening file." << endl;
    }

    getline(inFile,nextString);
    cout << nextString << endl;
    while(inFile){
        getline(inFile,nextString);
        cout << nextString << endl;
    }

    inFile.close();
}