/**************************************************************************
* Class Name: Begin
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: This class is derived from the Space class. This sets up the
*    beginning of the game, asking the user if they want to play. The game
*    will keep returning to this class object to print out the game menus.
 * ************************************************************************/
#include "Begin.hpp"

/******************************************************************************
* Begin constructor: Sets up the Begin object.
* ****************************************************************************/
Begin::Begin(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom, string inName)
    :Space(inTop, inRight, inLeft, inBottom, inName){
    this->setInteractBool(false);
}
 
/******************************************************************************
* interaction: Creates the interactive element of the space for the user
*    to complete. This will ask the user if they want to play if they are
*    first opening the program. Prints the menu of choices if Y is input.
* ****************************************************************************/
void Begin::interaction(Player *inPlayer){
    inPlayer->setCurrentSpace(this);
    bool playBool = true;
    if(!this->getInteractBool()){
        readFile("title.txt");
        cout << "You might have to adjust your window size." << endl;
        cout << "Would you like to play \"Beat The Beatles\"? Y/N: ";
        char answer = validateChar(true);

        if(answer == 'Y'){
            clrscr();
            readFile("begin.txt");
            cout << "Whose room will you start in?" << endl;
            printMenu();
            chooseMenu(inPlayer);
            playBool = true;
        }
        else{
            cout << "I guess you're not a fan." << endl;
            playBool = false;
        }
    }
    else{
        while(playBool){
            inPlayer->setCurrentSpace(this);
            cout << "Choose the next room:" << endl;
            printMenu();
            playBool = chooseMenu(inPlayer);

            //top of begin = ringo, top of ringo = end
            if(this->getTop()->getTop()->getInteractBool()){
                playBool = false;
            }

            if(inPlayer->getStep() == 10){
                //top of begin = ringo, top of ringo = end
                if(this->getTop()->getTop()->testEnd(inPlayer)){
                    this->getTop()->getTop()->interaction(inPlayer);
                    playBool = false;
                }
                else{
                    cout << "Sorry, but you've run out of steps. The Beatles leave you behind since they can't be late to their gig." << endl;
                    cout << "Guess you'll have to continue your trip alone..." << endl;
                    cout << "Try again..." << endl;
                    playBool = false;
                }
            }
        }      
    }
}
 
/****************************************************************
 * printMenu: Prints the menu for the user to choose from.
 * **************************************************************/
void Begin::printMenu(){
    cout << "1. Ringo" << endl;
    cout << "2. Paul" << endl;
    cout << "3. George" << endl;
    cout << "4. John" << endl;
    cout << "5. Check Items" << endl;
    cout << "6. Load up the Magical Mystery Tour Bus" << endl;
    cout << "7. Quit" << endl;
}

/****************************************************************
 * chooseMenu: Takes in an Player to use for the various
 *    interactions of each menu choice. Leads the user to the
 *    respective choice provided.
 * **************************************************************/
bool Begin::chooseMenu(Player *inPlayer){
    switch(validateInteger(1,7)){
        case 1:
            clrscr();
            this->getTop()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 2:
            clrscr();
            this->getRight()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 3:
            clrscr();
            this->getBottom()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 4:
            clrscr();
            this->getLeft()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 5:
            clrscr();
            inPlayer->getPlayerItems()->forwardPrint(false);
            this->setInteractBool(true);
            return true;
        case 6:
            clrscr();
            //top of begin = ringo, top of ringo = end
            this->getTop()->getTop()->interaction(inPlayer);
            this->setInteractBool(true);
            return true;
        default:
            this->setInteractBool(false);
            cout << "Well, maybe you can give it a try on your next trip." << endl;
            return false;
    }
}