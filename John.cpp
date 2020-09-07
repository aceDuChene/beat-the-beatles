/**************************************************************************
* Class Name: John
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: John makes you play hangman. If player wins, an item 
*    specific to John will be added to their bag.
 * ************************************************************************/
#include "John.hpp"

/******************************************************************************
* John constructor: Sets up the John object.
* ****************************************************************************/
John::John(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom, string inName)
    :Space(inTop, inRight, inLeft, inBottom, inName){
    this->setInteractBool(false);
}
 
/******************************************************************************
* interaction: Creates the interactive element of the space for the user
*    to complete. If done correctly, will add the space's item to their ItemBag.
* ****************************************************************************/
void John::interaction(Player *inPlayer){
    inPlayer->setCurrentSpace(this);
    if(this->getInteractBool() == true){
        cout << "You have already played with John," << endl;
        cout << "but you can do it again? Y/N: ";
        char answer = validateChar(false);
        if(answer == 'Y'){
            if(this->miniGame(inPlayer)){
                cout << "All we are saying, is give John a chance." << endl;
                cout << "If you keep beating him, he might get sad." << endl;
                cout << "Check your inventory for a new item." << endl << endl;
                inPlayer->getPlayerItems()->addItem(getRandItem(0));
            }
            else{
                cout << "John gives you a smile, \"Thanks for letting me win that one.\"" << endl;
                cout << "Try again." << endl << endl;
            }
        }
        else{
            cout << "You're right, the others are more interesting." << endl << endl;
        }
    }
    else{
        readFile("johnTest.txt");
        if(this->miniGame(inPlayer)){
            cout << "\"Well, you beat me! You're getting better all the time, aren't you?\"" << endl;
            cout << "He hands you his guitar. Check your inventory to see." << endl << endl;
            inPlayer->getPlayerItems()->addItem(getRandItem(1));
            this->setInteractBool(true);
        }
        else{
            cout << "\"I'm sorry, but if you can't even spell this word," << endl;
            cout << "I don't know if I should trust you with my things, now.\"" << endl;
            cout << "Try again." << endl << endl;
        }
    }
}

/**************************************************************************
 * minigame: John's minigame has the player play hangman. It compares two
 *   arrays, a blank one and one with the word to be guessed. Keeps track of
 *   the wrong guesses, and only allows 5 wrong guesses.
 * ************************************************************************/
bool John::miniGame(Player *inPlayer){
    srand(time(NULL));
    string possibleWords[7] = {"BEATLES", "PEACE", "NOWHEREMAN", "LIVERPOOL", "LOVE", "YOKO", "LENNON"};
    string word = possibleWords[rand()%7];
    char *arrayPtr = new char[word.length()];
    char inGuess;
    //int guessAmt = word.length() + 5;
    char wrongLetters[5] = {' ', ' ', ' ', ' ', ' '};
    int numWrong = 1;
    bool rightGuess = false;
    //bool gameDone = false;
    bool letterGuessed = false;
    cout << "If you reach 5 wrong letters, you lose the hangman game." << endl;

    for(size_t i = 0; i < word.length(); i++){
        arrayPtr[i] = '_';
    }

    printArray(arrayPtr, word.length());

    while(numWrong != 6){
        cout << "Wrong guesses left: " << 6 - numWrong << endl;

        //print out list of wrong letters so far
        if(wrongLetters[0] != ' '){
            cout << "Wrong letters guessed: ";
            printArray(wrongLetters, 5);
            cout << endl;
        }

        //prompt for new letter
        do{
            letterGuessed = false;
            cout << "What letter?" << endl;
            inGuess = validateAlpha();
            for(size_t j = 0; j < word.length(); j++){
                if(arrayPtr[j] == inGuess && !letterGuessed){
                    cout << "You have already tried that." << endl;
                    letterGuessed = true;
                }
            }
            for(int k = 0; k < 5; k++){
                if(wrongLetters[k] == inGuess && !letterGuessed){
                    cout << "Pick another letter." << endl;
                    letterGuessed = true;
                }
            }
        }while(letterGuessed);

        //changes index of game board if guess matches the word
        for(size_t j = 0; j < word.length(); j++){
            if(word[j] == inGuess){
                arrayPtr[j] = inGuess;
                //the guess was correct
                rightGuess = true;
            }
        }
        
        //when the guess was wrong
        if(!rightGuess){
            wrongLetters[numWrong - 1] = inGuess;
            numWrong++;
        }
        //resets the rightGuess bool
        rightGuess = false;

        printArray(arrayPtr, word.length());

        if(numWrong == 6){
            cout << "Wrong letters guessed: ";
            printArray(wrongLetters, 5);
            cout << "You lost..." << endl;
            //numWrong = guessAmt;
            cout << "Correct answer: " << word << endl;
            //gameDone = true;
            delete [] arrayPtr;
            return false;
        }        

        if(checkSolved(arrayPtr, word.length())){
            numWrong = 6;
            if(this->getInteractBool()){
                cout << "You beat John again." << endl;
                delete [] arrayPtr;
                return true;
            }
            else{
                cout << "You win!" << endl;
                this->setInteractBool(true);
                //gameDone = true;
                delete [] arrayPtr;
                return true;
            }
        }
    }

    delete [] arrayPtr;
    return false;
}

/**************************************************************************
 * printArray: This will print the arrays of letters/underscores.
 * ************************************************************************/
void John::printArray(char *inArray, int inSize){
    for(int i = 0; i < inSize; i++){
        cout << inArray[i] << " ";
    }
    cout << endl;
}

/**************************************************************************
 * checkSolved: checks if the user's guessing array is void of underscores.
 *    if so, that means all the correct letters are guessed and returns true.
 * ************************************************************************/
bool John::checkSolved(char *inArray, int inSize){
    int count = 0;
    for(int i = 0; i < inSize; i++){
        if(inArray[i] != '_' && inArray[i] != ' '){
            count++;
        }
    }
    if(count == inSize){
        return true;
    }
    return false;
}

/******************************************************************************
* getRandItem: Sets up three possible items for the user to obtain after
*    winning a round. The first item will be the necessary item to complete the 
*    game. After that, a random item will be rewarded. To be counted as the first
*    item, 1 must be passed as the parameter.
* ****************************************************************************/
Item John::getRandItem(int inNum){
    int num = rand()%3 + 1;
    if(inNum == 1){
        num = 1;
    }

    Item guitar("Epiphone Casino Guitar", "John used this guitar during the final rooftop concert in 1969.");
    Item cat("Tim", "A marmalade-colored half-persian cat.\nJohn will be sad that you stole him.");
    Item money("Monopoly Money", "John loved to play Monopoly, even at 3 in the morning.\nDon't tell him you have money up your sleeve.");

    switch(num){
        case 1:
            return guitar;
        case 2:
            return cat;
        default:
            return money;
    }
}