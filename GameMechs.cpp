#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    input = 0;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15; 

    exitFlag = false;
    loseFlag = false;

    food = objPos(-1,-1,'\0'); // At first the object will be created but will not be visible
}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{

    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}


// PPA 3 logic, sets the input
void GameMechs::getSnakeInput()
{
    if(MacUILib_hasChar()){
        setInput(MacUILib_getChar());
    }

}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = '\0';
}

// More methods should be added here

// Variation of PPA3 random generation
void GameMechs::generateFood(objPosArrayList* blockOff) {

    // Reset the food object to unvisible location before it spawns on the board

    int rx;
    int ry;
    srand(time(NULL));
    

    for(int i = 0; i < blockOff->getSize(); i++){
        while(true) {
            rx = (rand() % (boardSizeX-2)) + 1;
            ry = (rand() % (boardSizeY-2)) + 1;

            if(rx != blockOff->getElement(i).pos->x && ry != blockOff->getElement(i).pos->y) {
                food.setObjPos(rx, ry, 'X');
                break;
            }
        }
    }

}

objPos GameMechs::getFoodPos() {
    return food;
}