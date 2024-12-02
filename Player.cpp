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
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPos;
}

void Player::updatePlayerDir()
{
    // Copied from PPA 3 Logic
    char input = mainGameMechsRef->getInput();
    switch(input) { 
        case 'w':
            if(myDir != DOWN) 
                myDir = UP;
                break;
        case 'a':
            if(myDir != RIGHT) 
                myDir = LEFT;
                break;
        case 's':
            if(myDir != UP) 
                myDir = DOWN;
                break;
        case 'd':
            if(myDir != LEFT) 
                myDir = RIGHT;
                break;

        // Exit Key
        case ' ':
            mainGameMechsRef->setExitTrue();
            break;

        // Score increment Debug key
        case 'i':
            mainGameMechsRef->incrementScore();
            break;

        // Lose flag debug key
        case 'l':
            mainGameMechsRef->setLoseFlag();
            break;
        
        // Generate food debug key
        case 'g':
            mainGameMechsRef->generateFood(playerPos);
            break;
            
        default:
            break;
    }  

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int px = playerPos.pos->x;
    int py = playerPos.pos->y;
    int boardLimitY = mainGameMechsRef->getBoardSizeY()-2;
    int boardLimitX = mainGameMechsRef->getBoardSizeX()-2;

    // Logic for movement copied directly from PPA3
    switch(myDir)
    {                      
        case DOWN: 
            py = (py % boardLimitY)+1;
            break;
            
        case UP:
            py--;
            if(py < 1) {py = boardLimitY;}
            break;
            
        case LEFT:
            px--;
            if(px < 1) {px = boardLimitX;}
            break;

        case RIGHT:
            px = (px % boardLimitX)+1;
            break;

        default:
            break;
    }

    playerPos.setObjPos(px, py, playerPos.symbol);
}

// More methods to be added