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