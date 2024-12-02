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

    gameBoard = new GameMechs(40,20);
    player = new Player(gameBoard);
    // exitFlag = false;
}

void GetInput(void)
{
   gameBoard->getInput();
}

void RunLogic(void)
{
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    

    int i;
    int j;
    for (i = 0; i < gameBoard->getBoardSizeY(); i++) {
        for (j = 0; j < gameBoard->getBoardSizeX(); j++) {
            if (i == player->getPlayerPos().pos->y && j == player->getPlayerPos().pos->x) {
                MacUILib_printf("%c", player->getPlayerPos().symbol);
            }
            else if (i == 0 || i == gameBoard->getBoardSizeY() - 1 || j == 0 || j == gameBoard->getBoardSizeX() - 1) {
                MacUILib_printf("#");
            } else {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");  // Move to the next row
    }

    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
