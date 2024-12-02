#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // Setting starting position to be in middle of any given sized board
    playerPos.setObjPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '*');
    // more actions to be included
}


Player::~Player()
{
    // delete any heap members here
    delete mainGameMechsRef;
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{


}

void Player::movePlayer()
{
    
}

// More methods to be added