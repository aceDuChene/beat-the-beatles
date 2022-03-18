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
        readFile("./textFiles/title.txt");
        cout << "You might have to adjust your window size." << endl;
        cout << "Would you like to play \"Beat The Beatles\"? Y/N: ";
        char answer = validateChar(true);

        if(answer == 'Y'){
            readFile("./textFiles/begin.txt");
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
                    readFile("./textFiles/fail.txt");
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
        readFile("./textFiles/menu.txt");
}

/****************************************************************
 * chooseMenu: Takes in an Player to use for the various
 *    interactions of each menu choice. Leads the user to the
 *    respective choice provided.
 * **************************************************************/
bool Begin::chooseMenu(Player *inPlayer){
    switch(validateInteger(1,7)){
        case 1:
            this->getTop()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 2:
            this->getRight()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 3:
            this->getBottom()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 4:
            this->getLeft()->interaction(inPlayer);
            this->setInteractBool(true);
            inPlayer->addStep();
            return true;
        case 5:
            inPlayer->getPlayerItems()->forwardPrint(false);
            this->setInteractBool(true);
            return true;
        case 6:
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