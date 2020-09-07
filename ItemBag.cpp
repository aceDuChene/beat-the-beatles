/**************************************************************************
 * Class Name: ItemBag
 * Date:
 * Author: Danielle DuChene
 * Description: This class will be a linked list of different items to be
 *    used in the game. The player object has an item bag that the items
 *    will be added into.
 * ************************************************************************/
#include "ItemBag.hpp"

/****************************************************************
 * ItemBag constructor: Sets the front and back Item pointers to
 *    nullptr. Max size is set to Number Nine.
 * **************************************************************/
ItemBag::ItemBag(){
    front = nullptr;
    tail = nullptr;
    maxSize = 9;
    currentSize = 0;
}

/****************************************************************
 * ItemBag destructor: Destroys the ItemBag object.
 * **************************************************************/
ItemBag::~ItemBag(){
    while(front != nullptr){
        Item *futureGarbage = front;
        front = front->getNext();
        delete futureGarbage;
    }
}

/****************************************************************
 * addItem: Adds an Item to the end/back of the item bag.
 * **************************************************************/
void ItemBag::addItem(Item *inItemType){
    if(currentSize >= maxSize){
        cout << "You need to get rid of one of your items! Pick which one to toss." << endl;
        this->forwardPrint(true);
        //next option after print is to keep items
        cout << currentSize + 1 << ". Keep current items, toss new item" << endl;
        int numDel = validateInteger(1, currentSize + 1);
        if(numDel == currentSize + 1){
            return;
        }
        else{
            removeItem(numDel);
        }
    }

    //when bag is empty
    if(front == nullptr){
        Item *temp = inItemType;
        front = temp;
        tail = temp;
        if(currentSize < maxSize){
            currentSize++;
        }
    }

    else{
        Item *temp = inItemType;
        temp->setPrev(tail);
        tail->setNext(temp);
        tail = temp;
        if(currentSize < maxSize){
            currentSize++;
        }
    }
}

/****************************************************************
 * addItem: Adds an Item to the end/back of the item bag. This is
 *    an overloaded function that takes in an item instead of an
 *    item pointer.
 * **************************************************************/
void ItemBag::addItem(Item inItemType){
    if(currentSize >= maxSize){
        cout << "You need to get rid of one of your items! Pick which one to toss." << endl;
        this->forwardPrint(true);
        cout << currentSize + 1 << ". Keep current items, toss new item" << endl;
        int numDel = validateInteger(1, currentSize + 1);
        if(numDel == currentSize + 1){
            return;
        }
        else{
            removeItem(numDel);
        }
    }
    if(front == nullptr){
        Item *temp = new Item(inItemType.getItemName(), inItemType.getDesc());
        front = temp;
        tail = temp;
        front->setPrev(nullptr);
        front->setNext(nullptr);
        if(currentSize < maxSize){
            currentSize++;
        }
    }

    else{
        Item *temp = new Item(inItemType.getItemName(), inItemType.getDesc());
        temp->setPrev(tail);
        tail->setNext(temp);
        tail = temp;
        if(currentSize < maxSize){
            currentSize++;
        }
    }
}

/**************************************************************************
 * removeItem: Takes in the number that the user wants to delete. Goes 
 *   through the bag until it is reached and is deleted from there and
 *   pointers are appropriately placed.
 * ************************************************************************/
void ItemBag::removeItem(int itemNum){
    if(this->isEmpty()){
        //do not delete anything
        return;
    }

    Item *futureGarbage = front;
    //goes through the items until it finds the one to delete
    for(int i = 1; i < itemNum; i++){
        futureGarbage = futureGarbage->getNext();
    }

    //if it is the first item
    if(futureGarbage == front){
        if(front == nullptr){
            //do not delete anything
            return;
        }  
        
        front = front->getNext();
        delete futureGarbage;
        currentSize--;
        return;
    }

    if(futureGarbage == tail){
        if(tail == nullptr){
            //do nothing
            return;
        }

        tail = tail->getPrev();
        delete futureGarbage;
        currentSize--;
        return;
    }

    //set the prev pointer's next to the one in front of garbage
    futureGarbage->getPrev()->setNext(futureGarbage->getNext());
    delete futureGarbage;
    currentSize--;
    return;
}

/****************************************************************
 * forwardPrint: Prints the contents of the Item bag to the screen.
 * **************************************************************/
void ItemBag::forwardPrint(bool remove){
    Item *temp = front;
    int i = 1;

    if(this->currentSize == 0){
        cout << "You have nothing to check!" << endl;
    }
    
    else{
        if(temp->getNext() == nullptr){
            cout << i << ". " << temp->getItemName() << endl;
        }
        else{
            while(temp != nullptr){
                std::cout << i << ". ";
                cout << temp->getItemName() << endl;
                temp = temp->getNext();
                i++;
            }
        }
        
        //do not ask about descriptions if print is being called to delete
        if(remove){
        }

        //check descriptions from beginning menu
        else{

            int checkNum;
            cout << endl << "A. Check item description"<< endl;
            cout << "B. Delete an item" << endl;
            cout << "C. Back to Menu" << endl;
            char answer = validateABC();
            switch(answer){
                case 'A':
                    if(i == 1){
                        this->getItemNum(1)->printDesc();
                        cout << endl;
                    }
                    else{
                        checkNum = validateInteger(1, i - 1);
                        this->getItemNum(checkNum)->printDesc();
                        cout << endl;
                    }
                    break;
                case 'B':
                    if(this->getCurrentSize() == 0){
                        cout << "There are no items to delete!" << endl;
                    }
                    else if(this->getCurrentSize() == 1){
                        this->removeItem(1);
                    }
                    else{
                        checkNum = validateInteger(1,i - 1);
                        this->removeItem(checkNum);
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

/****************************************************************
 * isEmpty: tests if the list is empty. Returns true if it is empty.
 * **************************************************************/
bool ItemBag::isEmpty(){
    if(front == nullptr){
        return true;
    }
    else{
        return false;
    }
}

/****************************************************************
 * getItemNum: Takes in an integer referring to the placement of 
 *   the Item pointer to be returned.
 * **************************************************************/
Item* ItemBag::getItemNum(int inNum){
    Item *temp = front;
    for(int i = 1; i < inNum; i++){
        if(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
    }
    return temp;
}

/****************************************************************
 * getCurrentSize: Returns the current size of the itemBag.
 * **************************************************************/
 int ItemBag::getCurrentSize(){
     return currentSize;
 }
