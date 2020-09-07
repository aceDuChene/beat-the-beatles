/**************************************************************************
* Class Name: Player
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: This will keep track of the player's place in the game, the
*    total number of turns they have taken, and their bag of items.
 * ************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ItemBag.hpp"
#include "Space.hpp"
class Space;

class Player{
    private:
        ItemBag playerItems;
        Space *currentSpace;
        int totalSteps;
    public:
        Player();
        ~Player() {};
        ItemBag* getPlayerItems();
        void setCurrentSpace(Space*);
        void addStep();
        int getStep();
};

#endif