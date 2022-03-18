/**************************************************************************
* Class Name: George
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: George will have the player choose ingredients to make a 
*    sandwich. If they make an egg sandwich, the player will add an item
*    to their item bag.
 * ************************************************************************/
#include "George.hpp"

/******************************************************************************
* George constructor: Sets up the George object.
* ****************************************************************************/
George::George(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom, string inName)
    :Space(inTop, inRight, inLeft, inBottom, inName){
    this->setInteractBool(false);
}
 
/******************************************************************************
* interaction: Creates the interactive element of the space for the user
*    to complete. If done correctly, will add the space's item to their ItemBag.
* ****************************************************************************/
void George::interaction(Player *inPlayer){
    inPlayer->setCurrentSpace(this);
    char answer = ' ';
    //if they have already gotten the guitar once
    if(this->getInteractBool() == true){
        cout << "You have already made George an egg sandwich," << endl;
        cout << "but you can do it again? Y/N: ";
        answer = validateChar(false);
        if(answer == 'Y'){
            if(this->miniGame(inPlayer)){
                cout << "George hands you a random item. Check your inventory to see." << endl << endl;
                inPlayer->getPlayerItems()->addItem(getRandItem(0));
            }
            else{
                cout << "George throws you out of the room." << endl << endl;
            }
        }
        else{
            cout << "Well, that's fine. You can do something else." << endl << endl;
        }
    }

    //if they have not yet gotten the guitar, George will act like he's never seen them
    //before as he tries to erase the grotty sammy from his memory
    else{
        readFile("./textFiles/geoText.txt");
        if(this->miniGame(inPlayer)){
            cout << "George gives you his guitar. Check your inventory to see it." << endl << endl;
            inPlayer->getPlayerItems()->addItem(getRandItem(1));
            this->setInteractBool(true);
        }
        else{
            cout << "George is too repulsed by the sandwich you made to even" << endl;
            cout << "think about handing over the guitar so you can do your job." << endl;
            cout << "He tries his best to forget this incident ever happened." << endl << endl;
        }
    }
}

/*****************************************************************************
* miniGame: George's minigame has the player make him a sandwich. The main
*    deciding factor is whether or not the player chooses to make him an egg
*    sandwich.
******************************************************************************/
bool George::miniGame(Player *inPlayer){
    int choice;
    int numCount = 0;
    string complete[4] = {" ", " ", " "};

    string bread[3] = {"French", "Sourdough", "Pumpernickel"};
    string *breadPtr = bread;
    int breadNums[3] = {3, 3, 2};

    string filling[3] = {"Egg Salad", "Ham", "Cheese"};
    string *fillingPtr = filling;
    int fillNums[3] = {10, -30, 2};

    string sauce[3] = {"Mustard", "Relish", "Mayonnaise"};
    string *saucePtr = sauce;
    int sauceNums[3] = {1, 1, 2};

    string veggies[3] = {"Onion", "Lettuce", "Tomato"};
    string *veggiePtr = veggies;
    int vegNums[3] = {3, 2, 1};

    cout << "Can you make George the most fab sandwich?" << endl;

    //print array and add up the corresponding points
    cout << "Choose the bread..." << endl;
    printArray(breadPtr, 3);
    choice = validateInteger(1,3);
    complete[0] = bread[choice - 1];
    numCount = numCount + breadNums[choice - 1];
    cout << endl;
    
    cout << "Choose the filling..." << endl;
    printArray(fillingPtr, 3);
    choice = validateInteger(1,3);
    complete[1] = filling[choice - 1];
    numCount = numCount + fillNums[choice - 1];
    cout << endl;

    cout << "Choose the condiment..." << endl;
    printArray(saucePtr, 3);
    choice = validateInteger(1,3);
    complete[2] = sauce[choice - 1];
    numCount = numCount + sauceNums[choice - 1];
    cout << endl;

    cout << "Choose the veggies..." << endl;
    printArray(veggiePtr, 3);
    choice = validateInteger(1,3);
    complete[3] = veggies[choice - 1];
    numCount = numCount + vegNums[choice - 1];
    cout << endl;

    cout << "Your choices:" << endl;
    printArray(complete, 4);
    cout << endl;

    //player picked Ham
    if(numCount < 0){
        cout << "Don't you know George is a vegetarian?" << endl;
        cout << "\"This is completely grotty. I won't let this inside my beautiful room.\"" << endl;
        cout << "Try again." << endl;
        return false;
    }

    //player did not pick ham or egg
    else if(numCount >= 0 && numCount <=11){
        cout << "George eats your sandwich..." << endl;
        cout << "\"Well, it could be better.\"" << endl;
        cout << "You didn't make the most delicious sandwich." << endl;
        cout << "Try again." << endl;
        return false;
    }

    //player picked egg
    else{
        cout << "George takes an enormous bite of your sandwich..." << endl;
        cout << "\"Groovy! How did you know my favorite is egg sandwich?\"" << endl;
        cout << "You made George's favorite and most delicious sandwich!" << endl;
        return true;
    }
}

/******************************************************************************
* printArray: this is used to print out the possible options for the sandwich.
*******************************************************************************/
void George::printArray(string *inArray, int size){
    for(int i = 0; i < size; i++){
        cout << i + 1 << ". " << inArray[i] << endl;
    }
}

/******************************************************************************
* getRandItem: Sets up three possible items for the user to obtain after
*    winning a round. The first item will be the necessary item to complete the 
*    game. After that, a random item will be rewarded. To be counted as the first
*    item, 1 must be passed as the parameter.
* ****************************************************************************/
Item George::getRandItem(int inNum){
    int num = rand()%3 + 1;
    if(inNum == 1){
        num = 1;
    }

    Item guitar("\"Rocky\" the Fender Stratocaster Guitar", "Orininally a boring steel blue color, George painted this with\na psychadelic pattern using neon paints.");
    Item sitar("Sitar", "George became interested in this instrument after filming a scene from \"Help!\"\n");
    Item sand("Half-Eaten Egg Sandwich", "Did you take this from George? He wasn't even done eating it!");

    switch(num){
        case 1:
            return guitar;
        case 2:
            return sitar;
        default:
            return sand;
    }
}