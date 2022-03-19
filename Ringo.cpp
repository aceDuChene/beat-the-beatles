
/**************************************************************************
* Class Name: Ringo
* Date: 12-10-2019
* Author: Danielle DuChene
* Description: Your friend Ringo plays a game of tic tac toe. If the player 
*   wins, a Ringo specific item is added to the bag.
 * ************************************************************************/
 #include "Ringo.hpp"

/******************************************************************************
* Ringo constructor: Sets up the Ringo object.
* ****************************************************************************/
Ringo::Ringo(Space *inTop, Space *inRight, Space *inLeft, Space *inBottom, string inName)
    :Space(inTop, inRight, inLeft, inBottom, inName){
    this->setInteractBool(false);
}

/******************************************************************************
* interaction: Creates the interactive element of the space for the user
*    to complete. If done correctly, will add the space's item to their ItemBag.
* ****************************************************************************/
void Ringo::interaction(Player *inPlayer){
    inPlayer->setCurrentSpace(this);
    char answer = ' ';
    if(this->getInteractBool() == true){
        cout << "You have already beat Ringo" << endl;
        cout << "But you do you want to play again? Y/N: ";
        answer = validateChar(false);
        if(answer == 'Y'){
            if(this->miniGame(inPlayer)){
                readFile("./textFiles/ringoGame/winItem.txt");
                inPlayer->getPlayerItems()->addItem(getRandItem(0));
            }
            else{
                readFile("./textFiles/ringoGame/failureItem.txt");
            }
        }
        else{
            cout << "It is weird to see Ringo talking without emojis, isn't it?" << endl << endl;
        }
    }
    else{
        readFile("./textFiles/ringText.txt");
        if(this->miniGame(inPlayer)){
            readFile("./textFiles/ringoGame/win.txt");
            inPlayer->getPlayerItems()->addItem(getRandItem(1));
            this->setInteractBool(true);
        }
        else{
            readFile("./textFiles/ringoGame/failure.txt");
        }
    }
}

 /**************************************************************************
* checkTicTac: This Ringo-specific function takes in the tic tac toe board
*   and a character to check for, and returns whether or not that character
*   has won, or if all the taken spaces count up to 9 will print that 
*   the result is a tie.
 * ************************************************************************/
//some tests are from https://stackoverflow.com/questions/16924380/c-comparing-inner-values-in-a-2d-multidimensional-array
char Ringo::checkTicTac(const char gameBoard[3][3], char testChar){
    for(size_t i = 0; i != 3; i++){
        int win_cnt = 0;
        int k = 2;\

        //horizontal
        for(size_t j = 0; j != 3; j++){
            if(gameBoard[i][j] == testChar){
                win_cnt++;
                if(win_cnt == 3){
                    return testChar;
                }
            }
        }

        //vertical
        win_cnt = 0;
        for(size_t j = 0; j != 3; j++){
            if(gameBoard[j][i] == testChar){
                win_cnt++;
                if(win_cnt == 3){
                    return testChar;
                }
            }
        }

        //top to bottom diag
        win_cnt = 0;
        for(size_t j = 0; j != 3; j ++){
            if(gameBoard[j][j] == testChar){
                win_cnt++;
                if(win_cnt == 3){
                    return testChar;
                }
            }
        }

        //bottom to top diag
        win_cnt = 0;
        for(size_t j = 0; j != 3; j++){
            if(gameBoard[j][k] == testChar){
                win_cnt++;
                if(win_cnt == 3){
                    return testChar;
                }
            }
            k--;
        }
    }

    //count up for a tie
    int cnt = 0;
    for(size_t i = 0; i != 3; i ++){
        for(size_t j = 0; j != 3; j++){
            if(gameBoard[i][j] == 'X' || gameBoard[i][j] == 'O'){
                cnt++;
                if(cnt == 9){
                    cout << "enter if" << endl;
                    return 'T';
                }
            }
        }
    }
    return 'N';
}
 
