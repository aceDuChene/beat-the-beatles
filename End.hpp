/**************************************************************************
* Class Name: End
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: This class sets up the end of the game. It can test whether
*   or not the player has collected the correct items to be able to progress.
* *************************************************************************/
#ifndef END_HPP
#define END_HPP

#include "Space.hpp"
#include "Item.hpp"

class End : public Space{
    private:
    public:
        End(Space*, Space*, Space*, Space*, std::string);
        ~End() {};
        void interaction(Player*);
        bool testEnd(Player*);
        bool miniGame(Player*);
};

#endif