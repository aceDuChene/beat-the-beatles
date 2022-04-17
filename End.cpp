/**************************************************************************
* Class Name: End
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: This class sets up the end of the game. It can test whether
*   or not the player has collected the correct items to be able to progress.
* *************************************************************************/
#include "End.hpp"

/******************************************************************************
* End constructor: Sets up the End object.
* ****************************************************************************/
End::End(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom, string inName)
    :Space(inTop, inRight, inLeft, inBottom, inName){
    this->setInteractBool(false);
}
 
/******************************************************************************
* interaction: If user has the correct items, will ask if they want to finish
*    the game. If not, will not progress to the end.
* ****************************************************************************/
void End::interaction(Player *inPlayer){
    inPlayer->setCurrentSpace(this);
    //player has all the instruments
    bool endBool = testEnd(inPlayer);
    if(endBool && inPlayer->getStep() < 10){
        cout << "Would you like to enter the tour bus? Or go back to the lighthouse?" << endl;
        cout << "Y = move on     N = turn back" << endl;
        char answer = validateChar(false);
        if(answer == 'Y'){
           this->miniGame(inPlayer);
           this->setInteractBool(true);
        }
    }
    else if(endBool && inPlayer->getStep() >= 10){
        this->miniGame(inPlayer);
        this->setInteractBool(true);
    }
    //player does not have all items needed
    else{
        cout << "You're still missing some instruments... Go back and chat with the lads." << endl;
    }
}
 
/******************************************************************************
* testEnd: Goes through the user's item bag to see if they have the required
*    items to complete the game.
* ****************************************************************************/
bool End::testEnd(Player *inPlayer){
    bool paul = false;
    bool ringo = false;
    bool george = false;
    bool john = false;
    Item *temp = inPlayer->getPlayerItems()->getItemNum(1);
    for(int i = 1; i < 10; i++){
        if(temp != nullptr){
            //compares the items in item bag to required items
            //from http://www.cplusplus.com/reference/string/string/compare/
            if(temp->getItemName().compare("Ludwig \"Super Classic\" Drum Kit") == 0){
                ringo = true;
            } 
            if(temp->getItemName().compare("\"Rocky\" the Fender Stratocaster Guitar") == 0){
                george = true;
            }
            if(temp->getItemName().compare("Epiphone Casino Guitar") == 0){
                john = true;
            } 
            if(temp->getItemName().compare("Hofner Bass") == 0){
                paul = true;
            }
            temp = temp->getNext();
        }
    }
    if(paul && ringo && george && john && inPlayer->getStep() < 10){
        cout << "You have all the instruments and are ready to take the trip." << endl;
        return true;
    }
    else if(paul && ringo && george && john && inPlayer->getStep() >= 10){
        //go onto minigame
        return true;
    }
    else{
        cout << "You still have to beat some Beatles!" << endl;
        return false;
    }
}

/**************************************************************************
* miniGame: This is not really a minigame. It lists the ending credits of
*   the game.
 * ************************************************************************/
bool End::miniGame(Player *inPlayer){
    readFile("./textFiles/win.txt");
    return true;
}