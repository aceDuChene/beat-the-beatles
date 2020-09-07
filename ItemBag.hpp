/**************************************************************************
 * Class Name: ItemBag
 * Date:
 * Author: Danielle DuChene
 * Description: This class will be a linked list of different items to be
 *    used in the game. The player object has an item bag that the items
 *    will be added into.
 * ************************************************************************/
#ifndef ITEMBAG_HPP
#define ITEMBAG_HPP

#include <string>
#include <iostream>

#include "Item.hpp"
#include "validateInput.hpp"

using std::string;
using std::cout;
using std::endl;

class ItemBag{
    private:
        Item *front;
        Item *tail;
        int maxSize;
        int currentSize;
    public:
        ItemBag();
        ~ItemBag();
        void addItem(Item *itemType);
        void addItem(Item);
        void removeItem(int itemNum);
        void forwardPrint(bool remove); 
        bool isEmpty();
        Item* getItemNum(int);
        int getCurrentSize();
};

#endif