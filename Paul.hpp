/**************************************************************************
* Class Name: Paul
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: Paul asks the player a trivia question. They have two chances
*    to get the correct answer, if they do, they are awarded a Paul specific item.
 * ************************************************************************/
#ifndef PAUL_HPP
#define PAUL_HPP

#include <iostream>
#include <ctime>

#include "Space.hpp"
#include "ItemBag.hpp"
#include "validateInput.hpp"

class Paul : public Space{
    private:
    public:
        Paul(Space*, Space*, Space*, Space*, std::string);
        ~Paul() {};
        void interaction(Player*);
        bool miniGame(Player*);
        Item getRandItem(int);
};

#endif