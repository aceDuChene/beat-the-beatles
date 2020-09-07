/**************************************************************************
 * Class Name: Item
 * Date: 12-10-2019
 * Author: Danielle DuChene
 * Description: This class will be for items that will be created for each
 *    member of the band.
 * ************************************************************************/
#include "Item.hpp"

/**************************************************************************
 * Item constructor: Constructor for an Item object. Initializes next and 
 *    prev pointers to nullptr.
 * ************************************************************************/
Item::Item(string inName, string inDesc){
    next = nullptr;
    prev = nullptr;
    itemName = inName;
    description = inDesc;
}

/**************************************************************************
 * Item destructor: Destructor for an Item object.
 * ************************************************************************/
Item::~Item(){}

/**************************************************************************
 * getItemName: Returns the name of the object as a string.
 * ************************************************************************/
string Item::getItemName(){
    return itemName;
}

/**************************************************************************
 * getPrev:: Returns prev pointer.
 * ************************************************************************/
Item* Item::getPrev(){
    return prev;
}

/**************************************************************************
 * setPrev: Sets prev pointer of the Item.
 * ************************************************************************/
void Item::setPrev(Item *inItem){
    prev = inItem;
}

/**************************************************************************
 * getNext: Returns the Item pointer to next.
 * ************************************************************************/
Item* Item::getNext(){
    return next;
}

/**************************************************************************
 * setNext: Sets the next pointer of the Item object.
 * ************************************************************************/
void Item::setNext(Item *inItem){
    next = inItem;
}

/**************************************************************************
 * printDesc: Prints the descripton of the object.
 * ************************************************************************/
 string Item::getDesc(){
     return description;
 }

 void Item::printDesc(){
    cout << this->itemName << endl;
    cout << this->description << endl;
 }