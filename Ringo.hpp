
/**************************************************************************
* Class Name: Ringo
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: Your friend Ringo plays a game of tic tac toe. If the player 
*   wins, a Ringo specific item is added to the bag.
 * ************************************************************************/
#ifndef RINGO_HPP
#define RINGO_HPP

#include "Space.hpp"
#include "validateInput.hpp"
#include "ItemBag.hpp"

class Ringo : public Space{
    private:
    public:
        Ringo(Space*, Space*, Space*, Space*, std::string);
        ~Ringo() {};
        void interaction(Player*);
        char checkTicTac(const char gameBoard[3][3], char testChar);
        bool miniGame(Player*);
        Item getRandItem(int);
};

 #endif