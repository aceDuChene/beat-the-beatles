/**************************************************************************
* Class Name: Begin
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: This class is derived from the Space class. This sets up the
*    beginning of the game, asking the user if they want to play. The game
*    will keep returning to this class object to print out the game menus.
 * ************************************************************************/
#ifndef BEGIN_HPP
#define BEGIN_HPP

#include "Space.hpp"

class Begin : public Space{
    private:
    public:
        Begin(Space*, Space*, Space*, Space*, std::string);
        ~Begin() {};
        void interaction(Player*);
        bool miniGame(Player*) {return false;};
        void printMenu();
        bool chooseMenu(Player*);
};

#endif