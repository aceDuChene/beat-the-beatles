/**************************************************************************
 * Class Name: Item
 * Date: 12-10-2019
 * Author: Danielle DuChene
 * Description: This class will be for items that will be created for each
 *    member of the band.
 * ************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Item{
    private:
        Item *next;
        Item *prev;
        string itemName;
        string description;
    public:
        Item(string inName);
        Item(string inName, string inDesc);
        ~Item();
        string getItemName();
        Item* getPrev();
        void setPrev(Item* inItem);
        Item* getNext();
        void setNext(Item* inItem);
        string getDesc();
        void printDesc();
};

#endif