/******************************************************************************
* miniGame: Ringo's minigame is tic tac toe. He always chooses O because
*    it looks like a ring. Prompts user to unput row and column to play on.
*    Ringo has no AI and just plays on a random tile, in true Ringo fashion.
* ****************************************************************************/
bool Ringo::miniGame(Player *inPlayer){
    int columnInt;
    int rowInt;
    int ringRow;
    int ringColumn;
    char resultChar;

    cout << "You: X" << endl << "Ringo: O" << endl;
    char tictacArray[3][3] = {{'_','_','_'} , {'_','_','_'}, {' ',' ',' '}};
    bool gameDone = false;
    cout << "================Starting Point================" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cout << " " << tictacArray[i][j] << " |";
        }
        for(int j = 2; j < 3; j++){
            cout << " " << tictacArray[i][j];
        }
        cout << endl;
    }
    while(!gameDone){
        cout << "Which row and column do you want to play on?" << endl;
        cout << "Row: ";
        rowInt = validateInteger(1,3);
        cout << "Column: ";
        columnInt = validateInteger(1,3);
        while(tictacArray[rowInt - 1][columnInt - 1] == 'X' || tictacArray[rowInt - 1][columnInt - 1] == 'O'){
            cout << "That move has already been played. Try again." << endl;
            cout << "Row: ";
            cin >> rowInt;
            cout << "Column: ";
            cin >> columnInt;           
        }
        tictacArray[rowInt - 1][columnInt - 1] = 'X';

        cout << "==================Your Turn==================" << endl;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                cout << " " << tictacArray[i][j] << " |";
            }
            for(int j = 2; j < 3; j++){
                cout << " " << tictacArray[i][j];
            }
            cout << endl;
        }

        resultChar = checkTicTac(tictacArray, 'X');
        if(resultChar == 'X'){
            if( !(this->getInteractBool()) ){
                cout << "Congrats! You beat the drummer of The Beatles!" << endl;
                this->setInteractBool(true);
            }
            else{
                cout << "Well, you beat Ringo again. Does it make you feel good?" << endl;
            }
            gameDone = true;
            return true;
        }
        else if(resultChar == 'T'){
            cout << "You tied Ringo..." << endl;
            gameDone = true;
            return false;
        }
       
        do{
            ringRow = rand()%3;
            ringColumn = rand()%3;
        }while(tictacArray[ringRow][ringColumn] == 'X' || tictacArray[ringRow][ringColumn] == 'O');
        cout << "=================Ringo's Turn=================" << endl;
        tictacArray[ringRow][ringColumn] = 'O';
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                cout << " " << tictacArray[i][j] << " |";
            }
            for(int j = 2; j < 3; j++){
                cout << " " << tictacArray[i][j];
            }
            cout << endl;
        }

        resultChar = checkTicTac(tictacArray, 'O');
        if(resultChar == 'O'){
            cout << "Sorry, but Ringo beat you." << endl;
            gameDone = true;
            return false;
        }
        else if(resultChar == 'T'){
            cout << "You're on the same par as Ringo Starr..." << endl;
            return false;
        }
    }
    return false;
}

/******************************************************************************
* getRandItem: Sets up three possible items for the user to obtain after
*    winning a round. The first item will be the necessary item to complete the 
*    game. After that, a random item will be rewarded. To be counted as the first
*    item, 1 must be passed as the parameter.
* ****************************************************************************/
Item Ringo::getRandItem(int inNum){
    int num = rand()%3 + 1;
    if(inNum == 1){
        num = 1;
    }

    Item drum("Ludwig \"Super Classic\" Drum Kit", "This was one of Ringo's favorite drum kits to use.");
    Item foot("\"Elaphant Foot\"", "One of Ringo's famed pieces of MS paint art.\nDepicts the foot of an \"Elaphant.\"");
    Item ring("Red Ring", "Be careful while wearing this.\nWe wouldn't want you to be kidnapped and sacrificed.");

    switch(num){
        case 1:
            return drum;
        case 2:
            return foot;
        default:
            return ring;
    }
}