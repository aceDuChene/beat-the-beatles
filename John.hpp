/**************************************************************************
* Class Name: John
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: John makes you play hangman. If player wins, an item 
*    specific to John will be added to their bag.
 * ************************************************************************/
#ifndef JOHN_HPP
#define JOHN_HPP

#include "Space.hpp"
#include "ItemBag.hpp"
#include "validateInput.hpp"

class John : public Space{
    private:
    public:
        John(Space*, Space*, Space*, Space*, std::string);
        ~John() {};
        void interaction(Player*);
        bool miniGame(Player*);
        void printArray(char*, int);
        bool checkSolved(char*, int);
        Item getRandItem(int inNum);
};

#endif