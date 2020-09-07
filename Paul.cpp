/**************************************************************************
* Class Name: Paul
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: Paul asks the player a trivia question. They have two chances
*    to get the correct answer, if they do, they are awarded a Paul specific item.
 * ************************************************************************/
#include "Paul.hpp"

/******************************************************************************
* Paul constructor: Sets up the Paul object.
* ****************************************************************************/
Paul::Paul(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom, string inName)
    :Space(inTop, inRight, inLeft, inBottom, inName){
    this->setInteractBool(false);
}
 
/******************************************************************************
* interaction: Creates the interactive element of the space for the user
*    to complete. If done correctly, will add the space's item to their ItemBag.
* ****************************************************************************/
void Paul::interaction(Player *inPlayer){
    inPlayer->setCurrentSpace(this);
    char answer = ' ';
    if(this->getInteractBool() == true){
        cout << "You have already chatted with Paul." << endl;
        cout << "But you can do it again? Y/N: ";
        answer = validateChar(false);
        if(answer == 'Y'){
            if(this->miniGame(inPlayer)){
                cout << "\"Well, it looks like you really know your stuff." << endl;
                cout << "Go ahead and take this as proof of your genius.\"" << endl;
                cout << "Paul reaches into his coat and pulls a random item out of nowhere." << endl;
                cout << "Check your inventory to see." << endl << endl;
                inPlayer->getPlayerItems()->addItem(getRandItem(0));
            }
            else{
                cout << "\"Don't let it get you down, mate. You can always try again to make it better.\"" << endl;
                cout << "Try again." << endl << endl;
            }
        }
        else{
            cout << "Well, that's too bad, y'know." << endl << endl;
        }
    }
    else{
        readFile("paulText.txt");
        if(this->miniGame(inPlayer)){
            cout << "\"You might know more about us than even we do, and we know right about nothing." << endl;
            cout << "Take good care of my Hofner bass and be sure to put it in the right place.\"" << endl;
            cout << "Paul passes you the bass guitar. Check your inventory to see." << endl << endl;
            inPlayer->getPlayerItems()->addItem(getRandItem(1));
            this->setInteractBool(true);
        }
        else{
            cout << "\"Well, you didn't get it this time. But I want to help you with your problem." << endl;
            cout << "Why don't you come back again and we'll act like none of this ever happened?\"" << endl;
            cout << "Try again." << endl << endl;
        }
    }
}

/**************************************************************************
* miniGame: Paul's mini game has the player answering trivia questions
*   using A, B, C, and D. If the player gets it wrong, they get one more
*   chance. If it is wrong again, returns 
 * ************************************************************************/
bool Paul::miniGame(Player *inPlayer){
    srand(time(NULL));
    char userAnswer = ' ';
    char correctAnswers[6] = {'A', 'B', 'C', 'C', 'D', 'B'};
    string questions[6] = {"Who was the original drummer of The Beatles?\nA: Pete Best\nB: Ringo Starr\nC: Keith Moon\nD: Ash Ketchum",
        "What was the band's name when they first played in the clubs?\nA. The Silver Beat-Alls\nB. The Quarrymen\nC. Chaos Sauce\nD. The Scrummies",
        "Which Beatle was the first to become a vegetarian?\nA. John\nB. Paul\nC. George\nD. Ringo",
        "Which of these Beatles movies is an animated feature?\nA. A Hard Day’s Night\nB. Help!\nC. Yellow Submarine\nD. Let It Be",
        "With a tune in Paul’s mind and no lyrics to put to it, what was the working title of “Yesterday”?\nA. Tofu Wings\nB. Tomorrow’s Song\nC. Bury Me\nD. Scrambled Eggs",
        "Which Beatle was swept up in a conspiracy theory in the late 1960s, as fans dug up “clues” \nshowing that he died and was replaced by a look-alike?\nA. John\nB. Paul\nC. George\nD. Ringo"};
    int randQ = rand()%6;

    cout << questions[randQ] << endl;
    userAnswer = validateABCD();
    if(userAnswer != correctAnswers[randQ]){
        cout << "Sorry, wrong answer..." << endl;
        cout << "\"I'm a nice guy, y'know. I'll give you one more shot at this one." << endl;
        cout << "If you're wrong this time, though, I'll have to kick you out of here." << endl;
        cout << "You could always just come right back. I know I'm hard to resist.\"" << endl;
        cout << questions[randQ] << endl;
        userAnswer = validateABCD();
    }
    if(userAnswer != correctAnswers[randQ]){
        return false;
    }
    return true;
}

/******************************************************************************
* getRandItem: Sets up three possible items for the user to obtain after
*    winning a round. The first item will be the necessary item to complete the 
*    game. After that, a random item will be rewarded. To be counted as the first
*    item, 1 must be passed as the parameter.
* ****************************************************************************/
Item Paul::getRandItem(int inNum){
    int num = rand()%3 + 1;
    if(inNum == 1){
        num = 1;
    }

    Item bass("Hofner Bass", "Paul straight up just turned this baby upside down so he could play left-handed.");
    Item doll("Paul Doll", "For some reason, this ugly Paul McCartney doll fills you with a parental instinct.");
    Item mash("Mashed Potatoes", "One of the reasons Paul isn't a full blown vegan.");

    switch(num){
        case 1:
            return bass;
        case 2:
            return doll;
        default:
            return mash;
    }
}