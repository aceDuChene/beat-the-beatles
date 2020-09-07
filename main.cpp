/**************************************************************************
 * Program Name:
 * Date:
 * Author: Danielle DuChene
 * Description:
 * ************************************************************************/
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Item.hpp"
#include "ItemBag.hpp"
#include "Space.hpp"
#include "Ringo.hpp"
#include "John.hpp"
#include "Paul.hpp"
#include "George.hpp"
#include "End.hpp"
#include "Begin.hpp"
#include "Player.hpp"

int main()

{
    srand(time(0));
    Player *myPlayer = new Player;
    Space *myRingo = new Ringo(nullptr, nullptr, nullptr, nullptr, "the Ringo");
    Space *myJohn = new John(nullptr, nullptr, nullptr, nullptr, "the John");
    Space *myPaul = new Paul(nullptr, nullptr, nullptr, nullptr, "the Paul");
    Space *myGeorge = new George(nullptr, nullptr, nullptr, nullptr, "the George");
    Space *myEnd = new End(nullptr, nullptr, nullptr, nullptr, "the end");
    Space *myBegin = new Begin(nullptr, nullptr, nullptr, nullptr, "the beginning");

    //pointer order: top, right, left, bottom
    myBegin->setSpacePointers(myRingo, myPaul, myJohn, myGeorge);
    myRingo->setSpacePointers(myEnd, nullptr, nullptr, myBegin);
    myJohn->setSpacePointers(nullptr, myBegin, myEnd, nullptr);
    myPaul->setSpacePointers(nullptr, myEnd, myBegin, nullptr);
    myGeorge->setSpacePointers(myBegin, nullptr, nullptr, myEnd);
    myEnd->setSpacePointers(myGeorge, myJohn, myPaul, myRingo);

    myBegin->interaction(myPlayer);
    if(myBegin->getInteractBool()){
        myBegin->interaction(myPlayer);
    }

    delete myBegin;
    delete myEnd;
    delete myGeorge;
    delete myPaul;
    delete myJohn;
    delete myRingo;
    delete myPlayer;

    return 0;

}