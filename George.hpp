/**************************************************************************
* Class Name: George
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: George will have the player choose ingredients to make a 
*    sandwich. If they make an egg sandwich, the player will add an item
*    to their item bag.
 * ************************************************************************/
#ifndef GEORGE_HPP
#define GEORGE_HPP

#include <iostream>

#include "Space.hpp"
#include "ItemBag.hpp"
#include "validateInput.hpp"

class George : public Space{
    private:
    public:
        George(Space*, Space*, Space*, Space*, std::string);
        ~George() {};
        void interaction(Player*);
        bool miniGame(Player*);
        void printArray(string*, int);
        Item getRandItem(int);
};

#endif