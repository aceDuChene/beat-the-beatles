/**************************************************************************
 * Class Name: Space
 * Date:
 * Author: Danielle DuChene
 * Description: The space class holds four pointers for top, right, bottom, 
 *    and left. It links spaces through pointers.
 * ************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include <ctime>

#include "Item.hpp"
#include "ItemBag.hpp"
#include "validateInput.hpp"
#include "Player.hpp"
class Player;

using std::cout;
using std::endl;

class Space{
    private:
        Space *top;
        Space *right;
        Space *left;
        Space *bottom;
        string name;
        bool interactBool;
    public:
        Space(Space*, Space*, Space*, Space*, string);
        virtual ~Space() {}; 
        virtual string getName();
        virtual void interaction(Player*)=0; 
        bool getInteractBool() {return interactBool;};
        void setInteractBool(bool inBool) {interactBool = inBool;};
        void setSpacePointers(Space*, Space*, Space*, Space*);
        virtual bool testEnd(Player*) {return false;};
        virtual bool miniGame(Player*)=0;
        Space* getTop() {return top;};
        Space* getRight() {return right;};
        Space* getLeft() {return left;};
        Space* getBottom() {return bottom;};
};


#endif