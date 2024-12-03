#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


Player* player;
GameMechs* gameBoard;

int main(void)
{

    Initialize();

    while(gameBoard->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    // Initializing Game Mechanics, and Snake Body, and Food object
    gameBoard = new GameMechs();
    player = new Player(gameBoard);
    gameBoard->generateFood(player->getPlayerPos());
}

void GetInput(void)
{
    // Async input logic from PPA3 
    gameBoard->getSnakeInput();
}

void RunLogic(void)
{
    // Updating Player movements and clearing inputs
    player->updatePlayerDir();
    player->movePlayer();
    gameBoard->clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    // Drawing logic mainly copied from PPA3
    int i,j,k;
    objPos foodPos = gameBoard->getFoodPos();

    for (i = 0; i < gameBoard->getBoardSizeY(); i++)
    {
        for (j = 0; j < gameBoard->getBoardSizeX(); j++)
        {   
            if (i == 0 || i == gameBoard->getBoardSizeY() - 1 || j == 0 || j == gameBoard->getBoardSizeX()-1) {
                MacUILib_printf("#"); // Border

            } else if (i == foodPos.pos->y && j == foodPos.pos->x){
                MacUILib_printf("%c", gameBoard->getFoodPos().symbol);

            } else {
                bool spotTaken;

                // Printing Entire Snake Body
                for (k = 0; k < player->getPlayerPos()->getSize(); k++)
                {
                    spotTaken = false;
                    objPos snakePiece = player->getPlayerPos()->getElement(k).getObjPos();
                    if (i == snakePiece.pos->y && j == snakePiece.pos->x) {
                        MacUILib_printf("%c", snakePiece.getSymbol());
                        spotTaken = true;
                        break;
                    } 
                }

                if(!spotTaken){
                    MacUILib_printf(" "); // Empty Spaces
                }

                
            } 
        }
        MacUILib_printf("\n"); 
    }
    MacUILib_printf("Current Score: %d\n", gameBoard->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  


    if(gameBoard->getLoseFlagStatus()){
        MacUILib_printf("You Lost the Game\n");
    } else if (gameBoard->getExitFlagStatus()) {
        MacUILib_printf("You are now leaving the game\n");
    }  

    MacUILib_uninit();
    delete gameBoard;
    delete player;
}
