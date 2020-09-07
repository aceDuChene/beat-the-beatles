/**************************************************************************
* Class Name: Player
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: This will keep track of the player's place in the game, the
*    total number of turns they have taken, and their bag of items.
 * ************************************************************************/
#include "Player.hpp"


/******************************************************************************
 * Player constructor: sets up the Player object, starting space is nullptr and
 *    totalSteps is 0.
 * ****************************************************************************/
Player::Player(){
    currentSpace = nullptr;
    totalSteps = 0;
}

/******************************************************************************
 * getPlayerItems: Returns the itemBag associated with the player as a pointer
 *    so it can be edited.
 * ****************************************************************************/
ItemBag* Player::getPlayerItems(){
    return &playerItems;
}

/******************************************************************************
 * setCurrentSpace: Takes in a space pointer and sets the currentSpace of the
 *    player to that Space.
 * ****************************************************************************/
void Player::setCurrentSpace(Space *inSpace){
    currentSpace = inSpace;
}

/******************************************************************************
 * addStep: adds 1 to the step counter of the player.
 * ****************************************************************************/
void Player::addStep(){
    totalSteps++;
}

/******************************************************************************
 * getSteps: Returns the number of steps taken so far by the player.
 * ****************************************************************************/
int Player::getStep(){
    return totalSteps;
}