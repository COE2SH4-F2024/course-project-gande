#include "Player.h"
#include "MacUILib.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList = new objPosArrayList();

    // more actions to be included
    // Initial Snake head inserted to the head of the list
    objPos snakeHead = objPos();
    snakeHead.setObjPos((mainGameMechsRef->getBoardSizeX())/2, (mainGameMechsRef->getBoardSizeY())/2, '*');
    playerPosList->insertHead(snakeHead);

    // Testing multiple lengths;
    // snakeHead = objPos((mainGameMechsRef->getBoardSizeX())/2 - 2, (mainGameMechsRef->getBoardSizeY())/2, '*');
    // playerPosList->insertTail(snakeHead);
    // snakeHead = objPos((mainGameMechsRef->getBoardSizeX())/2 - 1, (mainGameMechsRef->getBoardSizeY())/2, '*');
    // playerPosList->insertTail(snakeHead);
    // snakeHead = objPos((mainGameMechsRef->getBoardSizeX())/2 + 1, (mainGameMechsRef->getBoardSizeY())/2, '*');
    // playerPosList->insertTail(snakeHead);
    // snakeHead = objPos((mainGameMechsRef->getBoardSizeX())/2 + 3, (mainGameMechsRef->getBoardSizeY())/2, '*');
    // playerPosList->insertTail(snakeHead);
}


Player::~Player()
{
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    return playerPosList;
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
        // case 'g':
        //     mainGameMechsRef->generateFood(player->getHeadElement());
        //     break;

        default:
            break;
    }  

}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int boardLimitY = mainGameMechsRef->getBoardSizeY()-2;
    int boardLimitX = mainGameMechsRef->getBoardSizeX()-2;

    // The current snake head and its coordinates
    objPos currentHead = playerPosList->getHeadElement();
    objPos updatedHead;
    int headx = currentHead.getObjPos().pos->x;
    int heady = currentHead.getObjPos().pos->y;

    // Logic for movement copied directly from PPA3
    switch(myDir)
    {                      
        case DOWN: 
            heady = (heady % boardLimitY)+1;
            break;
            
        case UP:
            heady--;
            if(heady < 1) {heady = boardLimitY;}
            break;
            
        case LEFT:
            headx--;
            if(headx < 1) {headx = boardLimitX;}
            break;

        case RIGHT:
            headx = (headx % boardLimitX)+1;
            break;

        default:
            break;
    }

    updatedHead.setObjPos(headx, heady, '*');


    if (!checkSelfCollision(updatedHead)) {
        playerPosList->insertHead(updatedHead);
        if(headx == mainGameMechsRef->getFoodPos().pos->x && heady == mainGameMechsRef->getFoodPos().pos->y) {
            mainGameMechsRef->generateFood(playerPosList);
            mainGameMechsRef->updateScore();
        } else {
            playerPosList->removeTail();
        }
    }
    

    
}

bool Player::checkSelfCollision(objPos newHead){
    for(int i=1; i<playerPosList->getSize(); i++){
        if(newHead.pos->x == playerPosList->getElement(i).pos->x && newHead.pos->y == playerPosList->getElement(i).pos->y) {
            mainGameMechsRef->setExitTrue();
            mainGameMechsRef->setLoseFlag();
            return true;   
        }
    }
    return false;
}

// More methods to be added